#ifndef		_ACCOUNT_HPP_
# define	_ACCOUNT_HPP_

class		Account {
private:
  int		_id;
  Date		*_birthdate;
  std::string	_name;
  int		_balance;
  
public:
  Account();
  int		getId() const;
  Date		*getBirthdate() const;
  std::string	getName() const;
  int		getBalance() const;

  void		setId(int);
  void		setBirthdate(Date*);
  void		setName(std::string);
  void		setBalance(int);
  
  void		addToBalance(int);
  void		removeFromBalance(int);
  virtual ~Account();
};

#endif		/* _ACCOUNT_HPP_ */
