#include "date.hpp"

int	main(int argc, char **argv) {
  (void)argc;
  (void)argv;
  Date *d = new Date(1, 7, 1996);
  d->dump();
  return (0);
}
