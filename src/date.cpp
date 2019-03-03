#include	<iostream>

#include	"date.hpp"

Date::Date() {
  this->_day = 1;
  this->_month = 1;
  this->_year = 1969;
  this->_literal = buildDate(this->_day, this->_month, this->_year);
}

Date::Date(int newDay, int newMonth, int newYear) {
  this->_day = newDay;
  this->_month = newMonth;
  this->_year = newYear;
  this->_literal = buildDate(this->_day, this->_month, this->_year);
}

Date::Date(std::string newLiteral) {
  this->_literal = newLiteral;
  distributeIntegerDate(newLiteral);
}

int		Date::getDay() const {
  return (this->_day);
}

int		Date::getMonth() const {
  return (this->_month);
}

int		Date::getYear() const {
  return (this->_year);
}

std::string	Date::getLiteral() const {
  return (this->_literal);
}

void		Date::setDay(int newDay) {
  this->_day = newDay;
}

void		Date::setMonth(int newMonth) {
  this->_month = newMonth;
}

void		Date::setYear(int newYear) {
  this->_year = newYear;
}

void		Date::setLiteral(std::string newLiteral) {
  this->_literal = newLiteral;
}

void		Date::distributeIntegerDate(std::string newDate) {
  this->_day = std::stoi(newDate.substr(0, newDate.find("-")));
  this->_month = std::stoi(newDate.substr(4, newDate.find("-")));
  this->_year = std::stoi(newDate.substr(6, newDate.find("-") + 2));
}

std::string	Date::buildDate(int newDay, int newMonth, int newYear) {
  std::string	literal_date = "";
  
  if (newDay <= 9) {
    literal_date += "0";
    literal_date += std::to_string(newDay);
  } else {
    literal_date += std::to_string(newDay);
  }
  literal_date += "-";
  if (newMonth <= 9) {
    literal_date += "0";
    literal_date += std::to_string(newMonth);
  } else {
    literal_date += std::to_string(newMonth);
  }
  literal_date += "-";
  literal_date += std::to_string(newYear);
  return (literal_date);
}

void		Date::dump() const {
  std::cout << "Day is : " << this->_day << std::endl;
  std::cout << "Month is : " << this->_month << std::endl;
  std::cout << "Year is : " << this->_year << std::endl;
  std::cout << "The whole date is : " << this->_literal << std::endl;
}
Date::~Date() {}
