#include	<iostream>
#include	<list>

#include	"account.hpp"

Account::Account() {
  this->_id = 1;
  this->_birthdate = new Date();
  this->_lastname = "Menethil";
  this->_firstname = "Arthas";
  this->_balance = 999.0;
  this->_accountType = e_type::classic;
}

Account::Account(int newId, Date *newBirthdate, std::string newLastname, std::string newFirstname, float newBalance, e_type newType, std::list<Record*> newHistory) {
  this->_id = newId;
  this->_birthdate = newBirthdate;
  this->_lastname = newLastname;
  this->_firstname = newFirstname;
  this->_balance = newBalance;
  this->_accountType = newType;
  this->_history = newHistory;
}

int		Account::getId() const {
  return (this->_id);
}

Date		*Account::getBirthdate() const {
  return (this->_birthdate);
}

std::string	Account::getFirstname() const {
  return (this->_firstname);
}

std::string	Account::getLastname() const {
  return (this->_lastname);
}

float		Account::getBalance() const {
  return (this->_balance);
}

std::list<Record*>Account::getHistory() const {
  return (this->_history);
}

e_type		Account::getType() const {
  return (this->_accountType);
}

void		Account::setId(int newId) {
  this->_id = newId;
}

void		Account::setBirthdate(Date *newBirthdate) {
  this->_birthdate = newBirthdate;
}

void		Account::setLastname(std::string newLastname) {
  this->_lastname = newLastname;
}

void		Account::setFirstname(std::string newFirstname) {
  this->_firstname = newFirstname;
}

void		Account::setBalance(float newBalance) {
  this->_balance = newBalance;
}

void		Account::setHistory(std::list<Record*> newHistory) {
  this->_history = newHistory;
}

void		Account::setType(e_type newType) {
  this->_accountType = newType;
}

void		Account::addRecordToHistory(Record *newRecord) {
  this->_history.push_back(newRecord);
}

void		Account::deposit(float amount) {
  this->_balance += amount;
}

float		Account::withdraw(float amount) {
  if (amount <= this->_balance)
    this->_balance -= amount;
  else
    std::cout << "Cannot take this amount." << std::endl;
    //TODO throw error
  return (amount);
}

void		Account::dump() const {
  std::cout << "Id : " << this->_id;
  std::cout << " Birthdate : " << this->_birthdate->getLiteral();
  std::cout << " \"" << this->_lastname;
  std::cout << " " << this->_firstname;
  std::cout << "  type: " << this->_accountType;
  std::cout << "\" Balance : " << this->_balance << std::endl;

  std::cout << "--- History ---" << std::endl;
  for (auto const& r : this->_history) {
    r->dump();
  }
}
Account::~Account() {}
