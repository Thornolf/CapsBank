#include		"bank.hpp"

Bank::Bank() {
  
}

void			Bank::setClients(std::vector<Account>	newClients, std::string	newDatabseLocation) {
  this->_clients = newClients;
  this->_databaseLocation = newDatabaseLocation;
}

void			Bank::getClients() {
  return (this->_clients);
}

void			Bank::save(std::string locationFile) {
  
}

void			Bank::load(std::string locationFile) {
  
}
Bank::~Bank() {
  
}
