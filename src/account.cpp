#include	"account.hpp"

Account::Account() {
  this->_id = 1;
  this->_birthdate = new Date();
  this->_name = "Codsworth";
  this->_balance = 999;
}

Account::~Account() {}
