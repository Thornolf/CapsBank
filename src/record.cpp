#include	<iostream>

#include	"record.hpp"

Record::Record() {
  
}

Record::Record(Date *newDate, float newBalance) {
  this->_date = newDate;
  this->_balance = newBalance;
}

Date	*Record::getDate() const {
  return (this->_date);
}

float	Record::getBalance() const {
  return (this->_balance);
}

void	Record::setDate(Date *newDate) {
  this->_date = newDate;
}

void	Record::setBalance(float newBalance) {
  this->_balance = newBalance;
}

void	Record::dump() const {
  std::cout << "Date : " << this->_date->getLiteral();
  std::cout << " Amount : " << this->_balance << std::endl;
}

Record::~Record() {}
