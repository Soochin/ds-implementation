// MinHeap.hpp
//
// Author: Soochin Kang, Trevor Dinh
// Add authors if you are implementing this file
//
// Vesion1 Date: 6/17/2018
//
// Binary MinHeap Implementation
// Use additional STL containers and any headers from standard library if needed.
// This is an implementation with a vector, which means dynamic memory allocation is
// unnecessary unless you choose to implemnt with an array.
// Add any private member functions and variables if needed.
// DO NOT CHANGE semantics and headers of public member functions.


#ifndef MINHEAP_HPP
#define MINHEAP_HPP

#include <vector>
#include "MinHeapException.hpp"
#include "IteratorException.hpp"

#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <climits>

template <typename T>
class MinHeap {
	// Iterator definitions
public:
	class Iterator;
	class ConstIterator;

public:
	// default constructor
	MinHeap() noexcept = default;

	// constructor with int array and length
	MinHeap(T* arr, int length);

	// constructor with a vector
	MinHeap(const std::vector<T>& v);

	// destructor
	virtual ~MinHeap() noexcept = default;

	// copy constructor
	MinHeap(const MinHeap& mh);

	// move constructor
	MinHeap(MinHeap&& mh) noexcept;

	// copy assignment operator
	MinHeap& operator=(const MinHeap& mh);

	// move assignment operator
	MinHeap& operator=(MinHeap&& mh) noexcept;


	// returns minimum element from the heap, which will be the root of
	// the heap. Throws MinHeapException when the heap is empty.
	const T& getMin() const;


    // removes minimum element from the heap, which will be the root of
    // the heap. After the removal, reheapify the heap.
    void removeMin();


	// returns true if the heap has no values in it.
	// false otherwise.
	bool isEmpty() const;


	// add() adds an element to the heap. If the element is already in
	// the set, this function has no effect. This function always runs in
	// O(log n) time when there are n elements in the heap.
	void add(const T& element);


	// remove() removes an element in the heap. If the element does not exist
	// in the heap, this function will throw MinHeapException. This function 
	// always runs in O(log n) time when there are n elements in the heap.
	void remove(const int index);


	// contains() returns true if the given element is already in the heap,
	// false otherwise. This function always runs in O(log n) time when
	// there are n elements in the heap
	bool contains(const T& element) const;


	// size() returns the number of elements in the heap.
	unsigned int size() const noexcept;


	// height() returns the height of the minheap.
	// This function always runs in theta(log n) time when
	// there are n elements in the heap. 
	int height() const;

    //debugging function to visualize vector
    void print();

    //debugging function to verify heap
    bool is_heap();


    // iterator() creates a new Iterator over this heap. It will
    // initially be referring to the first (root / minimum) value
    // in the heap, unless the heap is empty, in which case it will considered
    // both "past start" and "past end."
    // The method of iteration is preorder traversal.
    Iterator iterator();


    // constIterator(). An iterator that cannot modify the heap.
    // Only the traversal is valid.
    ConstIterator constIterator() const;


public:
	// Public Iterator section

	class IteratorBase {
	public:
		// Initializes a newly-constructed IteratorBase to operate on
		// the given heap. It will initially be referring to the first
		// value in the heap (the root, minimum), unless the heap is empty,
		// in which case it will be considered to both "past start" and "past end."
		IteratorBase(const MinHeap& mh) noexcept;


		// moveToNext() moves this iterator forward to the next value in the
		// heap. If the iterator is referring to the last value, it moves
		// to the "past end" position. If it is already at the "past end"
		// position, and IteratorException will be thrown.
		void moveToNext();


		// moveToPrevious() moves this iterator backward to the previous
        // value in the heap.  If the iterator is referring to the first
        // value, it moves to the "past start" position.  If it is already
        // at the "past start" position, an IteratorException will be thrown.
        void moveToPrevious();


        // isPastStart() returns true if this iterator is in the "past
        // start" position, false otherwise.
		bool isPastStart() const noexcept;


		// isPastEnd() returns true if this iterator is in the "past end"
        // position, false otherwise.
		bool isPastEnd() const noexcept;

	protected:
		// this is to access the member variables and member functions.
		const MinHeap<T>& mh;
		int curIndex;
	};


	class ConstIterator : public IteratorBase {
		// Initializes a newly-constructed ConstIterator to operate on
        // the given heap. It will initially be referring to the first
        // value (root, minumum) in the heap, unless the heap is empty, in which case
        // it will be considered to be both "past start" and "past end".
		ConstIterator(const MinHeap& mh) noexcept;

		// value() returns the value that the iterator is currently
        // referring to.  If the iterator is in the "past start" or
        // "past end" positions, an IteratorException will be thrown.
		const T& value() const;
	};


	class Iterator : public IteratorBase
    {
    public:
        // Initializes a newly-constructed Iterator to operate on the
        // given heap.  It will initially be referring to the first
        // value (root, minimum) in the heap, unless the heap is empty, in which case
        // it will be considered to be both "past start" and "past end".
        Iterator(MinHeap& list) noexcept;


        // value() returns the value that the iterator is currently
        // referring to. If the iterator is in the "past start" or
        // "past end" positions, an IteratorException will be thrown.
        T& value() const;


        // insertBefore() inserts a new value into the heap before
        // the one to which the iterator currently refers. If the
        // iterator is in the "past start" position, an IteratorException
        // is thrown.
        void insertBefore(const T& value);


        // insertAfter() inserts a new value into the heap after
        // the one to which the iterator currently refers. If the
        // iterator is in the "past end" position, an IteratorException
        // is thrown.
        void insertAfter(const T& value);


        // remove() removes the value to which this iterator refers,
        // moving the iterator to refer to either the value after it
        // (if moveToNextAfterward is true) or before it (if
        // moveToNextAfterward is false). If the iterator is in the
        // "past start" or "past end" position, an IteratorException
        // is thrown.
        // After removing, heap should be maintained as a heap.
        void remove(bool moveToNextAfterward = true);
    };



private:
	// implement any private functions that may help implement minheap.

    //may consider throwing errors when no such parent
    //or left/right child exists

    //return the parent of the node at this particular index.
    int parent(const int index) const;

    //return the left child of the node at this particular index.
    int left(const int index) const;

    //return the right child of the node at this particular index.
    int right(const int index) const;

    //build heap from initial values in vector (for constructor use)
    void build_heap();

    //heapify algorithm
    void heapify(int index);

    //decrease key, not sure if necessary though
    void decrease_key(int index, const T& element);

    //return the index of the smaller child at a given index
    int smaller_child(const int index);

    //percolate a node upwards
    void sift_up(const int index);

    //percolate a node downwards
    void sift_down(const int index);

    //return true if the index is within the heap
    //e.g. greater than/equal to 0 and less than heap size.
    bool within_heap(const int index);

    //return true if index == 0
    bool is_root(const int index);







private:
// add any private instance variables that may be helpful.
// here, size variable is not needed since we have size() function
// and we are using a vector for the container.
	std::vector<T> heap; 
};


// Implement all the member functions down here.
// The reason I am implementing function bodies in the header file
// is because this is a header file for a template class.


template <typename T>
MinHeap<T>::MinHeap(T* arr, int length)
{
    heap.assign(arr, arr + length);
}


template <typename T>
MinHeap<T>::MinHeap(const std::vector<T>& v)
{

	heap = v;
    build_heap();
}


template <typename T>
MinHeap<T>::MinHeap(const MinHeap& mh)
{
	heap = mh.heap;
}


template <typename T>
MinHeap<T>::MinHeap(MinHeap&& mh) noexcept
{
	std::swap(heap, mh.heap);
}


template <typename T>
MinHeap<T>& MinHeap<T>::operator=(const MinHeap& mh)
{
	heap = mh.heap;
    return *this;
}


template <typename T>
MinHeap<T>& MinHeap<T>::operator=(MinHeap&& mh) noexcept
{
	std::swap(heap, mh.heap);
    return *this;
}


template <typename T>
const T& MinHeap<T>::getMin() const
{
    if (isEmpty())
        throw MinHeapException("Heap is empty");
    return heap[0];
}


template <typename T>
void MinHeap<T>::removeMin()
{
    std::swap(heap[0], heap[heap.size()-1]);
    heap.pop_back();
    heapify(0); //was going to use heapify but heapify broke on the removeMin test case
}


template <typename T>
bool MinHeap<T>::isEmpty() const
{
    return heap.size() == 0;
}


template <typename T>
void MinHeap<T>::add(const T& element)
{
    heap.push_back(element);
    sift_up(heap.size()-1);
}


template <typename T>
void MinHeap<T>::remove(const int index)
{
    decrease_key(index, INT_MIN);
    removeMin();
}


template <typename T>
bool MinHeap<T>::contains(const T& element) const
{
    return std::find(heap.begin(),heap.end(), element) != heap.end();
}


template <typename T>
unsigned int MinHeap<T>::size() const noexcept
{
    return heap.size();
}


template <typename T>
int MinHeap<T>::height() const
{
    return (int)ceil(log2(heap.size() + 1)) - 1;
}


// From here, implement any private functions that may help you implement MinHeap

template <typename T>
int MinHeap<T>::parent(const int index) const
{
    if (index == 0)
        return -1;
    return (int)floor((index - 1) / 2);
}

template <typename T>
int MinHeap<T>::left(const int index) const
{
    if (2 * index + 1 < heap.size())
        return 2 * index + 1;
    return -1;
}

template <typename T>
int MinHeap<T>::right(const int index) const
{
    if (2 * index + 2 < heap.size())
        return 2 * index + 2;
    return -1;
}

template <typename T>
void MinHeap<T>::build_heap()
{
    for (int i = (int)((heap.size()) / 2); i >= 0; i--)
    {
        sift_down(i);
    }
}


template <typename T>
void MinHeap<T>::heapify(int index)
{

    //essentially the sift_down function in disguise; may refactor code to account for this

    int l = left(index);
    int r = right(index);
    int smaller;
    if (within_heap(l) && heap[l] < heap[index])
        smaller = l;
    else
        smaller = index;
    if (within_heap(r) && heap[r] < heap[smaller])
        smaller = r;
    if (smaller != index)
    {
        std::swap(heap[smaller], heap[index]);
        heapify(smaller);
    }
}

template <typename T>
void MinHeap<T>::decrease_key(int index, const T &element)
{
    if (element >= heap[index])
        throw MinHeapException("New key must be smaller than current key");
    heap[index] = element;
    sift_up(index);
}

template <typename T>
int MinHeap<T>::smaller_child(const int index)
{
    if (left(index) == -1 && right(index) == -1)
        return -1;
    if (right(index) == -1)
        return left(index);

    return heap[left(index)] < heap[right(index)] ? left(index) : right(index);
}

template <typename T>
void MinHeap<T>::sift_up(const int index)
{
    if (is_root(index) || index == -1)
        return;
    if (heap[parent(index)] > heap[index])
    {
        std::swap(heap[parent(index)], heap[index]);
        sift_up(parent(index));
    }
}

template <typename T>
void MinHeap<T>::sift_down(const int index)
{
    if (within_heap(2 * index + 1))
    {
        int child = smaller_child(index);
        if (child != -1 && heap[child] < heap[index])
        {
            std::swap(heap[child], heap[index]);
            sift_down(child);
        }
    }
}

template <typename T>
bool MinHeap<T>::within_heap(const int index)
{
    return index >= 0 && index < heap.size();
}

template <typename T>
bool MinHeap<T>::is_root(const int index)
{
    return index == 0;
}

template <typename T>
void MinHeap<T>::print()
{
    std::cout << "[";
    for (auto e : heap) {
        std::cout << e << std::endl;
    }
    std::cout << "]" << std::endl;
}


template <typename T>
typename MinHeap<T>::Iterator MinHeap<T>::iterator()
{
}


template <typename T>
typename MinHeap<T>::ConstIterator MinHeap<T>::constIterator() const
{
}


template <typename T>
MinHeap<T>::IteratorBase::IteratorBase(const MinHeap& mh) noexcept
{
}


template <typename T>
void MinHeap<T>::IteratorBase::moveToNext()
{
}


template <typename T>
void MinHeap<T>::IteratorBase::moveToPrevious()
{
}


template <typename T>
bool MinHeap<T>::IteratorBase::isPastStart() const noexcept
{
}


template <typename T>
bool MinHeap<T>::IteratorBase::isPastEnd() const noexcept
{
}


template <typename T>
MinHeap<T>::ConstIterator::ConstIterator(const MinHeap& mh) noexcept
{
}


template <typename T>
const T& MinHeap<T>::ConstIterator::value() const
{
}


template <typename T>
MinHeap<T>::Iterator::Iterator(MinHeap& mh) noexcept
{
}


template <typename T>
T& MinHeap<T>::Iterator::value() const
{
}


template <typename T>
void MinHeap<T>::Iterator::insertBefore(const T& value)
{
}


template <typename T>
void MinHeap<T>::Iterator::insertAfter(const T& value)
{
}


template <typename T>
void MinHeap<T>::Iterator::remove(bool moveToNextAfterward)
{
}


#endif /* MINHEAP_HPP */
