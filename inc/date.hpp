#ifndef		_DATE_HPP_
# define	_DATE_HPP_

#include <string>

class		Date {
private:
  int		_day;
  int		_month;
  int		_year;
  std::string	_literal;
public:
  Date();
  Date(int,int,int);
  Date(std::string);
  int		getDay() const;
  int		getMonth() const;
  int		getYear() const;
  std::string	getLiteral() const;
  
  void		setDay(int);
  void		setMonth(int);
  void		setYear(int);
  void		setLiteral(std::string);

  void		distributeIntegerDate(std::string);
  std::string	buildDate(int, int, int);
  void		dump() const;
  virtual ~Date();
};

#endif		/* _DATE_HPP_ */
