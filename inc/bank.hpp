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
  void			setClients(std::vector<Account>);
  std::vector<Account>	getClients();
  void			save(std::string);
  void			load(std::string);
  virtual ~Bank();
};

#endif			/* _BANK_HPP_ */
