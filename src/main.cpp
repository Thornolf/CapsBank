#include <iostream>

#include "date.hpp"
#include "account.hpp"

int	main(int argc, char **argv) {
  (void)argc;
  (void)argv;
  Account *a = new Account(1, new Date(1996,7,1), "Menethil", "Arthas", 999);
  a->dump();
  return (0);
}
