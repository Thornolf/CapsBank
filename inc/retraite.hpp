#ifndef		_RETRAITE_HPP_
# define	_RETRAITE_HPP_

#include	<string>

#include	"account.hpp"

class		Retraite : public Account {
public:
  Retraite();
  Retraite(int, Date *, std::string, std::string, double, e_type, std::list<Record*>);
  double	withdraw(double);
  bool		authorization(double);
  virtual ~Retraite();
};

#endif          /* _RETRAITE_HPP_ */
