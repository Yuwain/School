/******************************************************************************
    Written by:     Jeremy High
    Student ID:     103306452
    Written on:     January 28th, 2014

    This program reads in strings from stdin until there is an error and
    then uses bubble sort to sort them
******************************************************************************/
#include <list>
#include <iostream>
#include <iterator>

using namespace std;

template <typename FwdIter>
void bubbleSort(FwdIter first, FwdIter last);

int main() {
  string word;
  list<decltype(word)> words;

  while (cin >> word) {
    words.push_back(word);
  }

  bubbleSort(begin(words), end(words));

  for (auto elem: words) {
    cout << elem << endl;
  }

  return 0;
}

/********************************************************
  Bubble sorts a bunch of strings

  First 	- The first element in the list
  Last 	- The position one past the end of the list
********************************************************/
template <typename FwdIter>
void bubbleSort(FwdIter first, FwdIter last) {
  bool sorted = false;
  FwdIter temp = next(first);

  while (!sorted) {
    sorted = true;

    for (auto i = first; temp != last; ++i) {
      if (*i > *temp) {
        iter_swap(i, temp);
        sorted = false;
      }

      ++temp;
    }

    temp = next(first);
  }
}
