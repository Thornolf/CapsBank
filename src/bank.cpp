#include		<fstream>
#include		<iostream>

#include		"bank.hpp"

Bank::Bank() {
  
}

Bank::Bank(std::vector<Account>	newClients, std::string	newDatabaseLocation) {
  this->_clients = newClients;
  this->_databaseLocation = newDatabaseLocation;
}

void			Bank::setClients(std::vector<Account>	newClients) {
  this->_clients = newClients;
}

void			Bank::setDatabaseLocation(std::string newDatabaseLocation) {
  this->_databaseLocation = newDatabaseLocation;
}


std::vector<Account>	Bank::getClients(void) const {
  return (this->_clients);
}

std::string		Bank::getDatabaseLocation(void) const {
  return (this->_databaseLocation);
}

void			Bank::createClient(std::string data) {
  std::string			s = data.substr(0, data.find(",,") + 1);
  std::string			delimiter = ",";
  std::vector<std::string>	param;
  std::vector<std::string>	DataHistory;
  std::list<Record*>		newHistory
  std::string			token;
  size_t			pos = 0;
  
  while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    param.push_back(token);
    s.erase(0, pos + delimiter.length());
  }
  std::string			tmp = data.substr(data.find(",,") + 2);
  std::string			amount = tmp.substr(0, tmp.find(","));
  std::string			old_status = tmp.substr(tmp.find(",") + 1);
  pos = 0;
  while ((pos = old_status.find(delimiter)) != std::string::npos) {
    token = old_status.substr(0, pos);
    histories.push_back(token);
    old_status.erase(0, pos + delimiter.length());
  }
  histories.push_back(old_status);
  for (unsigned int i = 0; i + 1 < histories.size(); i += 2)
    {
      std::cout << "Date : " << histories.at(i);
      std::cout << "  Amount : " << histories.at(i + 1) << std::endl;
    }
}

void			Bank::save(std::string locationFile) {
  (void)locationFile;
}

void			Bank::load(std::string locationFile) {
  std::string line;
  std::ifstream file(locationFile);
  
  if (file.is_open()) {
    while ( getline (file,line) ) {
      createClient(line);
    }
    file.close();
  }
}

Bank::~Bank() {
  
}
