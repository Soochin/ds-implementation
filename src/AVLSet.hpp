// AVLSet.hpp
//
// ICS 46 Winter 2018
// Project #4: Set the Controls for the Heart of the Sun
//
// An AVLSet is an implementation of a Set that is an AVL tree, which uses
// the algorithms we discussed in lecture to maintain balance every time a
// new element is added to the set.
//
// You are not permitted to use the containers in the C++ Standard Library
// (such as std::set, std::map, or std::vector) to store the information
// in your data structure.  Instead, you'll need to implement your AVL tree
// using your own dynamically-allocated nodes, with pointers connecting them,
// and with your own balancing algorithms used.

#ifndef AVLSET_HPP
#define AVLSET_HPP

#include <functional>
#include "Set.hpp"



template <typename T>
class AVLSet : public Set<T>
{
public:
    // Initializes an AVLSet to be empty.
    AVLSet();

    // Cleans up the AVLSet so that it leaks no memory.
    virtual ~AVLSet() noexcept;

    // Initializes a new AVLSet to be a copy of an existing one.
    AVLSet(const AVLSet& s);

    // Initializes a new AVLSet whose contents are moved from an
    // expiring one.
    AVLSet(AVLSet&& s) noexcept;

    // Assigns an existing AVLSet into another.
    AVLSet& operator=(const AVLSet& s);

    // Assigns an expiring AVLSet into another.
    AVLSet& operator=(AVLSet&& s) noexcept;


    // isImplemented() should be modified to return true if you've
    // decided to implement an AVLSet, false otherwise.
    virtual bool isImplemented() const noexcept override;


    // add() adds an element to the set.  If the element is already in the set,
    // this function has no effect.  This function always runs in O(log n) time
    // when there are n elements in the AVL tree.
    virtual void add(const T& element) override;


    // contains() returns true if the given element is already in the set,
    // false otherwise.  This function always runs in O(log n) time when
    // there are n elements in the AVL tree.
    virtual bool contains(const T& element) const override;


    // size() returns the number of elements in the set.
    virtual unsigned int size() const noexcept override;


    // height() returns the height of the AVL tree.
    int height() const;


    // preorder() visits all of the elements in the AVL tree in preorder,
    // calling the given "visit" function and passing it each element.
    void preorder(std::function<void(const T&)> visit) const;


    // inorder() visits all of the elements in the AVL tree in order
    // calling the given "visit" function and passing it each element.
    void inorder(std::function<void(const T&)> visit) const;


    // postorder() visits all of the elements in the AVL tree in postorder
    // calling the given "visit" function and passing it each element.
    void postorder(std::function<void(const T&)> visit) const;


private:

};


template <typename T>
AVLSet<T>::AVLSet()
{
}


template <typename T>
AVLSet<T>::~AVLSet() noexcept
{
}


template <typename T>
AVLSet<T>::AVLSet(const AVLSet& s)
{
}


template <typename T>
AVLSet<T>::AVLSet(AVLSet&& s) noexcept
{
}


template <typename T>
AVLSet<T>& AVLSet<T>::operator=(const AVLSet& s)
{
    return *this;
}


template <typename T>
AVLSet<T>& AVLSet<T>::operator=(AVLSet&& s) noexcept
{
    return *this;
}


template <typename T>
bool AVLSet<T>::isImplemented() const noexcept
{
    return false;
}


template <typename T>
void AVLSet<T>::add(const T& element)
{
}


template <typename T>
bool AVLSet<T>::contains(const T& element) const
{
    return false;
}


template <typename T>
unsigned int AVLSet<T>::size() const noexcept
{
    return 0;
}


template <typename T>
int AVLSet<T>::height() const
{
    return -1;
}


template <typename T>
void AVLSet<T>::preorder(std::function<void(const T&)> visit) const
{
}


template <typename T>
void AVLSet<T>::inorder(std::function<void(const T&)> visit) const
{
}


template <typename T>
void AVLSet<T>::postorder(std::function<void(const T&)> visit) const
{
}



#endif // AVLSET_HPP

