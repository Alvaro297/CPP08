#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>
#include <vector>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		typedef typename std::deque<T>::iterator iterator;
		//typedef typename std::deque<T>::constIterator constIterator;

		iterator begin() { return this->c.begin();};
		iterator end() { return this->c.end();};
		//constIterator begin() const { return this->c.begin();};
		//constIterator end() const { return this->c.end();};
};

#endif