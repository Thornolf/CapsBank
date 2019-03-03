#include	<iostream>

#include	"account.hpp"

Account::Account() {
  this->_id = 1;
  this->_birthdate = new Date();
  this->_lastname = "Menethil";
  this->_firstname = "Arthas";
  this->_balance = 999;
}

Account::Account(int newId, Date *newBirthdate, std::string newLastname, std::string newFirstname, int newBalance) {
  this->_id = newId;
  this->_birthdate = newBirthdate;
  this->_lastname = newLastname;
  this->_firstname = newFirstname;
  this->_balance = newBalance;
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

int		Account::getBalance() const {
  return (this->_balance);
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

void		Account::setBalance(int newBalance) {
  this->_balance = newBalance;
}

void		Account::deposit(int amount) {
  this->_balance += amount;
}

int		Account::withdraw(int amount) {
  if (amount <= this->_balance)
    this->_balance -= amount;
  else
    std::cout << "Cannot take this amount." << std::endl;
    //TODO throw error
  return (amount);
}

void		Account::dump() const {
  std::cout << "Id : " << this->_id << std::endl;
  std::cout << "Birthdate : " << this->_birthdate->getLiteral() << std::endl;
  std::cout << "Lastname : " << this->_lastname << std::endl;
  std::cout << "Firstname : " << this->_firstname << std::endl;
  std::cout << "Balance : " << this->_balance << std::endl;
}
Account::~Account() {}
