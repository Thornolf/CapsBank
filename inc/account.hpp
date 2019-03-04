#ifndef		_ACCOUNT_HPP_
# define	_ACCOUNT_HPP_

#include	<string>

#include	"date.hpp"
class		Account {
private:
  int		_id;
  Date		*_birthdate;
  std::string	_firstname;
  std::string	_lastname;
protected:
  int		_balance;
public:
  Account();
  Account(int, Date *, std::string, std::string, int);
  int		getId() const;
  Date		*getBirthdate() const;
  std::string	getLastname() const;
  std::string	getFirstname() const;
  int		getBalance() const;

  void		setId(int);
  void		setBirthdate(Date*);
  void		setLastname(std::string);
  void		setFirstname(std::string);
  void		setBalance(int);
  
  void		deposit(int);
  virtual int	withdraw(int);
  void		dump() const;
  virtual ~Account();
};

#endif		/* _ACCOUNT_HPP_ */
