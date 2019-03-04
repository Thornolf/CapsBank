#ifndef		_CHILDREN_HPP_
# define	_CHILDREN_HPP_

#include	"account.hpp"

class		Children : public Account {
 public:
  Children();
  Children(int , Date *, std::string, std::string , float, Account *);

  float		getMonthlyLimit() const;
  float		getDailyLimit() const;
  float		getMonthlyWithdraw() const;
  float		getDailyWithdraw() const;
  Account	*getParent();
  void		setMonthlyWithdraw(float);
  void		setDailyWithdraw(float);
  void		setParent(Account *);
  
  float		withdraw(float);
  virtual ~Children();
 private:
  float const	_monthlyLimit = 50.0;
  float const	_dailyLimit = 10.0;
  float		_monthlyWithdraw;
  float		_dailyWithdraw;
  Account	*_parent;
};

#endif		/* _CHILDREN_HPP_ */
