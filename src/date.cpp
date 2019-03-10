#include	<iostream>

#include	"date.hpp"


static	std::vector<std::string>	vectorisationDate(std::string predicat) {
  std::vector<std::string>	data;
  size_t			pos = 0;
  std::string			token;
  std::string			delimiter = "-";
  
  while ((pos = predicat.find(delimiter)) != std::string::npos) {
    token = predicat.substr(0, pos);
    data.push_back(token);
    predicat.erase(0, pos + delimiter.length());
  }
  data.push_back(predicat);
  return (data);
}

Date::Date() {
  this->_day = 1;
  this->_month = 1;
  this->_year = 1969;
  this->_literal = buildDate(this->_year, this->_month, this->_day);
  time_t	now;
  struct tm	*timeinfo;
  char		buffer [80];
  time(&now);
  timeinfo = localtime(&now);
  strftime (buffer, 80, "%F", timeinfo);
  this->_now = buffer;
}

Date::Date(int newYear, int newMonth, int newDay) {
  this->_year = newYear;
  this->_month = newMonth;
  this->_day = newDay;
  this->_literal = buildDate(this->_year, this->_month, this->_day);
  time_t	now;
  struct tm	*timeinfo;
  char		buffer [80];
  time(&now);
  timeinfo = localtime(&now);
  strftime (buffer, 80, "%F", timeinfo);
  this->_now = buffer;
}

Date::Date(std::string newLiteral) {
  this->_literal = newLiteral;
  distributeIntegerDate(newLiteral);
  time_t	now;
  struct tm	*timeinfo;
  char		buffer [80];
  time(&now);
  timeinfo = localtime(&now);
  strftime (buffer, 80, "%F", timeinfo);
  this->_now = buffer;
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

std::string	Date::getNow() const {
  return (this->_now);
}

int		Date::getNumberDays() const {
  return (this->_numberDays);
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

void		Date::setNow(std::string newNow) {
  this->_now = newNow;
}

void		Date::setNumberDays(int newNumberDays) {
  this->_numberDays = newNumberDays;
}

void		Date::distributeIntegerDate(std::string newDate) {
  std::vector<std::string> v;
  v = vectorisationDate(newDate);
  this->_year = std::stoi(v.at(0));
  this->_month = std::stoi(v.at(1));
  this->_day = std::stoi(v.at(2));
}

int		Date::daysBetweenDate(std::string firstDate, std::string lastDate) {
  int				first = 0;
  int				last = 0;
  std::vector<std::string>	firstVector = vectorisationDate(firstDate);
  std::vector<std::string>	lastVector  = vectorisationDate(lastDate);

  first += (std::stoi(firstVector.at(0)) * 365);
  first += (std::stoi(firstVector.at(1)) * 31);
  first += (std::stoi(firstVector.at(2)));
  last += (std::stoi(lastVector.at(0)) * 365);
  last += (std::stoi(lastVector.at(1)) * 31);
  last += (std::stoi(lastVector.at(2)));
  return (last - first);
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
