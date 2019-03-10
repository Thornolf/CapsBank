#ifndef		_DATE_HPP_
# define	_DATE_HPP_

#include	<string>
#include	<vector>
#include	<time.h>

class		Date {
private:
  std::string	_now;
  int		_day;
  int		_month;
  int		_year;
  int		_numberDays;
  std::string	_literal;
public:
  Date();
  Date(int,int,int);
  Date(std::string);
  int		getDay() const;
  int		getMonth() const;
  int		getYear() const;
  int		getNumberDays() const;
  std::string	getLiteral() const;
  std::string	getNow() const;
  
  void		setDay(int);
  void		setMonth(int);
  void		setYear(int);
  void		setLiteral(std::string);
  void		setNow(std::string);
  void		setNumberDays(int);

  int		daysBetweenDate(std::string, std::string);
  void		distributeIntegerDate(std::string);
  std::string	buildDate(int, int, int);
  void		dump() const;
  virtual ~Date();
};

#endif		/* _DATE_HPP_ */
