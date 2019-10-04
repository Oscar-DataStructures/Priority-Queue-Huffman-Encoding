/*
Austin B, Oscar M
CS 271
Dr. Lall
Project 4
*/

#include <sstream>
#include <string>
#include <typeinfo>


using namespace std;


// ============================= Heap Constructor ==============================
template <class KeyType>
minHeap<KeyType>::minHeap(int n)
// PreConditions: n must be a postive int
// PostConditions: Create empty minHeap object


{
  heapSize = 0;
  capacity = n;
  A = new KeyType*[n];  //dynamically allocated array
}


// ======================== Heap From Array Constructor ========================
template <class KeyType>
minHeap<KeyType>::minHeap(KeyType*initA[], int n)
// PreConditions:initA must be a array, int n must be a postive int
// PostConditions: Create minHeap object from array initA


{
  A = new KeyType*[n];  //dynamically allocated array
  heapSize = n;
  for(int i = 0; i < n; i++)
  {
    *(A+i) = *(initA+i);  //uses pointerse to get elements of array
  }
  capacity = heapSize;
  buildHeap();

}


// =========================== Heap Copy Constructor ============================
template <class KeyType>
minHeap<KeyType>::minHeap(const minHeap<KeyType>& heap)
// PreConditions: heap must be existing minHeap object
// PostConditions: Copys existing heap onto consucted minHeap


{
  copy(heap);
}


// ============================== Heap Destructor ==============================
template <class KeyType>
minHeap<KeyType>::~minHeap()
// PreConditions: N/A
// PostConditions: minHeap object is deallocated


{
  destroy();
}


// ============================= Heap Sort Method ==============================
template <class KeyType>
void minHeap<KeyType>::heapSort(KeyType*sorted[])
// PreConditions: sorted must be an array
// PostConditions: returns sorted array in sorted parameter


{
  int sizeHolder = heapSize;
  int iterator = 0;

  KeyType tmp[heapSize];

  for(int i = heapSize -1; i >= 0; i--)
  {
    swap(0, i);

    tmp[iterator] = A[i];
    heapSize--;

    heapify(0);

    iterator++;
  }

  for(int i = 0; i < sizeHolder; i++)
  {
    sorted[i] = tmp[i];
  }
}


// ============================= To String Method ==============================
template <class KeyType>
std::string minHeap<KeyType>::toString() const
// PreConditions: N/A
// PostConditions: will produce a visual representation of the heap as an array


{
  std::stringstream ss;
  ss << "[";

  for (int i = 0; i < heapSize; i++)
  {
      ss << *(A[i]);
      if(i != heapSize-1) //takes care of last character not being a ","
        ss << ", ";
  }

  ss << "]";

  return ss.str();
}


// ======================== Assignment Operator Method =========================
template <class KeyType>
minHeap<KeyType>& minHeap<KeyType>::operator=(const minHeap<KeyType>& heap)
// PreConditions: heap and the minHeap object must be same type
// PostConditions: minHeap object will be the same as heap


{
  if (&heap != this)  //if they are not the same
  {
    destroy();
		copy(heap);
	}

  return *this;
}


// ============================== Heapify Method ===============================
template <class KeyType>
void minHeap<KeyType>::heapify(int index)
// PreConditions: index must be a positive index in range
// PostConditions: heap will have min heap property


{
  int left = leftChild(index);
  int right = rightChild(index);
  int smallest = index;


  if(left < heapSize && *(A[left]) < *(A[index]))  //checks for child and element size
  {
      smallest = left;
  }


  if(right < heapSize && *(A[right]) < *(A[smallest])) //checks for child and element size
  {
      smallest = right;
  }

  if(smallest != index) //if min property is still not maintained
  {
      swap(index, smallest);
      heapify(smallest);
  }
}


// ============================= Build Heap Method =============================
template <class KeyType>
void minHeap<KeyType>::buildHeap()
// PreConditions: N/A
// PostConditions: heap with min heap property


{
  for (int i = ((heapSize/2)-1); i >= 0; i--)  //build heap downwards
  {
    heapify(i);
  }
}


// ================================ Swap Method ================================
template <class KeyType>
void minHeap<KeyType>::swap(int index1, int index2)
// PreConditions: index1 and index2 must be positive ints in range
// PostConditions: elements in the heap at index1 and index2 will be exchanged


{
  KeyType* tmp = A[index1];
  A[index1] = A[index2];
  A[index2] = tmp;
}


// ================================ Copy Method ================================
template <class KeyType>
void minHeap<KeyType>::copy(const minHeap<KeyType>& heap)
// PreConditions: heap must have the same type as minHeap object
// PostConditions: minHeap object will be a copy of heap


{
  A = new KeyType[heap.capacity]; //dynamically allocated array

  for (int i = 0; i < heap.heapSize; i++)
  {
    A[i] = heap.A[i];
  }

  capacity = heap.capacity; //assign new capacity to match array
  heapSize = heap.heapSize; //assign new heapSize to match heap
}


// ============================== Destroy Method ===============================
template <class KeyType>
void minHeap<KeyType>::destroy()
// PreConditions: N/A
// PostConditions: heap array will be deallocated


{
  delete []A; //gives error that its already delted
}
