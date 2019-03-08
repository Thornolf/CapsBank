#include	<iostream>
#include	<fstream>

#include	"date.hpp"
#include	"account.hpp"
#include	"children.hpp"
#include	"bank.hpp"

int	main(int argc, char **argv) {
  (void)argc;
  (void)argv;
  Bank *b = new Bank("banque.csv");
  for (auto i : b->getClients()) {
    if (i->getId() == 2102)
      i->dump();
  }
  b->save("banque.csv");
  return (0);
}
