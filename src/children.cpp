#include	<iostream>

#include	"children.hpp"

Children::Children() {
  this->_monthlyWithdraw = 0.0;
  this->_dailyWithdraw = 0.0;
  this->_parentId = 1;
}

Children::Children(int id, Date *date, std::string lastname, std::string firstname, double balance, int newParentId, e_type type, std::list<Record*> history) : Account(id, date, lastname, firstname, balance, type, history) {
  this->_monthlyWithdraw = 0.0;
  this->_dailyWithdraw = 0.0;
  this->_parentId = newParentId;
}

Children::Children(int id, Date *date, std::string lastname, std::string firstname, double balance, int newParentId, e_type type) : Account(id, date, lastname, firstname, balance, type) {
  this->_monthlyWithdraw = 0.0;
  this->_dailyWithdraw = 0.0;
  this->_parentId = newParentId;
}

double		Children::getMonthlyLimit() const {
  return (this->_monthlyLimit);
}

double		Children::getDailyLimit() const {
  return (this->_dailyLimit);
}

double		Children::getMonthlyWithdraw() const {
  return (this->_monthlyWithdraw);
}

double		Children::getDailyWithdraw() const {
  return (this->_dailyWithdraw);
}

int		Children::getParentId() {
  return (this->_parentId);
}

void		Children::setMonthlyWithdraw(double	newMonthlyWithdraw) {
  this->_monthlyWithdraw = newMonthlyWithdraw;
}

void		Children::setDailyWithdraw(double	newDailyWithdraw) {
  this->_dailyWithdraw = newDailyWithdraw;
}

void		Children::setParentId(int	newParentId) {
  this->_parentId = newParentId;
}

double		Children::withdraw(double amount) {
  double	tmp_monthly = amount + this->_monthlyWithdraw;
  double	tmp_daily = amount + this->_dailyWithdraw;
  
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
  std::cout << "Responsable : " << this->_parentId << std::endl;
  std::cout << "--- History ---" << std::endl;
  for (auto const& r : this->getHistory()) {
    r->dump();
  }
}

Children::~Children() {
}
