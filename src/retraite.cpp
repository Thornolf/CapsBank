#include	"retraite.hpp"

Retraite::Retraite() {
  
}

Retraite::Retraite(int id, Date *date, std::string lastname, std::string firstname, float balance) : Account(id, date, lastname, firstname, balance) {
  
}

float		Retraite::withdraw(float amount) {
  return (amount);
}

bool		Retraite::authorization(float amount) {
  return (true);
}

Retraite::~Retraite() {}
