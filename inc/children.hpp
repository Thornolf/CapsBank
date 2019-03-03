#ifndef		_CHILDREN_HPP_
# define	_CHILDREN_HPP_

#include	"account.hpp"

Class	Children : public Account {
 public:
  Children();
  int		withdraw(int);
  virtual ~Children();
 private:
  int		_monthlyLimit = 50;
  int		_actualMonthWithdraw;
  Account	*_parent;
};

#endif		/* _CHILDREN_HPP_ */
