#ifndef		_RETRAITE_HPP_
# define	_RETRAITE_HPP_

#include	<string>

#include	"account.hpp"
#include	"authorisation.hpp"

class		Retraite : public Account {
private:
  Authorisation	*_authorisation;
public:
  Retraite();
  Retraite(int, Date *, std::string, std::string, double, e_type);
  Retraite(int, Date *, std::string, std::string, double, e_type, std::list<Record*>);
  double	withdraw(double);
  bool		authorization(double);
  virtual ~Retraite();
};

#endif          /* _RETRAITE_HPP_ */
