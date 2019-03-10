#ifndef		_CHILDREN_HPP_
# define	_CHILDREN_HPP_

#include	"account.hpp"

class		Children : public Account {
 public:
  Children();
  Children(int , Date *, std::string, std::string , double, int, e_type, std::list<Record*>);
  Children(int , Date *, std::string, std::string , double, int, e_type);

  double	getMonthlyLimit() const;
  double	getDailyLimit() const;
  double	getMonthlyWithdraw() const;
  double	getDailyWithdraw() const;
  int		getParentId();
  void		setMonthlyWithdraw(double);
  void		setDailyWithdraw(double);
  void		setParentId(int);
  
  double		withdraw(double);
  void		dump() const;
  virtual ~Children();
 private:
  double const	_monthlyLimit = 50.0;
  double const	_dailyLimit = 10.0;
  double	_monthlyWithdraw;
  double	_dailyWithdraw;
  int		_parentId;
};

#endif		/* _CHILDREN_HPP_ */
