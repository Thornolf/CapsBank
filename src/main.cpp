#include	<iostream>

#include	"date.hpp"
#include	"account.hpp"
#include	"children.hpp"

int	main(int argc, char **argv) {
  (void)argc;
  (void)argv;
  Account *p = new Account(1, new Date(1990, 1, 1), "Tartouffe", "Michou", 999);
  Children *c = new Children(2, new Date(2019,12,22), "Desjardin", "Jean", 77, p);
  c->withdraw(9);
  std::cout << "Monthly withdraw : " << c->getMonthlyWithdraw();
  std::cout << " Daily withdraw : " << c->getDailyWithdraw() << std::endl;
  c->setDailyWithdraw(0);
  c->withdraw(4);
  std::cout << "Monthly withdraw : " << c->getMonthlyWithdraw();
  std::cout << " Daily withdraw : " << c->getDailyWithdraw() << std::endl;
  c->withdraw(6);
  std::cout << "Monthly withdraw : " << c->getMonthlyWithdraw();
  std::cout << " Daily withdraw : " << c->getDailyWithdraw() << std::endl;
  return (0);
}
