#include		<fstream>
#include		<iostream>
#include		<iomanip>

#include		"exceptionHandler.hpp"
#include		"bank.hpp"

static	std::string	roundDouble(double nbr) {
  std::ostringstream round;
  round << std::fixed;
  round << std::setprecision(2);
  round << nbr;
  return (round.str());
}

Bank::Bank(std::string	newDatabaseLocation) {
  this->_databaseLocation = newDatabaseLocation;
  load(this->_databaseLocation);
}

Bank::Bank(std::vector<Account*> newClients, std::string newDatabaseLocation) {
  this->_clients = newClients;
  this->_databaseLocation = newDatabaseLocation;
}

void			Bank::setClients(std::vector<Account*> newClients) {
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

template <typename T>
void			Bank::addClient(T const &newAccount) {
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

void			Bank::dynamicallyCreateClient(Date *birthdate, std::string lastname, std::string firstname, e_type type, int parentId) {
  int newId = nonUsedId(this->_clients);
  if (type == e_type::enfant)
    addClient(new Children(newId, birthdate, lastname, firstname, 0.0, parentId, e_type::enfant));
  else
    addClient(new Account(newId, birthdate, lastname, firstname, 0.0, e_type::classic));
  for (auto c : this->_clients) {
    std::cout << "Id : " << c->getId() << std::endl;
  }
}

void			Bank::showAll(void) {
  for (auto client : this->_clients) {
    std::cout << "["<< client->getId() << "] " << client->getLastname() << " " << client->getFirstname();
    std::cout << " : " << roundDouble(client->getBalance()) << " $ " << std::endl;
    std::cout << std::endl;
  }
}

void			Bank::showSpecific(int id) {
  for (auto client : this->_clients) {
    if (id == client->getId()) {
      std::cout << "["<< client->getId() << "] " << client->getLastname() << " " << client->getFirstname();
      std::cout << " : " << roundDouble(client->getBalance()) << " $ " << std::endl;
      std::cout << std::endl;
    }
  }
}

int			Bank::nonUsedId(std::vector<Account *> clients) {
  int newId = 1;

  for (auto it = clients.begin(); it != clients.end(); it++) {
    if (newId == (*it)->getId()) {
      newId++;
      it = clients.begin();
    }
  }
  return (newId);
}

bool			Bank::validId(std::string id) {
  int	parentId;
  
  if (isDigit(id) == false)
    throw ExceptionHandler("Not a number");
  parentId = std::stoi(id);
  for (auto client : this->_clients) {
    if (client->getId() == parentId)
      return (true);
  }
  std::cerr << "Unknown ID, please enter a valid ID." << std::endl;
  return (false);
}

void			Bank::save(std::string locationFile) {
  std::ofstream clearFile;
  
  clearFile.open(locationFile, std::ofstream::out | std::ofstream::trunc);
  clearFile.close();
  
  std::ofstream writeFile;
  writeFile.open(locationFile, std::ios::out);
  for (auto client : this->_clients) {
    std::string s = "";
    
    if (client->getType() == e_type::retraite) {
      s += std::to_string(client->getId());
      s += ",R," + client->getLastname() + "," + client->getFirstname() + ",";
      s +=  client->getBirthdate()->getLiteral() + ",,";
      s += roundDouble(client->getBalance());
      for (auto h : client->getHistory()) {
	s += "," + h->getDate()->getLiteral() + ",";
	s += roundDouble(h->getBalance());
      }
      s += "\n";
    } else if (client->getType() == e_type::enfant) {
      
      s += std::to_string(client->getId());
      s += ",E," + client->getLastname() + "," + client->getFirstname() + ",";
      s +=  client->getBirthdate()->getLiteral() + ",";
      s += std::to_string(dynamic_cast<Children *>(client)->getParentId()) + ",";
      s += roundDouble(client->getBalance());
      
      for (auto h : client->getHistory()) {
	s += "," + h->getDate()->getLiteral() + ",";
	s += roundDouble(h->getBalance());
      }
      s += "\n";
    } else {
      s += std::to_string(client->getId());
      s += ",A," + client->getLastname() + "," + client->getFirstname() + ",";
      s +=  client->getBirthdate()->getLiteral() + ",,";
      s += roundDouble(client->getBalance());
      for (auto h : client->getHistory()) {
	s += "," + h->getDate()->getLiteral() + ",";
	s += roundDouble(h->getBalance());
      }
      s += "\n";
    }
    writeFile << s;
  }
  writeFile.close();
}

void			Bank::load(std::string locationFile) {
  std::string			line;
  std::ifstream			file(locationFile, std::ios::in);
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
      if (profil.at(1) == "E") {
	addClient(new Children(std::stoi(profil.at(0)), new Date(profil.at(4)), profil.at(2), profil.at(3), std::stod(profil.at(6)), std::stoi(profil.at(5)), e_type::enfant, history));
      }
      else if (profil.at(1) == "R") {
	addClient(new Retraite(std::stoi(profil.at(0)), new Date(profil.at(4)), profil.at(2), profil.at(3), std::stod(profil.at(6)), e_type::retraite, history));
      }
      else {
	addClient(new Account(std::stoi(profil.at(0)), new Date(profil.at(4)), profil.at(2), profil.at(3), std::stod(profil.at(6)), e_type::classic, history));
      }
      i = 7;
      history.clear();
    }
    file.close();
  }
}

bool		Bank::isDigit(const std::string& string) const
{
    std::string::const_iterator it = string.begin();
    while (it != string.end())
      {
	if ((*it < '0' || *it >'9') && (*it != '.'))
	  {
	    throw ExceptionHandler("Not a number.");
	  }
	++it;
      }
    return !string.empty() && it == string.end();
}

void			Bank::dump() const {
}

Bank::~Bank() {
  
}
