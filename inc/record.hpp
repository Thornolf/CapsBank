#ifndef		_RECORD_HPP_
# define	_RECORD_HPP_

#include	"date.hpp"

class Record {
private:
  Date		*_date;
  float		_balance;
public:
  Record();
  Record(Date*, float);
  
  Date		*getDate() const;
  float		getBalance() const;
  void		setDate(Date *);
  void		setBalance(float);
  void		dump() const;
  virtual ~Record();
};

#endif		/* _RECORD_HPP_ */
