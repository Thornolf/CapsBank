#ifndef			_BANK_HPP_
# define		_BANK_HPP_

#include		<vector>

#include		"account.hpp"

class			Bank {
private:
  std::vector<Account>	_clients;
  std::string		_databaseLocation;
public:
  Bank();
  Bank(std::vector<Account>, std::string);
  void			setClients(std::vector<Account>);
  void			setDatabaseLocation(std::string);
  std::vector<Account>	getClients(void) const;
  std::string		getDatabaseLocation(void) const;
  void			createClient(std::string);
  void			save(std::string);
  void			load(std::string);
  virtual ~Bank();
};

#endif			/* _BANK_HPP_ */
