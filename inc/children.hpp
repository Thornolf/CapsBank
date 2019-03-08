#ifndef		_CHILDREN_HPP_
# define	_CHILDREN_HPP_

#include	"account.hpp"

class		Children : public Account {
 public:
  Children();
  Children(int , Date *, std::string, std::string , float, int, e_type, std::list<Record*>);

  float		getMonthlyLimit() const;
  float		getDailyLimit() const;
  float		getMonthlyWithdraw() const;
  float		getDailyWithdraw() const;
  int		getParentId();
  void		setMonthlyWithdraw(float);
  void		setDailyWithdraw(float);
  void		setParentId(int);
  
  float		withdraw(float);
  void		dump() const;
  virtual ~Children();
 private:
  float const	_monthlyLimit = 50.0;
  float const	_dailyLimit = 10.0;
  float		_monthlyWithdraw;
  float		_dailyWithdraw;
  int		_parentId;
};

#endif		/* _CHILDREN_HPP_ */
