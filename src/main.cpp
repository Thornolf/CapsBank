#include	<iostream>
#include	<fstream>
#include	<map>

#include	"date.hpp"
#include	"account.hpp"
#include	"children.hpp"
#include	"bank.hpp"
#include	"exceptionHandler.hpp"

bool            isDateValid(std::string predicat) {
  std::vector<std::string>	data;
  std::string			delimiter = "-";
  size_t			pos = 0;
  std::string			token;
  int				year = 0;
  int				month = 0;
  int				day = 0;
  int				count = 0;
  
  while ((pos = predicat.find(delimiter)) != std::string::npos) {
    token = predicat.substr(0, pos);

    if (predicat.find_first_not_of("0123456789") == std::string::npos) {
	return (false);
    }
    data.push_back(token);
    predicat.erase(0, pos + delimiter.length());
    count++;
  }
    data.push_back(predicat);
    year = std::stoi(data.at(0));
    month = std::stoi(data.at(1));
    day = std::stoi(data.at(2));
    (void)year;
    if ((month >= 0 && month <= 12) && (day >= 0 && day <= 31) && count == 2)
      return (true);
    return (false);
}

void show(std::string s, Bank *b) {
  (void)s;
  bool		valid = false;
  std::string	cmd;
  
  try {
    std::cout << "Which account do you want to see ? (Give an ID or type all to see all accounts)\n> ";
    std::getline(std::cin, cmd);
    if (cmd == "all")
      b->showAll();
    else {
      while (valid == false ) {
	if (b->validId(cmd) == true) {
	  valid = true;
	  for (auto client : b->getClients()) {
	    if (std::stoi(cmd) == client->getId())
	      b->showSpecific(std::stoi(cmd));
	  }
	} else {
	  std::cout << "> ";
	  std::getline(std::cin, cmd);
	}
      }
    }
  } catch (ExceptionHandler &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return;
  }
}

void withdraw(std::string s, Bank *b) {
  std::string	cmd;
  int		id;
  double	amount = 0;
  try {
    std::cout << "Enter the ID of the account you want to withdraw from.\n> ";
    std::getline(std::cin, cmd);
    if (b->validId(cmd) == false) {
      throw ExceptionHandler("The account doesn't exist.\n");
    }
    id = std::stoi(cmd);
    std::cout << "How much do you want to withraw from this account ?\n> ";
    std::getline(std::cin, cmd);
    if (b->isDigit(cmd) == true) {
      amount = std::stod(cmd);
      for (auto client : b->getClients()) {
	if (client->getId() == id) {
	  if (client->getType() == e_type::retraite)
	    dynamic_cast<Retraite *>(client)->withdraw(amount);
	  else if (client->getType() == e_type::enfant)
	    dynamic_cast<Children *>(client)->withdraw(amount);
	  else
	    client->withdraw(amount);
	}
      }
    }    
  } catch (ExceptionHandler &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return;
  }
  (void)s;
}

void deposit(std::string s, Bank *b) {
  
  std::string	cmd;
  int		id;
  double	amount = 0;
  try {
    std::cout << "Enter the ID of the account you want to deposit on.\n> ";
    std::getline(std::cin, cmd);
    if (b->validId(cmd) == false) {
      throw ExceptionHandler("The account doesn't exist.\n");
    }
    id = std::stoi(cmd);
    std::cout << "How much do you want to deposit on this account ?\n> ";
    std::getline(std::cin, cmd);
    if (b->isDigit(cmd) == true) {
      amount = std::stod(cmd);
      for (auto client : b->getClients()) {
	if (client->getId() == id) {
	  client->deposit(amount);
	}
      }
    }    
  } catch (ExceptionHandler &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return;
  }
  (void)s;
}

void create(std::string s, Bank *b) {
  std::string	date;
  std::string	firstname;
  std::string	lastname;
  std::string	cmd;
  int		parentId = 0;
  e_type	type;
  
  (void)s;
  std::cout << "What is the birthdate of the new user (Format YYYY-(M)M-DD) ?\n> ";
  std::getline(std::cin, cmd);
  date = cmd; 
  std::cout << "What is the lastname of the new user ?\n> ";
  std::getline(std::cin, cmd);
  lastname = cmd;
  std::cout << "What is the firstname of the new user ?\n> ";
  std::getline(std::cin, cmd);
  firstname = cmd;
  if (isDateValid(date) == true) { //TODO add verification lastname & firstname // Throw si date invalide
    Date *d = new Date(date);
    if (d->daysBetweenDate(d->getLiteral(), d->getNow()) <= 3650) {
      type = e_type::enfant;
      std::cout << "As a children you must provide the ID from one of your parent. \n> ";
      std::getline(std::cin, cmd);
      while (b->validId(cmd) == false) {
	std::cout << "The ID doesn't exist, please enter a valid ID. \n> ";
	std::getline(std::cin, cmd);
      }
      parentId = std::stoi(cmd);
    }
    else
      type = e_type::classic;
    b->dynamicallyCreateClient(new Date(date), lastname, firstname, type, parentId);
  }
}

void help(std::string s, Bank *b) {
  (void)s;
  std::cout << "quit will terminate the program and save all the information in the .csv" << std::endl;
  std::cout << "create will allow you to create a freshly new account" << std::endl;
  (void)b;
}

void quit(std::string s, Bank *b) {
  (void)s;
  b->save(b->getDatabaseLocation());
  exit(1);
}



// Passer Bank en reference comme ça pas besoin de recup la valeur de retour

int	main(int argc, char **argv) {
  (void)argc;
  (void)argv;
  Bank *b = new Bank("banque.csv");

  typedef void (*DoIt)(std::string, Bank *);
  typedef std::map<std::string, DoIt> MapCall;
  MapCall	doit;
  doit.insert(MapCall::value_type("show", show));
  doit.insert(MapCall::value_type("withdraw", withdraw));
  doit.insert(MapCall::value_type("deposit", deposit));
  doit.insert(MapCall::value_type("create", create));
  doit.insert(MapCall::value_type("help", help));
  doit.insert(MapCall::value_type("quit", quit));
  std::string cmd;
  std::cout << "> ";
  while (cmd != "exit" && cmd != "quit") {
    std::getline(std::cin, cmd);
    
    MapCall::const_iterator call;
    call = doit.find(cmd);
    if (call != doit.end()) {
      (*call).second(cmd, b);
    }
    else {
      std::cout << "Unknown command, type help to get the command list." << std::endl;
    }
    std::cout << "> ";
  }
  return (0);
}
