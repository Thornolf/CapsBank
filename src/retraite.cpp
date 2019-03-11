#include	<iostream>
#include	<string>

#include	"retraite.hpp"
#include	"exceptionHandler.hpp"

Retraite::Retraite() {
  this->_authorisation = new Authorisation();
}

Retraite::Retraite(int id, Date *date, std::string lastname, std::string firstname, double balance, e_type type, std::list<Record*> history) : Account(id, date, lastname, firstname, balance, type, history) {
  this->_authorisation = new Authorisation();
}

Retraite::Retraite(int id, Date *date, std::string lastname, std::string firstname, double balance, e_type type) : Account(id, date, lastname, firstname, balance, type) {
  this->_authorisation = new Authorisation();
}

double          Retraite::withdraw(double amount) {
  if (amount <= this->_balance && (this->_authorisation->withdrawRequest() == true)) {
    std::cout << "The request for your withdraw of "<< amount << " $ was approved by the bank." << std::endl;
    this->_balance -= amount;
    this->addRecordToHistory(new Record(new Date(this->getBirthdate()->getNow()), this->_balance));
  }
  else
    throw ExceptionHandler("Not enough funds in your bank account.");
  return (amount);
}

bool		Retraite::authorization(double amount) {
  (void)amount;
  return (true);
}

Retraite::~Retraite() {}
