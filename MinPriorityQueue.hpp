// MinHeap.hpp
//
// Author: Soochin Kang
// Add authors if you are implementing this file
//
// Vesion1 Date: 6/17/2018
//
// This is the complete implementation of MinPriorityQueue<ValueType> class template.
// This class uses a MinHeap for the container.
// It uses private inheritence to hide details of MinHeap (container abstraction).
// Do not add any STL containers, only use MinHeap to implement.
// Also, DO NOT CHANGE any function headers (adding features would be fine, but
// make sure you test that function thoroughly).
// If you want to print something, including <iostream> would be okay.

// This class is already fully implemented if MinHeap.hpp is correctly implemented.

#ifndef MINPRIORITYQUEUE_HPP
#define MINPRIORITYQUEUE_HPP

#include "MinHeap.hpp"

template <typename ValueType>
class MinPriorityQueue : private MinHeap<ValueType> {
public:
	// Note that the constructors, destructors, and assignment operators
	// are not declared here, because the defaulys will do precisely what
	// we want them to, in this case: call the versions from the base class.
	// The only reason you would need to add those declarations is if you added
	// something to this class template that required
	// initialization, cleanup, etc., which is unlikely.
	// If you want your own constructors, destructors, and operator=, feel free
	// to implement those by adding public functions.


	// enqueue() add the given value to the queue with minimum priority.
	// the minimum element will be located at the front of the queue.
	void enqueue(const ValueType& value);


	// dequeueMin() removes the element that has the smallest priority value.
	// This is analogous to the queue operation dequeue().
	void dequeueMin();


	// findMin() returns the element that has the smallest priority value, without
	// removing it from the queue. This is analgous to the queue operation front().
	const ValueType& findMin() const;


	// These members of MinHeap are being made into public members
	// of MinPriorityQueue. Given a MinPriorityQueu object you'd now be able to
	// call the isEmpty() and size() member functions.
	//
	// Note that we don't need to implement those separately; the implementation
	// from MinHeap are not a part of MinPriorityQueue.
	// All we're doing is making them public.

	using MinHeap<ValueType>::isEmpty;
	using MinHeap<ValueType>::size;
};


template <typename ValueType>
void MinPriorityQueue<ValueType>::enqueue(const ValueType& value) {
	this->add(value);
}


template <typename ValueType>
void MinPriorityQueue<ValueType>::dequeueMin() {
	this->removeMin();
}


template <typename ValueType>
const ValueType& MinPriorityQueue<ValueType>::findMin() const {
	return this->getMin();
}


#endif /* MINPRIORITYQUEUE_HPP */
