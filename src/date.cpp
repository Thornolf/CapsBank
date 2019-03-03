#include	<iostream>

#include	"date.hpp"

Date::Date() {
  this->_day = 1;
  this->_month = 1;
  this->_year = 1969;
  this->_literal = buildDate(this->_year, this->_month, this->_day);
}

Date::Date(int newYear, int newMonth, int newDay) {
  this->_year = newYear;
  this->_month = newMonth;
  this->_day = newDay;
  this->_literal = buildDate(this->_year, this->_month, this->_day);
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
  this->_year = std::stoi(newDate.substr(0, newDate.find("-") + 2));
  this->_month = std::stoi(newDate.substr(6, newDate.find("-")));
  this->_day = std::stoi(newDate.substr(4, newDate.find("-")));
}

std::string	Date::buildDate(int newYear, int newMonth, int newDay) {
  std::string	literal_date = "";
  
  literal_date += std::to_string(newYear);
  literal_date += "-";
  literal_date += std::to_string(newMonth);
  literal_date += "-";
  literal_date += std::to_string(newDay);
  return (literal_date);
}

void		Date::dump() const {
  std::cout << "Day is : " << this->_day << std::endl;
  std::cout << "Month is : " << this->_month << std::endl;
  std::cout << "Year is : " << this->_year << std::endl;
  std::cout << "The whole date is : " << this->_literal << std::endl;
}
Date::~Date() {}
