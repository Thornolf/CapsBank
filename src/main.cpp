#include	<iostream>

#include	"date.hpp"
#include	"account.hpp"
#include	"children.hpp"
#include	"bank.hpp"

int	main(int argc, char **argv) {
  (void)argc;
  (void)argv;
  Bank	*b = new Bank();
  b->load("banque.csv");
  /*
  Account *p = new Account(1, new Date(1990, 1, 1), "Tartouffe", "Michou", 999, e_type::classic);
  Children *c = new Children(2, new Date(2019,12,22), "Desjardin", "Jean", 77, p, e_type::enfant);
  c->addRecordToHistory(new Record(new Date(2019, 3, 4), 100.0));
  c->addRecordToHistory(new Record(new Date(2018, 8, 23), 202.84));
  c->addRecordToHistory(new Record(new Date(2017, 10, 19), 40.0));
  c->addRecordToHistory(new Record(new Date(2016, 1, 1), 23.23));
  c->dump();

  */
  return (0);
}
