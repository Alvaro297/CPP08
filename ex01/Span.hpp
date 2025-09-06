#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <exception>
#include <vector>
#include <iostream>

class Span
{
private:
	std::vector<int> _data;
	unsigned int maxNumbers;
public:
	Span();
	Span(unsigned int maxNum);
	Span(const Span& newSpan);
	Span& operator=(const Span& newSpan);
	~Span();
	void addNumber(int newNumber);
	int shortestSpan();
	int longestSpan();

	class IndexOutBound : public std::exception
	{
		public:
			const char* what() const throw() { return "So much number in array"; }
	};
};


#endif