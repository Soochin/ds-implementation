// MinHeapException.hpp
// This header file contains class MinHeapException
// which can be thrown in MinHeap class.
// MinHeapException can be constructed with a string
// That specifies the reason for throwing excpetions.

#ifndef MINHEAPEXCEPTION_HPP
#define MINHEAPEXCEPTION_HPP

#include <string>

class MinHeapException {
public:
	MinHeapException(const std::string& reason);

	std::string reason() const;
private:
	std::string reason_;
};

inline MinHeapException::MinHeapException(const std::string& reason)
	: reason_{reason}
{
}

inline std::string MinHeapException::reason() const {
	return reason_;
}

#endif /* MINHEAPEXCPETION_HPP */