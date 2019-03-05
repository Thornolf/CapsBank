#include		<fstream>
#include		<iostream>

#include		"bank.hpp"

Bank::Bank(std::string	newDatabaseLocation) {
  this->_databaseLocation = newDatabaseLocation;
  load(this->_databaseLocation);
}

Bank::Bank(std::vector<Account*> newClients, std::string	newDatabaseLocation) {
  this->_clients = newClients;
  this->_databaseLocation = newDatabaseLocation;
}

void			Bank::setClients(std::vector<Account*>	newClients) {
  this->_clients = newClients;
}

void			Bank::setDatabaseLocation(std::string newDatabaseLocation) {
  this->_databaseLocation = newDatabaseLocation;
}


std::vector<Account*>	Bank::getClients(void) const {
  return (this->_clients);
}

std::string		Bank::getDatabaseLocation(void) const {
  return (this->_databaseLocation);
}

void			Bank::addClient(Account *newAccount) {
  this->_clients.push_back(newAccount);
}

std::vector<std::string>Bank::createClient(std::string data) {
  std::string			delimiter = ",";
  std::string			token;
  size_t			pos = 0;
  std::vector<std::string>	profil;
  
  while ((pos = data.find(delimiter)) != std::string::npos) {
    token = data.substr(0, pos);
    profil.push_back(token);
    data.erase(0, pos + delimiter.length());
  }
  profil.push_back(data);
  return (profil);
}
  
void			Bank::save(std::string locationFile) {
  (void)locationFile;
}

void			Bank::load(std::string locationFile) {
  std::string			line;
  std::ifstream			file(locationFile);
  std::vector<std::string>	profil;
  std::list<Record*>		history;
  unsigned int			i = 7;
  
  if (file.is_open()) {
    while (getline (file,line)) {
      profil = createClient(line);
      while (i + 1 < profil.size()) {
	history.push_back(new Record(new Date(profil.at(i)), std::stof(profil.at(i + 1))));
	i += 2;
      }
      i = 7;
      history.clear();
    }
    file.close();
  }
}

Bank::~Bank() {
  
}
