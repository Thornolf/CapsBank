#ifndef			_ACCOUNT_HPP_
# define		_ACCOUNT_HPP_

#include		<string>
#include		<list>

#include		"date.hpp"
#include		"record.hpp"

enum			e_type {
			classic = 0,
			enfant = 1,
			retraite = 2,
};

class			Account {
private:
  int			_id;
  Date			*_birthdate;
  std::string		_firstname;
  std::string		_lastname;
  std::list<Record*>	_history;
  
protected:
  int			_balance;
  e_type		_accountType;
  
public:
  Account();
  Account(int, Date *, std::string, std::string, float, e_type, std::list<Record*>);
  int			getId() const;
  Date			*getBirthdate() const;
  std::string		getLastname() const;
  std::string		getFirstname() const;
  float			getBalance() const;
  std::list<Record*>	getHistory() const;
  e_type		getType() const;

  void			setId(int);
  void			setBirthdate(Date*);
  void			setLastname(std::string);
  void			setFirstname(std::string);
  void			setBalance(float);
  void			setHistory(std::list<Record*>);
  void			setType(e_type);
  
  void			addRecordToHistory(Record*);
  void			deposit(float);
  virtual float		withdraw(float);
  void			dump() const;
  virtual ~Account();
};

#endif			/* _ACCOUNT_HPP_ */
