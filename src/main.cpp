#include	<iostream>
#include	<fstream>
#include	<map>

#include	"date.hpp"
#include	"account.hpp"
#include	"children.hpp"
#include	"bank.hpp"

void DoOne(std::string s) { std::cout << s << std::endl; }
void DoTwo(std::string s) { std::cout << s << std::endl; }
void DoNil(std::string s) { std::cout << s << std::endl; }

int	main(int argc, char **argv) {
  (void)argc;
  (void)argv;
  Bank *b = new Bank("banque.csv");
  (void)b;  

  typedef void (*DoIt)(std::string);
  typedef std::map<std::string, DoIt> MapCall;
  MapCall	doit;
  doit.insert(MapCall::value_type("One",DoOne));
  doit.insert(MapCall::value_type("Two",DoTwo));
  doit.insert(MapCall::value_type("Nil",DoOne));
  
  std::string cmd;
  std::cout << "> ";
  while (cmd != "exit" && cmd != "quit") {
    std::getline(std::cin, cmd);
    
    MapCall::const_iterator call;
    call = doit.find(cmd);
    std::cout << "Prompt de call = " << call << std::endl;
    if (call != doit.end()) {
      (*call).second(cmd);
    }
    else {
      std::cout << "Unknown call requested" << std::endl;
    }
    std::cout << "> ";
  }
  return (0);
}
