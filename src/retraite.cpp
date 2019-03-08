#include	"retraite.hpp"

Retraite::Retraite() {
  
}

Retraite::Retraite(int id, Date *date, std::string lastname, std::string firstname, double balance, e_type type, std::list<Record*> history) : Account(id, date, lastname, firstname, balance, type, history) {
  
}

double		Retraite::withdraw(double amount) {
  return (amount);
}

bool		Retraite::authorization(double amount) {
  (void)amount;
  return (true);
}

Retraite::~Retraite() {}
