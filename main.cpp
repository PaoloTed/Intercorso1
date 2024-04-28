
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
int scelta;
do{
  std::cout << "Lasd Libraries 2024" << std::endl;
  std::cout << "Scegliere i test da effettuare " << std::endl;
  std::cout << "1) Test Prod" << std::endl;
  std::cout << "2) Test My" << std::endl;
  std::cout << "3) Tutti" << std::endl;
  std::cout << "4) Exit" << std::endl;
  std::cin >> scelta;
  switch (scelta) {
    case 1:
      lasdtest();
      break;
    case 2:
      mytest();
      break;
    case 3:
      lasdtest();
      mytest();
      break;
    case 4:
      return 0;
    default:
      std::cout << "Scelta non valida" << std::endl;
      break;
  }

}while(scelta!=4);
}
