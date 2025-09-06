#include "Span.hpp"
#include <stdexcept>

Span::Span() : _data(), maxNumbers(0) { std::cout << "Span default constructor called" << std::endl; }

Span::Span(unsigned int n) : _data(), maxNumbers(n) { std::cout << "Span parameterized constructor called with n=" << n << std::endl; }

Span::Span(const Span& other) : _data(other._data), maxNumbers(other.maxNumbers) { std::cout << "Span copy constructor called" << std::endl; }

Span& Span::operator=(const Span& other)
{
	std::cout << "Span copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_data = other._data;
		this->maxNumbers = other.maxNumbers;
	}
	return *this;
}

Span::~Span() { std::cout << "Span destructor called" << std::endl; }

int Span::longestSpan()
{
	int minElement, maxElement;

	if (this->_data.size() < 2)
		throw std::runtime_error("Not enough elements");
	minElement = *std::min_element(_data.begin(), _data.end());
	maxElement = *std::max_element(_data.begin(), _data.end());
	return (maxElement - minElement);
}

int Span::shortestSpan()
{
	int minElement, element;
	std::vector<int> shortedVector;

	if (this->_data.size() < 2)
		throw std::runtime_error("Not enough elements");
	shortedVector = _data;
	std::sort(shortedVector.begin(), shortedVector.end());
	for (size_t i = 0; i < (shortedVector.size() - 1); i++)
	{
		if (i == 0)
			minElement = shortedVector[i + 1] - shortedVector[i];
		else
		{
			element = shortedVector[i + 1] - shortedVector[i];
			if (element < minElement)
				minElement = element;
		}
	}
	return (minElement);
}

void Span::addNumber(int newNumber)
{
	if (this->_data.size() >= this->maxNumbers)
		throw IndexOutBound();
	this->_data.push_back(newNumber);
}
