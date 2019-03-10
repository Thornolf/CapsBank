#include	<iostream>
#include	<fstream>
#include	<map>

#include	"date.hpp"
#include	"account.hpp"
#include	"children.hpp"
#include	"bank.hpp"
#include	<time.h>

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
  std::cout << s << std::endl;
  (void)b;
}

void withdraw(std::string s, Bank *b) {
  std::cout << s << std::endl;
  (void)b;
}

void deposit(std::string s, Bank *b) {
  std::cout << s << std::endl;
  (void)b;
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
  Date *d = new Date(date);
  if (d->daysBetweenDate(d->getLiteral(), d->getNow()) <= 3650) {
    type = e_type::enfant;
    while (b->validId(std::stoi(cmd))) {
      std::cout << "As a children you must provide the ID from one of your parent ?\n> ";
      std::getline(std::cin, cmd);
    }
    parentId = std::stoi(cmd);
    std::cout << "Parent Id : " << parentId << std::endl;
  }
  else
    type = e_type::classic;
  if (isDateValid(date) == true) { //TODO add verification lastname & firstname
    b->dynamicallyCreateClient(new Date(date), lastname, firstname, type, parentId);
  }
}

void help(std::string s, Bank *b) {
  (void)s;
  std::cout << "quit will terminate the program and save all the information in the .csv" << std::endl;
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
  (void)b;  

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
      std::cout << "Unknown call requested" << std::endl;
    }
    std::cout << "> ";
  }
  return (0);
}
