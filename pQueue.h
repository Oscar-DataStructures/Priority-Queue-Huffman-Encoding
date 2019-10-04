/*
Austin B, Oscar M
CS 271
Dr. Lall
Project 4
*/

#include <iostream>
#include <string>
#include "minHeap.h"

template <class KeyType>
class MinPriorityQueue : public minHeap<KeyType>
{
  public:
  MinPriorityQueue(); // default constructor
  MinPriorityQueue(int n); // construct an empty MPQ with capacity n
  MinPriorityQueue(const MinPriorityQueue<KeyType>& pq); // copy constructor
  // Destructor inherited from minHeap<KeyType>


  KeyType* minimum() const; // return the minimum element
  KeyType* extractMin(); // delete the minimum element and return it

  void decreaseKey(int index, KeyType* key); // decrease the value of an element
  void insert(KeyType* key); // insert a new element

  bool empty() const; // return whether the MPQ is empty
  int length() const; // return the number of keys
  std::string toString() const; // return a string representation of the MPQ
  // Assignment operator inherited from minHeap<KeyType>
  // Specify that MPQ will be referring to the following members of minHeap<KeyType>.

  using minHeap<KeyType>::A;
  using minHeap<KeyType>::heapSize;
  using minHeap<KeyType>::capacity;
  using minHeap<KeyType>::parent;
  using minHeap<KeyType>::swap;
  using minHeap<KeyType>::heapify;

  /* The using statements are necessary to resolve ambiguity because
  these members do not refer to KeyType. Alternatively, you could
  use this->heapify(0) or minHeap<KeyType>::heapify(0).
  */
};

template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const MinPriorityQueue<KeyType>& pq);

class FullError { }; // MinPriorityQueue full exception
class EmptyError { }; // MinPriorityQueue empty exception
class KeyError { }; // MinPriorityQueue key exception

#include "pQueue.cpp"
