
#include "./exercise1a/test.hpp"
#include "./exercise1b/test.hpp"

/* ************************************************************************** */

#include <iostream>

using namespace std;

/* ************************************************************************** */

void mytest() {
  cout << endl << "~*~#~*~ Welcome to the LASD Test My Suite Paolo Tedesco~*~#~*~ " << endl;

  unsigned int loctestnum, loctesterr;
  unsigned int stestnum = 0, stesterr = 0;

  loctestnum = 0; loctesterr = 0;
  testSimpleExercise1AMy(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  loctestnum = 0; loctesterr = 0;
  testSimpleExercise1BMy(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  cout << endl << "Exercise 1 (Errors/Tests: " << stesterr << "/" << stestnum << ")";
  cout << endl << "Goodbye!" << endl;
}
