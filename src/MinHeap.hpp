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

template <typename T>
class MinHeap {
public:
	// default constructor
	MinHeap() noexcept;

	// constructor with int array and length
	MinHeap(int* arr, int length);

	// constructor with a vector
	MinHeap(const std::vector<int>& v);

	// destructor
	virtual ~MinHeap() noexcept;

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
	void remove(const T& element);


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

private:
// implement any private functions that may help implement minheap.


    //may consider throwing errors when no such parent
    //or left/right child exists


    //https://courses.csail.mit.edu/6.006/fall10/handouts/recitation10-8.pdf
    //this provides functions for max-heap, but it will be helpful in implementing minheap in C++
    

    //return the parent of the node at this particular index.
    int parent(const int index) const;

    //return the left child of the node at this particular index.
    int left(const int index) const;

    //return the right child of the node at this particular index.
    int right(const int index) const;


private:
// add any private instance variables that may be helpful.
// here, size variable is not needed since we have size() function
// and we are using a vector for the container.
	std::vector<T> head; 
};


// Implement all the member functions down here.
// The reason I am implementing function bodies in the header file
// is because this is a header file for a template class.

template <typename T>
MinHeap<T>::MinHeap() noexcept
{
}


template <typename T>
MinHeap<T>::MinHeap(int* arr, int length)
    : head(begin(arr), end(arr))
{
}


template <typename T>
MinHeap<T>::MinHeap(const std::vector<int>& v)
{
}


template <typename T>
MinHeap<T>::~MinHeap() noexcept
{
}


template <typename T>
MinHeap<T>::MinHeap(const MinHeap& mh)
{
}


template <typename T>
MinHeap<T>::MinHeap(MinHeap&& mh) noexcept
{
}


template <typename T>
MinHeap<T>& MinHeap<T>::operator=(const MinHeap& mh)
{
    return *this;
}


template <typename T>
MinHeap<T>& MinHeap<T>::operator=(MinHeap&& mh) noexcept
{
    return *this;
}


template <typename T>
const T& MinHeap<T>::getMin() const
{
    if (isEmpty())
        throw MinHeapException("Heap is empty");
    return buf[0];
}


template <typename T>
void MinHeap<T>::removeMin()
{
}


template <typename T>
bool MinHeap<T>::isEmpty() const
{
    return buf.size() == 0;
}


template <typename T>
void MinHeap<T>::add(const T& element)
{
}


template <typename T>
void MinHeap<T>::remove(const T& element)
{
}


template <typename T>
bool MinHeap<T>::contains(const T& element) const
{
}


template <typename T>
unsigned int MinHeap<T>::size() const noexcept
{
    return buf.size();
}


template <typename T>
int MinHeap<T>::height() const
{
}


// From here, implement any private functions that may help you implement MinHeap

template <typename T>
int MinHeap<T>::parent(const int index) const
{
}

template <typename T>
int MinHeap<T>::left(const int index) const
{
}

template <typename T>
int MinHeap<T>::right(const int index) const
{
}





#endif /* MINHEAP_HPP */
