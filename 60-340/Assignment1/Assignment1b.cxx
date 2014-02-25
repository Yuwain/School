/******************************************************************************
    Written by:     Jeremy High
    Student ID:     103306452
    Written on:     January 28th, 2014

    This program reads a bunch of strings from stdin until an error occurs
    and then uses quicksort to sort them
******************************************************************************/
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

template <typename BidIter>
void quickSort(BidIter first, BidIter last);

template <typename BidIter>
BidIter middle(BidIter first, BidIter last);

int main() {
  string word;
  list<decltype(word)> words;

  while (cin >> word) {
    words.push_back(word);
  }

  quickSort(begin(words), end(words));

  for (auto elem : words) {
    cout << elem << endl;
  }

  return 0;
}

/********************************************************************
	Performs in-place quick sort on a list of strings

	First	- The first element in the range to be sorted
	Last 	- One after the final element in the range to be sorted
********************************************************************/
template <typename BidIter>
void quickSort(BidIter first, BidIter last) {
  if (first == last || next(first) == last) {
    return;
  }

  BidIter pivot = middle(first, last);

  iter_swap(first, pivot);

  auto split = partition(
      next(first), last,
      [first](typename BidIter::value_type const& value) { return value < *first; } 
  );

  iter_swap(first, prev(split));

  quickSort(first, prev(split));
  quickSort(split, last);

  return;
}

/********************************************************************
	Finds the middle element in a range of elements

	First	- The first element in the range
	Last	- One past the final element in the range
********************************************************************/
template <typename BidIter>
BidIter middle(BidIter first, BidIter last) {
  BidIter mid = first;

  while (first != last && next(first) != last) {
    advance(first, 2);

    if (first == last) {
      break;
    }

    ++mid;
  }

  return mid;
}
