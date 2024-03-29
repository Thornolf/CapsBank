#include	<iostream>

#include	"record.hpp"

Record::Record() {
  
}

Record::Record(Date *newDate, double newBalance) {
  this->_date = newDate;
  this->_balance = newBalance;
}

Date	*Record::getDate() const {
  return (this->_date);
}

double	Record::getBalance() const {
  return (this->_balance);
}

void	Record::setDate(Date *newDate) {
  this->_date = newDate;
}

void	Record::setBalance(double newBalance) {
  this->_balance = newBalance;
}

void	Record::dump() const {
  std::cout << " " << this->_date->getLiteral();
  std::cout << " : " << this->_balance << " $"<< std::endl;
}

Record::~Record() {}
