#ifndef				_BANK_HPP_
# define			_BANK_HPP_

#include			<vector>

#include			"account.hpp"
#include			"children.hpp"
#include			"retraite.hpp"

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

  int				nonUsedId(std::vector<Account *>);
  bool				validId(std::string);
  std::vector<std::string>	createClient(std::string);
  template <typename T>
  void				addClient(T const &);
  void				dynamicallyCreateClient(Date *, std::string, std::string, e_type, int);
  void				showAll(void);
  void				showSpecific(int);
  void				save(std::string);
  void				load(std::string);
  void				dump() const;
  bool				isDigit(const std::string &) const;
  virtual ~Bank();
};

#endif				/* _BANK_HPP_ */
