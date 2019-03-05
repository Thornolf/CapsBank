#include	<iostream>

#include	"children.hpp"

Children::Children() {
  this->_monthlyWithdraw = 0.0;
  this->_dailyWithdraw = 0.0;
  this->_parent = new Account();
}

Children::Children(int id, Date *date, std::string lastname, std::string firstname, float balance, Account *newParent, e_type type, std::list<Record*> history) : Account(id, date, lastname, firstname, balance, type, history) {
  this->_monthlyWithdraw = 0.0;
  this->_dailyWithdraw = 0.0;
  this->_parent = newParent;
}

float		Children::getMonthlyLimit() const {
  return (this->_monthlyLimit);
}

float		Children::getDailyLimit() const {
  return (this->_dailyLimit);
}

float		Children::getMonthlyWithdraw() const {
  return (this->_monthlyWithdraw);
}

float		Children::getDailyWithdraw() const {
  return (this->_dailyWithdraw);
}

Account		*Children::getParent() {
  return (this->_parent);
}

void		Children::setMonthlyWithdraw(float newMonthlyWithdraw) {
  this->_monthlyWithdraw = newMonthlyWithdraw;
}

void		Children::setDailyWithdraw(float newDailyWithdraw) {
  this->_dailyWithdraw = newDailyWithdraw;
}

void		Children::setParent(Account *newParent) {
  this->_parent = newParent;
}

float		Children::withdraw(float amount) {
  float	tmp_monthly = amount + this->_monthlyWithdraw;
  float	tmp_daily = amount + this->_dailyWithdraw;
  
  if (amount <= this->_balance && tmp_monthly <= this->_monthlyLimit && tmp_daily <= this->_dailyLimit) {
    if (this->_monthlyWithdraw <= this->_monthlyLimit && this->_dailyWithdraw <= this->_dailyLimit) {
      this->_dailyWithdraw += amount;
      this->_monthlyWithdraw += amount;
      this->_balance -= amount;
    }
  }
  else
    if (tmp_monthly <= this->_monthlyLimit)
      throw "You cannot withdraw more than your monthly limit.";
    else if (tmp_monthly <= this->_dailyLimit)
      throw "You cannot withdraw more than your daily limit.";
    else
      throw "Not enough funds in your bank accunt.";
  return (amount);
}

void		Children::dump() const {
  std::cout << "Id : " << this->getId();
  std::cout << " Birthdate : " << this->getBirthdate()->getLiteral();
  std::cout << " \"" << this->getLastname();
  std::cout << " " << this->getFirstname();
  std::cout << "\" Balance : " << this->getBalance() << std::endl;
  std::cout << "Responsable : " << this->_parent->getFirstname() << std::endl;
  std::cout << "--- History ---" << std::endl;
  for (auto const& r : this->getHistory()) {
    r->dump();
  }
}

Children::~Children() {
}
