#include	<iostream>
#include	<fstream>
#include	<map>

#include	"date.hpp"
#include	"account.hpp"
#include	"children.hpp"
#include	"bank.hpp"
#include	"exceptionHandler.hpp"

static bool		isDateValid(std::string predicat) {
  std::vector<std::string>	data;
  std::string			delimiter = "-";
  std::string			token;
  size_t			pos = 0;
  int				year = 0;
  int				month = 0;
  int				day = 0;
  int				count = 0;

  std::string::const_iterator it = predicat.begin();
  while (++it != predicat.end())
    if ((*it < '0' || *it >'9') && (*it != '-'))
      throw ExceptionHandler("Not a valid date.");
  while ((pos = predicat.find(delimiter)) != std::string::npos) {
    token = predicat.substr(0, pos);
    data.push_back(token);
    predicat.erase(0, pos + delimiter.length());
    count++;
  }
    data.push_back(predicat);
    year = std::stoi(data.at(0));
    month = std::stoi(data.at(1));
    day = std::stoi(data.at(2));
    if ((month >= 0 && month <= 12) && (day >= 0 && day <= 31) && count == 2 && year > 0)
      return (true);
    return (false);
}

static bool		isNamesValid(std::string predicat) {
  std::string::const_iterator it = predicat.begin();
  while (++it != predicat.end())
    if ((*it < 'a' || *it >'z') && (*it != '-') && (*it < 'A' || *it >'Z'))
      throw ExceptionHandler("Not a valid name. Names contain only letter and \"-\"");
  return (true);
}

static void		show(Bank *b) {
  bool			valid = false;
  std::string		cmd;
  
  try {
    std::cout << "Which account do you want to see ? (Give an ID or type all to see all accounts)\n->";
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
	  std::cout << "-> ";
	  std::getline(std::cin, cmd);
	}
      }
    }
  } catch (ExceptionHandler &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return;
  }
}

static void		withdraw(Bank *b) {
  std::string		cmd;
  int			id;
  double		amount = 0;
  
  try {
    std::cout << "Enter the ID of the account you want to withdraw from.\n->";
    std::getline(std::cin, cmd);
    if (b->validId(cmd) == false) {
      throw ExceptionHandler("The account doesn't exist.");
    }
    id = std::stoi(cmd);
    std::cout << "How much do you want to withraw from this account ?\n->";
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
}

static void		deposit(Bank *b) {
  std::string		cmd;
  int			id;
  double		amount = 0;
  
  try {
    std::cout << "Enter the ID of the account you want to deposit on.\n-> ";
    std::getline(std::cin, cmd);
    if (b->validId(cmd) == false) {
      throw ExceptionHandler("The account doesn't exist.\n");
    }
    id = std::stoi(cmd);
    std::cout << "How much do you want to deposit on this account ?\n-> ";
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
}

static void		create(Bank *b) {
  std::string		date;
  std::string		firstname;
  std::string		lastname;
  std::string		cmd;
  Date			*d;
  int			parentId = 0;
  e_type		type;
  
  try {
    std::cout << "What is the birthdate of the new user (Format YYYY-(M)M-DD) ?\n-> ";
    std::getline(std::cin, cmd);
    date = cmd;
    if (isDateValid(date) == true) {
      d = new Date(date);
    }
    std::cout << "What is the lastname of the new user ?\n-> ";
    std::getline(std::cin, cmd);
    lastname = cmd;
    isNamesValid(lastname);
    std::cout << "What is the firstname of the new user ?\n-> ";
    std::getline(std::cin, cmd);
    firstname = cmd;
    isNamesValid(firstname);
    if (d->daysBetweenDate(d->getLiteral(), d->getNow()) <= 3650) {
      type = e_type::enfant;
      std::cout << "As a children you must provide the ID from one of your parent. \n-> ";
      std::getline(std::cin, cmd);
      while (b->validId(cmd) == false) {
	std::cout << "The ID doesn't exist, please enter a valid ID.\n-> ";
	std::getline(std::cin, cmd);
      }
      parentId = std::stoi(cmd);
    }
    else
      type = e_type::classic;
    b->dynamicallyCreateClient(new Date(date), lastname, firstname, type, parentId);
  } catch (ExceptionHandler &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return;
  }
}

static void		help(Bank *b) {
  std::cout << "show\t: type all or a valid ID to see an account." << std::endl;
  std::cout << "withdraw: take money from an account by selecting a valid ID and an amount." << std::endl;
  std::cout << "deposit\t: put money into an account by selecting a valid ID and an amount." << std::endl;
  std::cout << "create\t: enter a valid birthdate, and a first and last name containing only alphabetic characters" << std::endl;
  std::cout << "quit\t: terminate the program and save all the information in the .csv" << std::endl;
  std::cout << "help\t: print these hints." << std::endl;
  (void)b;
}

static void		quit(Bank *b) {
  b->save(b->getDatabaseLocation());
  exit(1);
}

int			main(void) {
  Bank *b = new Bank("banque.csv");
  typedef void (*func)(Bank *);
  typedef std::map<std::string, func> ListeCommand;
  ListeCommand			      command;
  std::string			      cmd;

  std::cout << "\t\t--- Welcome to the CapsBank, best bank in the Wasteland ! ---\n" << std::endl;
  std::cout << "\t\tThis program was made by Remi GIACOMETTI & Quentin BAUDET\n" << std::endl;
  help(b);
  command.insert(ListeCommand::value_type("show", show));
  command.insert(ListeCommand::value_type("withdraw", withdraw));
  command.insert(ListeCommand::value_type("deposit", deposit));
  command.insert(ListeCommand::value_type("create", create));
  command.insert(ListeCommand::value_type("help", help));
  command.insert(ListeCommand::value_type("quit", quit));
  std::cout << "\n> ";
  while (cmd != "exit" && cmd != "quit") {
    std::getline(std::cin, cmd);
    
    ListeCommand::const_iterator	call;
    call = command.find(cmd);
    if (call != command.end()) {
      (*call).second(b);
    }
    else {
      std::cout << "Unknown command, type help to get the command list." << std::endl;
    }
    std::cout << "> ";
  }
  return (0);
}
