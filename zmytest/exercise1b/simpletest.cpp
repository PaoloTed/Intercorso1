
#include <iostream>

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"

#include "../stack/stack.hpp"
#include "../../stack/vec/stackvec.hpp"
#include "../../stack/lst/stacklst.hpp"

#include "../queue/queue.hpp"
#include "../../queue/vec/queuevec.hpp"
#include "../../queue/lst/queuelst.hpp"


/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

template <typename Stk>
void stestStackIntMy(Stk & stk, unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  try {
    Empty(loctestnum, loctesterr, stk, true);
    Size(loctestnum, loctesterr, stk, true, 0);

    Top(loctestnum, loctesterr, stk, false, 0);
    TopNPop(loctestnum, loctesterr, stk, false, 0);

    PushC(loctestnum, loctesterr, stk, 4);
    PushC(loctestnum, loctesterr, stk, 0);
    PushC(loctestnum, loctesterr, stk, 3);
    PushC(loctestnum, loctesterr, stk, 1);
    PushC(loctestnum, loctesterr, stk, 2);
    PushC(loctestnum, loctesterr, stk, 6);
    PushC(loctestnum, loctesterr, stk, 7);

    Empty(loctestnum, loctesterr, stk, false);
    Size(loctestnum, loctesterr, stk, true, 7);

    TopNPop(loctestnum, loctesterr, stk, true, 7);
    Top(loctestnum, loctesterr, stk, true, 6);
    Top(loctestnum, loctesterr, (const Stk) stk, true, 6);

    Stk copstk(stk);
    EqualStack(loctestnum, loctesterr, stk, copstk, true);
    PushC(loctestnum, loctesterr, stk, 8);
    NonEqualStack(loctestnum, loctesterr, stk, copstk, true);

    Stk diffstk;
    PushC(loctestnum, loctesterr, diffstk, 10);
    NonEqualStack(loctestnum, loctesterr, stk, diffstk, true);

    copstk = stk;
    EqualStack(loctestnum, loctesterr, stk, copstk, true);
    PushC(loctestnum, loctesterr, copstk, 9);
    NonEqualStack(loctestnum, loctesterr, stk, copstk, true);

  }
  catch (...) {

  }
  testnum += loctestnum;
  testerr += loctesterr;
  cout << "End of Stack<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}
void stestStackIntMy(unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  lasd::StackVec<int> stkvec;
  cout << endl << "Begin of StackVec<int> Test:" << endl;
  stestStackIntMy(stkvec, loctestnum, loctesterr);
  lasd::StackLst<int> stklst;
  cout << endl << "Begin of StackLst<int> Test:" << endl;
  stestStackIntMy(stklst, loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
}

template <typename Stk>
void stestStackFloatMy(Stk & stk, unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  try {
    PushC(loctestnum, loctesterr, stk, 7.1);
    PushC(loctestnum, loctesterr, stk, 3.3);
    PushC(loctestnum, loctesterr, stk, 8.8);
    PushC(loctestnum, loctesterr, stk, 2.2);
    PushC(loctestnum, loctesterr, stk, 6.6);

    Empty(loctestnum, loctesterr, stk, false);
    Size(loctestnum, loctesterr, stk, true, 5);

    TopNPop(loctestnum, loctesterr, stk, true, 6.6);
    Top(loctestnum, loctesterr, stk, true, 2.2);
    Pop(loctestnum, loctesterr, stk, true);
    TopNPop(loctestnum, loctesterr, stk, true, 8.8);
    Pop(loctestnum, loctesterr, stk, true);
    TopNPop(loctestnum, loctesterr, stk, true, 3.3);
    Pop(loctestnum, loctesterr, stk, true);
    TopNPop(loctestnum, loctesterr, stk, true, 7.1);
    Pop(loctestnum, loctesterr, stk, false);
  }
  catch (...) {

  }
  testnum += loctestnum;
  testerr += loctesterr;
  cout << "End of Stack<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}
void stestStackFloatMy(unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  lasd::StackVec<double> stkvec;
  cout << endl << "Begin of StackVec<double> Test:" << endl;
  stestStackFloatMy(stkvec, loctestnum, loctesterr);
  lasd::StackLst<double> stklst;
  cout << endl << "Begin of StackLst<double> Test:" << endl;
  stestStackFloatMy(stklst, loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
}

template <typename Stk>
void stestStackStringMy(Stk & stk, unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  try {
    PushM(loctestnum, loctesterr, stk, string("A"));
    PushM(loctestnum, loctesterr, stk, string("B"));

    Empty(loctestnum, loctesterr, stk, false);
    Size(loctestnum, loctesterr, stk, true, 2);

    TopNPop(loctestnum, loctesterr, stk, true, string("B"));
    Top(loctestnum, loctesterr, stk, true, string("A"));
    Pop(loctestnum, loctesterr, stk, true);
    Pop(loctestnum, loctesterr, stk, false);
  }
  catch (...) {

  }
  testnum += loctestnum;
  testerr += loctesterr;
  cout << "End of Stack<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}
void stestStackStringMy(unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  lasd::StackVec<string> stkvec;
  cout << endl << "Begin of StackVec<string> Test:" << endl;
  stestStackStringMy(stkvec, loctestnum, loctesterr);
  lasd::StackLst<string> stklst;
  cout << endl << "Begin of StackLst<string> Test:" << endl;
  stestStackStringMy(stklst, loctestnum, loctesterr);
  cout << endl;
  try {
    lasd::Vector<string> vec(3);
    SetAt(loctestnum, loctesterr, vec, true, 0, string("X"));
    SetAt(loctestnum, loctesterr, vec, true, 1, string("Y"));
    SetAt(loctestnum, loctesterr, vec, true, 2, string("Z"));

    PushM(loctestnum, loctesterr, stkvec, string("X"));
    PushM(loctestnum, loctesterr, stkvec, string("Y"));
    PushM(loctestnum, loctesterr, stkvec, string("Z"));
    lasd::StackVec<string> newstkvec(vec);
    EqualStack(loctestnum, loctesterr, stkvec, newstkvec, true);

    PushM(loctestnum, loctesterr, stklst, string("Z"));
    PushM(loctestnum, loctesterr, stklst, string("Y"));
    PushM(loctestnum, loctesterr, stklst, string("X"));
    lasd::StackLst<string> newstklst(vec);
    EqualStack(loctestnum, loctesterr, stklst, newstklst, true);
  }
  catch (...) {

  }
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestStackMy(unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  stestStackIntMy(loctestnum, loctesterr);
  stestStackFloatMy(loctestnum, loctesterr);
  stestStackStringMy(loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
  cout << endl << "Exercise 1B - Stack (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}

/* ************************************************************************** */

template <typename Que>
void stestQueueIntMy(Que & que, unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  try {
    Empty(loctestnum, loctesterr, que, true);
    Size(loctestnum, loctesterr, que, true, 0);

    Head(loctestnum, loctesterr, que, false, 0);
    HeadNDequeue(loctestnum, loctesterr, que, false, 0);

    EnqueueC(loctestnum, loctesterr, que, 7);
    EnqueueC(loctestnum, loctesterr, que, 2);
    EnqueueC(loctestnum, loctesterr, que, 6);
    EnqueueC(loctestnum, loctesterr, que, 3);
    EnqueueC(loctestnum, loctesterr, que, 5);

    Empty(loctestnum, loctesterr, que, false);
    Size(loctestnum, loctesterr, que, true, 5);

    HeadNDequeue(loctestnum, loctesterr, que, true, 5);
    Head(loctestnum, loctesterr, que, true, 3);
    Dequeue(loctestnum, loctesterr, que, true);
    HeadNDequeue(loctestnum, loctesterr, que, true, 6);
    Dequeue(loctestnum, loctesterr, que, true);
    HeadNDequeue(loctestnum, loctesterr, que, true, 2);
    Dequeue(loctestnum, loctesterr, que, true);
    HeadNDequeue(loctestnum, loctesterr, que, true, 7);
    Dequeue(loctestnum, loctesterr, que, false);


  }
  catch (...) {

  }
  testnum += loctestnum;
  testerr += loctesterr;
  cout << "End of Queue<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}
void stestQueueIntMy(unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  lasd::QueueVec<int> quevec;
  cout << endl << "Begin of QueueVec<int> Test:" << endl;
  stestQueueIntMy(quevec, loctestnum, loctesterr);
  lasd::QueueLst<int> quelst;
  cout << endl << "Begin of QueueLst<int> Test:" << endl;
  stestQueueIntMy(quelst, loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
}

template <typename Que>
void stestQueueFloatMy(Que & que, unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  try {
    EnqueueC(loctestnum, loctesterr, que, 7.1);
    EnqueueC(loctestnum, loctesterr, que, 3.3);
    EnqueueC(loctestnum, loctesterr, que, 8.8);
    EnqueueC(loctestnum, loctesterr, que, 2.2);
    EnqueueC(loctestnum, loctesterr, que, 6.6);

    Empty(loctestnum, loctesterr, que, false);
    Size(loctestnum, loctesterr, que, true, 5);

    HeadNDequeue(loctestnum, loctesterr, que, true, 6.6);
    Head(loctestnum, loctesterr, que, true, 2.2);
    Dequeue(loctestnum, loctesterr, que, true);
    HeadNDequeue(loctestnum, loctesterr, que, true, 8.8);
    Dequeue(loctestnum, loctesterr, que, true);
    HeadNDequeue(loctestnum, loctesterr, que, true, 3.3);
    Dequeue(loctestnum, loctesterr, que, true);
    HeadNDequeue(loctestnum, loctesterr, que, true, 7.1);
    Dequeue(loctestnum, loctesterr, que, false);
  }
  catch (...) {

  }
  testnum += loctestnum;
  testerr += loctesterr;
  cout << "End of Queue<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}
void stestQueueFloatMy(unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  lasd::QueueVec<double> quevec;
  cout << endl << "Begin of QueueVec<double> Test:" << endl;
  stestQueueFloatMy(quevec, loctestnum, loctesterr);
  lasd::QueueLst<double> quelst;
  cout << endl << "Begin of QueueLst<double> Test:" << endl;
  stestQueueFloatMy(quelst, loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
}

template <typename Que>
void stestQueueStringMy(Que & que, unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  try {
    EnqueueM(loctestnum, loctesterr, que, string("X"));
    EnqueueM(loctestnum, loctesterr, que, string("Y"));
    EnqueueM(loctestnum, loctesterr, que, string("Z"));

    Empty(loctestnum, loctesterr, que, false);
    Size(loctestnum, loctesterr, que, true, 3);

    HeadNDequeue(loctestnum, loctesterr, que, true, string("Z"));
    Head(loctestnum, loctesterr, que, true, string("Y"));
    Dequeue(loctestnum, loctesterr, que, true);
    HeadNDequeue(loctestnum, loctesterr, que, true, string("X"));
    Dequeue(loctestnum, loctesterr, que, false);
  }
  catch (...) {

  }
  testnum += loctestnum;
  testerr += loctesterr;
  cout << "End of Queue<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}
void stestQueueStringMy(unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  lasd::QueueVec<string> quevec;
  cout << endl << "Begin of QueueVec<string> Test:" << endl;
  stestQueueStringMy(quevec, loctestnum, loctesterr);
  lasd::QueueLst<string> quelst;
  cout << endl << "Begin of QueueLst<string> Test:" << endl;
  stestQueueStringMy(quelst, loctestnum, loctesterr);
  cout << endl;
  try {
    lasd::Vector<string> vec(2);
    SetAt(loctestnum, loctesterr, vec, true, 0, string("A"));
    SetAt(loctestnum, loctesterr, vec, true, 1, string("B"));

    EnqueueM(loctestnum, loctesterr, quevec, string("A"));
    EnqueueM(loctestnum, loctesterr, quevec, string("B"));
    lasd::QueueVec<string> newquevec(vec);
    EqualQueue(loctestnum, loctesterr, quevec, newquevec, true);
    EnqueueM(loctestnum, loctesterr, quelst, string("A"));
    EnqueueM(loctestnum, loctesterr, quelst, string("B"));
    lasd::QueueLst<string> newquelst(vec);
    EqualQueue(loctestnum, loctesterr, quelst, newquelst, true);
  }
  catch (...) {

  }
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestQueueMy(unsigned int & testnum, unsigned int & testerr) {
  unsigned int loctestnum = 0, loctesterr = 0;
  stestQueueIntMy(loctestnum, loctesterr);
  stestQueueFloatMy(loctestnum, loctesterr);
  stestQueueStringMy(loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
  cout << endl << "Exercise 1B - Queue (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}

/* ************************************************************************** */

void testSimpleExercise1BMy(unsigned int & testnum, unsigned int & testerr) {
  stestStackMy(testnum, testerr);
  stestQueueMy(testnum, testerr);
  cout << endl << "Exercise 1B (Simple Test) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}

/* ************************************************************************** */