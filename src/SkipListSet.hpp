// SkipListSet.hpp
//
// ICS 46 Winter 2018
// Project #4: Set the Controls for the Heart of the Sun
//
// A SkipListSet is an implementation of a Set that is a skip list, implemented
// as we discussed in lecture.  A skip list is a sequence of levels
//
// You are not permitted to use the containers in the C++ Standard Librar
// (such as std::set, std::map, or std::vector), *except* that you can use
// std::vector to store your level (e.g., pointers to the head node of each
// level) if you'd like.  Beyond that, you'll need to implement your own
// dynamically-allocated nodes with pointers connecting htem.  Notably,
// you'll also need <random> from the C++ Standard Library, which I've used
// below.
//
// Each node should contain only two pointers: one to the node that follows it
// on the same level and another to the equivalent node on the level below it.
// Additional pointers use more memory but don't enable any techniques not
// enabled by the other two.
//
// Three utilities are included here: SkipListKind, SkipListKey, and
// SkipListLevelTester.  You'll want to use these as-is and should not
// modify them.

#ifndef SKIPLISTSET_HPP
#define SKIPLISTSET_HPP

#include <memory>
#include <random>
#include "Set.hpp"




// SkipListKind indicates a kind of key: a normal one, the special key
// -INF, or the special key +INF.  It's necessary for us to implement
// the notion of -INF and +INF separately, since we're building a class
// template and not all types of keys would have a reasonable notion of
// -INF and +INF.

enum class SkipListKind
{
    Normal,
    NegInf,
    PosInf
};




// A SkipListKey represents a single key in a skip list.  It is possible
// to compare these keys using < or == operators (which are overloaded here)
// and those comparisons respect the notion of whether each key is normal,
// -INF, or +INF.

template <typename T>
class SkipListKey
{
public:
    SkipListKey(SkipListKind kind, const T& key);

    bool operator==(const SkipListKey& other) const;
    bool operator<(const SkipListKey& other) const;

private:
    SkipListKind kind;
    T key;
};


template <typename T>
SkipListKey<T>::SkipListKey(SkipListKind kind, const T& key)
    : kind{kind}, key{key}
{
}


template <typename T>
bool SkipListKey<T>::operator==(const SkipListKey& other) const
{
    return kind == other.kind
        && (kind != SkipListKind::Normal || key == other.key);
}


template <typename T>
bool SkipListKey<T>::operator<(const SkipListKey& other) const
{
    switch (kind)
    {
    case SkipListKind::NegInf:
        return other.kind != SkipListKind::NegInf;

    case SkipListKind::PosInf:
        return false;

    default: // SkipListKind::Normal
        return other.kind == SkipListKind::PosInf
            || (other.kind == SkipListKind::Normal && key < other.key);
    }
}



// The SkipListLevelTester class represents the ability to decide whether
// a key placed on one level of the skip list should also occupy the next
// level.  This is the "coin flip," so to speak.  Note that this is an
// abstract base class with one implementation, RandomSkipListLevelTester,
// just below it.  RandomSkipListLevelTester is what it sounds like: It
// makes the decision at random (with a 50/50 chance of deciding whether
// a key should occupy the next level).  However, by setting things up
// this way, we have a way to control things more carefully in our
// testing (as you can, as well).

class SkipListLevelTester
{
public:
    virtual ~SkipListLevelTester() = default;

    virtual bool shouldOccupyNextLevel() = 0;
    virtual std::unique_ptr<SkipListLevelTester> clone() = 0;
};



class RandomSkipListLevelTester : public SkipListLevelTester
{
public:
    RandomSkipListLevelTester();
    virtual ~RandomSkipListLevelTester() = default;

    virtual bool shouldOccupyNextLevel() override;
    virtual std::unique_ptr<SkipListLevelTester> clone() override;

private:
    std::default_random_engine engine;
    std::bernoulli_distribution distribution;
};


inline RandomSkipListLevelTester::RandomSkipListLevelTester()
    : engine{std::random_device{}()}, distribution{0.5}
{
}


inline bool RandomSkipListLevelTester::shouldOccupyNextLevel()
{
    return distribution(engine);
}


inline std::unique_ptr<SkipListLevelTester> RandomSkipListLevelTester::clone()
{
    return std::unique_ptr<SkipListLevelTester>{new RandomSkipListLevelTester()};
}




template <typename T>
class SkipListSet : public Set<T>
{
public:
    // Initializes an SkipListSet to be empty, with or without a
    // "level tester" object that will decide, whenever a "coin flip"
    // is needed, whether a key should occupy the next level above.
    SkipListSet();
    SkipListSet(std::unique_ptr<SkipListLevelTester> levelTester);

    // Cleans up the SkipListSet so that it leaks no memory.
    virtual ~SkipListSet() noexcept;

    // Initializes a new SkipListSet to be a copy of an existing one.
    SkipListSet(const SkipListSet& s);

    // Initializes a new SkipListSet whose contents are moved from an
    // expiring one.
    SkipListSet(SkipListSet&& s) noexcept;

    // Assigns an existing SkipListSet into another.
    SkipListSet& operator=(const SkipListSet& s);

    // Assigns an expiring SkipListSet into another.
    SkipListSet& operator=(SkipListSet&& s) noexcept;


    // isImplemented() should be modified to return true if you've
    // decided to implement a SkipListSet, false otherwise.
    virtual bool isImplemented() const noexcept override;


    // add() adds an element to the set.  If the element is already in the set,
    // this function has no effect.  This function runs in an expected time
    // of O(log n) (i.e., over the long run, we expect the average to be
    // O(log n)) with very high probability.
    virtual void add(const T& element) override;


    // contains() returns true if the given element is already in the set,
    // false otherwise.  This function runs in an expected time of O(log n)
    // (i.e., over the long run, we expect the average to be O(log n))
    // with very high probability.
    virtual bool contains(const T& element) const override;


    // size() returns the number of elements in the set.
    virtual unsigned int size() const noexcept override;


    // levelCount() returns the number of levels in the skip list.
    unsigned int levelCount() const noexcept;


    // nodesOnLevel() returns the number of nodes on the given level
    // of the skip list.  Level 0 is the bottom level; level 1 is the
    // one above level 0; and so on.  If the given level doesn't exist,
    // this function returns 0.
    unsigned int nodesOnLevel(unsigned int level) const noexcept;


    // isElementOnLevel() returns true if the given element is on the
    // given level, false otherwise.  Level 0 is the bottom level; level 1
    // is the one above level 0; and so on.  If the given level doesn't
    // exist, this function returns false.
    bool isElementOnLevel(const T& element, unsigned int level) const;


private:
    std::unique_ptr<SkipListLevelTester> levelTester;
};


template <typename T>
SkipListSet<T>::SkipListSet()
    : SkipListSet{std::make_unique<RandomSkipListLevelTester>()}
{
}


template <typename T>
SkipListSet<T>::SkipListSet(std::unique_ptr<SkipListLevelTester> levelTester)
    : levelTester{std::move(levelTester)}
{
}


template <typename T>
SkipListSet<T>::~SkipListSet() noexcept
{
}


template <typename T>
SkipListSet<T>::SkipListSet(const SkipListSet& s)
{
}


template <typename T>
SkipListSet<T>::SkipListSet(SkipListSet&& s) noexcept
{
}


template <typename T>
SkipListSet<T>& SkipListSet<T>::operator=(const SkipListSet& s)
{
    return *this;
}


template <typename T>
SkipListSet<T>& SkipListSet<T>::operator=(SkipListSet&& s) noexcept
{
    return *this;
}


template <typename T>
bool SkipListSet<T>::isImplemented() const noexcept
{
    return false;
}


template <typename T>
void SkipListSet<T>::add(const T& element)
{
}


template <typename T>
bool SkipListSet<T>::contains(const T& element) const
{
    return false;
}


template <typename T>
unsigned int SkipListSet<T>::size() const noexcept
{
    return 0;
}


template <typename T>
unsigned int SkipListSet<T>::levelCount() const noexcept
{
    return 0;
}


template <typename T>
unsigned int SkipListSet<T>::nodesOnLevel(unsigned int level) const noexcept
{
    return 0;
}


template <typename T>
bool SkipListSet<T>::isElementOnLevel(const T& element, unsigned int level) const
{
    return false;
}



#endif // SKIPLISTSET_HPP

