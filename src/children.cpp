#include	<iostream>

#include	"children.hpp"

Children::Children() {
  this->_monthlyWithdraw = 0;
  this->_dailyWithdraw = 0;
  this->_parent = new Account();
}

Children::Children(int id, Date *date, std::string lastname, std::string firstname, int balance, Account *newParent) : Account(id, date, lastname, firstname, balance) {
  this->_monthlyWithdraw = 0;
  this->_dailyWithdraw = 0;
  this->_parent = newParent;
}

int		Children::getMonthlyLimit() const {
  return (this->_monthlyLimit);
}

int		Children::getDailyLimit() const {
  return (this->_dailyLimit);
}

int		Children::getMonthlyWithdraw() const {
  return (this->_monthlyWithdraw);
}

int		Children::getDailyWithdraw() const {
  return (this->_dailyWithdraw);
}

Account		*Children::getParent() {
  return (this->_parent);
}

void		Children::setMonthlyWithdraw(int newMonthlyWithdraw) {
  this->_monthlyWithdraw = newMonthlyWithdraw;
}

void		Children::setDailyWithdraw(int newDailyWithdraw) {
  this->_dailyWithdraw = newDailyWithdraw;
}

void		Children::setParent(Account *newParent) {
  this->_parent = newParent;
}


int		Children::withdraw(int amount) {
  int	tmp_monthly = amount + this->_monthlyWithdraw;
  int	tmp_daily = amount + this->_dailyWithdraw;
  
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

Children::~Children() {
}
