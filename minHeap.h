
/*
Oscar Martinez
CS 271
Dr. Lall
Project 3
*/

#include <iostream>
#include <string>

int DEFAULT_SIZE = 10;

template <class KeyType>
class minHeap
{
	public:
		minHeap(int n = DEFAULT_SIZE); // default constructor
		minHeap(KeyType*initA[], int n); // construct heap from array
		minHeap(const minHeap<KeyType>& heap); // copy constructor
		~minHeap(); // destructor

		void heapSort(KeyType*sorted[]); // heapsort, return result in sorted
		std::string toString() const; // return string representation
		minHeap<KeyType>& operator=(const minHeap<KeyType>& heap); // assignment operator

	private:
		KeyType **A; // array containing the heap
		int heapSize; // size of the heap
		int capacity; // size of A

		void heapify(int index); // heapify subheap rooted at index
		void buildHeap(); // build heap

		int leftChild(int index) { return 2 * index + 1; } // return index of left child
		int rightChild(int index) { return 2 * index + 2; } // return index of right child
		int parent(int index) { return (index - 1) / 2; } // return index of parent

		void swap(int index1, int index2); // swap elements in A
		void copy(const minHeap<KeyType>& heap); // copy heap to this heap
		void destroy(); // deallocate heap
};

#include "minHeap.cpp"
