#ifndef		_RECORD_HPP_
# define	_RECORD_HPP_

#include	"date.hpp"

class Record {
private:
  Date		*_date;
  double	_balance;
public:
  Record();
  Record(Date*, double);
  
  Date		*getDate() const;
  double	getBalance() const;
  void		setDate(Date *);
  void		setBalance(double);
  void		dump() const;
  virtual ~Record();
};

#endif		/* _RECORD_HPP_ */
