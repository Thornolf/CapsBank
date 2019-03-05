#ifndef				_BANK_HPP_
# define			_BANK_HPP_

#include			<vector>

#include			"account.hpp"

class				Bank {
private:
  std::vector<Account*>		_clients;
  std::string			_databaseLocation;
public:
  Bank(std::string);
  Bank(std::vector<Account*>, std::string);
  void				setClients(std::vector<Account*>);
  void				setDatabaseLocation(std::string);
  std::vector<Account*>		getClients(void) const;
  std::string			getDatabaseLocation(void) const;
  
  std::vector<std::string>	createClient(std::string);
  void				addClient(Account *);
  void				save(std::string);
  void				load(std::string);
  virtual ~Bank();
};

#endif				/* _BANK_HPP_ */
