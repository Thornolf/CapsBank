#ifndef		_RETRAITE_HPP_
# define	_RETRAITE_HPP_

#include	<string>

#include	"account.hp"

class		Retraite : public Account {
private:

public:
  Retraite();
  Retraite(int, Date *, std::string, std::string, float);
  float		withdraw(float);
  bool		authorization(float);
  virtual ~Retraite();
};

#endif          /* _RETRAITE_HPP_ */
