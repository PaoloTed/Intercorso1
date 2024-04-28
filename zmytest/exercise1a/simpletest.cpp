
#include <iostream>

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/dictionary.hpp"
#include "../container/traversable.hpp"
#include "../container/mappable.hpp"
#include "../container/linear.hpp"

#include "../vector/vector.hpp"

#include "../list/list.hpp"


/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

void stestVectorIntMy(unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Vector<int> Test:" << endl;
  try {
    {
      lasd::SortableVector<int> vec(3);
      Empty(loctestnum, loctesterr, vec, false);
      Size(loctestnum, loctesterr, vec, true, 3);

      SetAt(loctestnum, loctesterr, vec, true, 0, 7);
      SetAt(loctestnum, loctesterr, vec, true, 1, 8);
      SetAt(loctestnum, loctesterr, vec, true, 2, 9);

      GetFront(loctestnum, loctesterr, vec, true, 7);
      GetBack(loctestnum, loctesterr, vec, true, 9);

      Exists(loctestnum, loctesterr, vec, true, 8);

      FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 24);
      FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldMultiply<int>, 1, 504);

      vec.Sort();

      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

      vec.Resize(2);
      FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldMultiply<int>, 1, 56);
    }
    {
      lasd::SortableVector<int> vec ;
      Empty(loctestnum, loctesterr, vec, true);

      GetFront(loctestnum, loctesterr, vec, false, 0);
      GetBack(loctestnum, loctesterr, vec, false, 0);
      SetAt(loctestnum, loctesterr, vec, false, 1, 0);
      GetAt(loctestnum, loctesterr, vec, false, 2, 0);

      Exists(loctestnum, loctesterr, vec, false, 0);

      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

      FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 0);
      FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 0);
    }
  }
  catch (...) {

  }
  cout << "End of Vector<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestVectorDoubleMy(unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Vector<double> Test:" << endl;
  try {
    lasd::SortableVector<double> vec(3);
    Empty(loctestnum, loctesterr, vec, false);
    Size(loctestnum, loctesterr, vec, true, 3);

    SetAt(loctestnum, loctesterr, vec, true, 0, 7.7);
    SetAt(loctestnum, loctesterr, vec, true, 2, 1.1);
    SetAt(loctestnum, loctesterr, vec, true, 1, 5.5);

    GetFront(loctestnum, loctesterr, vec, true, 7.7);
    GetBack(loctestnum, loctesterr, vec, true, 5.5);

    Exists(loctestnum, loctesterr, vec, true, 1.1);

  }
  catch (...) {

  }
  cout << "End of Vector<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestVectorStringMy(unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Vector<string> Test:" << endl;
  try {
    lasd::SortableVector<string> vec(2);

    Empty(loctestnum, loctesterr, vec, false);
    Size(loctestnum, loctesterr, vec, true, 2);

    SetAt(loctestnum, loctesterr, vec, true, 1, string("Z"));
    SetAt(loctestnum, loctesterr, vec, true, 0, string("Y"));

    GetFront(loctestnum, loctesterr, vec, true, string("Y"));
    GetBack(loctestnum, loctesterr, vec, true, string("Z"));

    Exists(loctestnum, loctesterr, vec, true, string("Y"));

    lasd::SortableVector<string> copvec(vec);
    EqualVector(loctestnum, loctesterr, vec, copvec, true);

    Exists(loctestnum, loctesterr, vec, false, string("X"));

    MapPreOrder(loctestnum, loctesterr, vec, true, [](string & str) { MapStringAppend(str, string("!")); });
    NonEqualVector(loctestnum, loctesterr, vec, copvec, true);

    copvec = move(vec);
    FoldPreOrder(loctestnum, loctesterr, copvec, true, &FoldStringConcatenate, string("?"), string("?Y! Z!"));

    lasd::SortableVector<string> movvec(move(vec));
    movvec.Sort();
    FoldPreOrder(loctestnum, loctesterr, movvec, true, &FoldStringConcatenate, string("?"), string("?Y! Z!"));

    SetAt(loctestnum, loctesterr, vec, false, 0, string(""));
    vec.Resize(1);
    SetAt(loctestnum, loctesterr, vec, true, 0, string("W"));

    movvec.Clear();
    Empty(loctestnum, loctesterr, movvec, true);
  }
  catch (...) {

  }
  cout << "End of Vector<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestVectorMy(unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  stestVectorIntMy(loctestnum, loctesterr);
  stestVectorDoubleMy(loctestnum, loctesterr);
  stestVectorStringMy(loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
  cout << endl << "Exercise 1A - Vector (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}

/* ************************************************************************** */

void stestListIntMy(unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of List<int> Test:" << endl;
  try {
    lasd::List<int> lst;

    Empty(loctestnum, loctesterr, lst, true);
    Size(loctestnum, loctesterr, lst, true, 0);

    InsertAtBack(loctestnum, loctesterr, lst, true, 7);
    InsertAtFront(loctestnum, loctesterr, lst, true, 8);
    InsertAtFront(loctestnum, loctesterr, lst, true, 10);
    InsertAtBack(loctestnum, loctesterr, lst, true, 3);
    InsertAtFront(loctestnum, loctesterr, lst, true, 2);

    GetFront(loctestnum, loctesterr, lst, true, 2);
    GetBack(loctestnum, loctesterr, lst, true, 3);
    SetFront(loctestnum, loctesterr, lst, true, 3);
    SetBack(loctestnum, loctesterr, lst, true, 7);
    GetAt(loctestnum, loctesterr, lst, true, 3, 10);
    SetAt(loctestnum, loctesterr, lst, true, 3, 4);

    Exists(loctestnum, loctesterr, lst, false, 5);

    TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);
    FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldAdd<int>, 0, 32);
    FoldPostOrder(loctestnum, loctesterr, lst, true, &FoldMultiply<int>, 1, 5040);

    RemoveFromFront(loctestnum, loctesterr, lst, true);
    FrontNRemove(loctestnum, loctesterr, lst, true, 10);
    FoldPostOrder(loctestnum, loctesterr, lst, true, &FoldMultiply<int>, 1, 420);

    lasd::List<int> coplst(lst);
    EqualList(loctestnum, loctesterr, lst, coplst, true);
    MapPreOrder(loctestnum, loctesterr, lst, true, &MapIncrement<int>);
    NonEqualList(loctestnum, loctesterr, lst, coplst, true);

    InsertAtFront(loctestnum, loctesterr, lst, true, 1);
    InsertAtBack(loctestnum, loctesterr, lst, true, 1);
    NonEqualList(loctestnum, loctesterr, lst, coplst, true);
    coplst = lst;
    EqualList(loctestnum, loctesterr, lst, coplst, true);

    RemoveFromFront(loctestnum, loctesterr, coplst, true);
    FrontNRemove(loctestnum, loctesterr, coplst, true, 7);
    coplst = move(lst);

    FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldAdd<int>, 0, 12);
    FoldPreOrder(loctestnum, loctesterr, coplst, true, &FoldAdd<int>, 0, 18);

    lasd::List<int> movlst(move(lst));
    MapPreOrder(loctestnum, loctesterr, movlst, true, &MapIncrement<int>);
    FoldPreOrder(loctestnum, loctesterr, movlst, true, &FoldAdd<int>, 0, 15);

    InsertC(loctestnum, loctesterr, movlst, true, 7);
    InsertC(loctestnum, loctesterr, movlst, false, 9);
    Remove(loctestnum, loctesterr, movlst, true, 7);
    InsertC(loctestnum, loctesterr, movlst, true, 8);
    FoldPreOrder(loctestnum, loctesterr, movlst, true, &FoldAdd<int>, 1, 23);

    movlst.Clear();
    Empty(loctestnum, loctesterr, movlst, true);
    Size(loctestnum, loctesterr, movlst, true, 0);
  }
  catch (...) {

  }
  cout << "End of List<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestListDoubleMy(unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Modified List<double> Test:" << endl;
  try {
    lasd::List<double> lst;

    // Inserting elements at the back and front
    InsertAtBack(loctestnum, loctesterr, lst, true, 3.5);
    InsertAtFront(loctestnum, loctesterr, lst, true, 4.4);
    InsertAtBack(loctestnum, loctesterr, lst, true, 1.2);
    InsertAtFront(loctestnum, loctesterr, lst, true, 2.3);

    // Checking if the list is empty and its size
    Empty(loctestnum, loctesterr, lst, false);
    Size(loctestnum, loctesterr, lst, true, 4);

    // Getting front and back elements
    GetFront(loctestnum, loctesterr, lst, true, 2.3);
    GetBack(loctestnum, loctesterr, lst, true, 1.2);

    // Checking if a certain element exists
    Exists(loctestnum, loctesterr, lst, true, 4.4);

    // Traversing and folding operations
    TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);
    FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldAdd<double>, 0.0, 11.4);
    TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);
    FoldPostOrder(loctestnum, loctesterr, lst, true, &FoldMultiply<double>, 1.0, 36.36);

    // Clearing the list
    lst.Clear();
    Empty(loctestnum, loctesterr, lst, true);
    Size(loctestnum, loctesterr, lst, true, 0);
  }
  catch (...) {
    cout << "An exception occurred." << endl;
  }
  cout << "End of my List<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestListStringMy(unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Modified List<string> Test:" << endl;
  try {
    lasd::List<string> lst;

    // Inserting elements at the back and front
    InsertAtBack(loctestnum, loctesterr, lst, true, string("D"));
    InsertAtFront(loctestnum, loctesterr, lst, true, string("E"));
    InsertAtBack(loctestnum, loctesterr, lst, true, string("F"));
    InsertAtFront(loctestnum, loctesterr, lst, true, string("G"));

    // Checking if the list is empty and its size
    Empty(loctestnum, loctesterr, lst, false);
    Size(loctestnum, loctesterr, lst, true, 4);

    // Getting front and back elements
    GetFront(loctestnum, loctesterr, lst, true, string("G"));
    GetBack(loctestnum, loctesterr, lst, true, string("F"));

    // Checking if a certain element exists
    Exists(loctestnum, loctesterr, lst, true, string("E"));

    // Traversing and folding operations
    TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<string>);
    FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldStringConcatenate, string("X"), string("XGEDF"));
    TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<string>);
    FoldPostOrder(loctestnum, loctesterr, lst, true, &FoldStringConcatenate, string("X"), string("XFEDG"));

    // Clearing the list
    lst.Clear();
    Empty(loctestnum, loctesterr, lst, true);
    Size(loctestnum, loctesterr, lst, true, 0);
  }
  catch (...) {
    cout << "An exception occurred." << endl;
  }
  cout << "End of Modified List<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestListMy(unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  stestListIntMy(loctestnum, loctesterr);
  stestListDoubleMy(loctestnum, loctesterr);
  stestListStringMy(loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
  cout << endl << "Exercise 1A - List (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}

/* ************************************************************************** */

void stestVectorListIntMy(unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Vector/List<int> Test:" << endl;
  try {
    lasd::SortableVector<int> vec(3);
    SetAt(loctestnum, loctesterr, vec, true, 1, -1);
    SetAt(loctestnum, loctesterr, vec, true, 0, 0);
    SetAt(loctestnum, loctesterr, vec, true, 2, 1);

    lasd::List<int> lst;
    InsertAtFront(loctestnum, loctesterr, lst, true, 0);
    InsertAtFront(loctestnum, loctesterr, lst, true, 1);
    InsertAtFront(loctestnum, loctesterr, lst, true, -1);

    EqualLinear(loctestnum, loctesterr, vec, lst, true);

    lasd::SortableVector<int> copvec(lst);
    EqualVector(loctestnum, loctesterr, vec, copvec, true);

    lasd::SortableVector<int> copvecx(vec);
    EqualVector(loctestnum, loctesterr, copvecx, copvec, true);

    lasd::List<int> coplst(vec);
    EqualList(loctestnum, loctesterr, lst, coplst, true);
    lasd::List<int> coplstx(lst);
    EqualList(loctestnum, loctesterr, coplstx, coplst, true);
  }
  catch (...) {

  }
  cout << "End of Vector/List<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestVectorListDoubleMy(unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Vector/List<double> Test:" << endl;
  try {
    lasd::SortableVector<double> vec(4);
    SetAt(loctestnum, loctesterr, vec, true, 2, -1.5);
    SetAt(loctestnum, loctesterr, vec, true, 0, 1.0);
    SetAt(loctestnum, loctesterr, vec, true, 3, 0.5);
    SetAt(loctestnum, loctesterr, vec, true, 1, 2.0);

    lasd::List<double> lst;
    InsertAtFront(loctestnum, loctesterr, lst, true, 1.0);
    InsertAtBack(loctestnum, loctesterr, lst, true, -1.5);
    InsertAtFront(loctestnum, loctesterr, lst, true, 2.0);
    InsertAtBack(loctestnum, loctesterr, lst, true, 0.5);

    EqualLinear(loctestnum, loctesterr, vec, lst, true);

    lasd::SortableVector<double> copvec(lst);
    EqualVector(loctestnum, loctesterr, vec, copvec, true);

    lasd::SortableVector<double> copvecx(vec);
    EqualVector(loctestnum, loctesterr, copvecx, copvec, true);

    lasd::List<double> coplst(vec);
    EqualList(loctestnum, loctesterr, lst, coplst, true);

    lasd::List<double> coplstx(lst);
    EqualList(loctestnum, loctesterr, coplstx, coplst, true);
  }
  catch (...) {

  }
  cout << "End of Vector/List<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestVectorListStringMy(unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Vector/List<string> Test:" << endl;
  try {
    lasd::SortableVector<string> vec(3);
    SetAt(loctestnum, loctesterr, vec, true, 1, string("X"));
    SetAt(loctestnum, loctesterr, vec, true, 0, string("Y"));
    SetAt(loctestnum, loctesterr, vec, true, 2, string("Z"));

    lasd::List<string> lst;
    InsertAtFront(loctestnum, loctesterr, lst, true, string("Y"));
    InsertAtBack(loctestnum, loctesterr, lst, true, string("Z"));
    InsertAtFront(loctestnum, loctesterr, lst, true, string("X"));

    EqualLinear(loctestnum, loctesterr, vec, lst, true);

    lasd::SortableVector<string> copvec(lst);
    EqualVector(loctestnum, loctesterr, vec, copvec, true);
    lasd::SortableVector<string> copvecx(vec);
    EqualVector(loctestnum, loctesterr, copvecx, copvec, true);

    lasd::List<string> coplst(vec);
    EqualList(loctestnum, loctesterr, lst, coplst, true);
    lasd::List<string> coplstx(lst);
    EqualList(loctestnum, loctesterr, coplstx, coplst, true);

    lasd::List<string> coplsty(move(vec));
    EqualList(loctestnum, loctesterr, coplst, coplsty, true);
    EqualVector(loctestnum, loctesterr, vec, copvec, false);

    lasd::SortableVector<string> copvecy(move(lst));
    EqualVector(loctestnum, loctesterr, copvec, copvecy, true);
    EqualList(loctestnum, loctesterr, lst, coplst, false);
  }
  catch (...) {

  }
  cout << "End of Vector/List<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestVectorListMy(unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  stestVectorListIntMy(loctestnum, loctesterr);
  stestVectorListDoubleMy(loctestnum, loctesterr);
  stestVectorListStringMy(loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
  cout << endl << "Exercise 1A - Vector/List (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}

/* ************************************************************************** */

void testSimpleExercise1AMy(unsigned int & testnum, unsigned int & testerr) {
  stestVectorMy(testnum, testerr);
  stestListMy(testnum, testerr);
  stestVectorListMy(testnum, testerr);
  cout << endl << "Exercise 1A (Simple Test) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}
