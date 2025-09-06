#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <exception>
#include <algorithm>

class NotFoundException : public std::exception
{
	public:
		const char* what() const throw() { return "Not found in array"; }
};

template <typename T>
typename T::iterator easyfind(T& in, int i)
{
	typename T::iterator index = std::find(in.begin(), in.end(), i);
	
	if (index == in.end())
		throw NotFoundException();
	return (index);
}


#endif