#ifndef		_CHILDREN_HPP_
# define	_CHILDREN_HPP_

#include	"account.hpp"

class		Children : public Account {
 public:
  Children();
  Children(int , Date *, std::string, std::string , int, Account *);

  int		getMonthlyLimit() const;
  int		getDailyLimit() const;
  int		getMonthlyWithdraw() const;
  int		getDailyWithdraw() const;
  Account	*getParent();
  void		setMonthlyWithdraw(int);
  void		setDailyWithdraw(int);
  void		setParent(Account *);
  
  int		withdraw(int);
  virtual ~Children();
 private:
  int const	_monthlyLimit = 50;
  int const	_dailyLimit = 10;
  int		_monthlyWithdraw;
  int		_dailyWithdraw;
  Account	*_parent;
};

#endif		/* _CHILDREN_HPP_ */
