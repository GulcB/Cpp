/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:10:50 by gbodur            #+#    #+#             */
/*   Updated: 2026/08/23 06:37:01 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include "Span.hpp"
#include <limits>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _data(other._data) {}

Span& Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _data = other._data;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (_data.size() >= _maxSize)
        throw SpanFullException();
    _data.push_back(number);
}

unsigned int Span::shortestSpan() const
{
    if (_data.size() < 2)
        throw SpanNotEnoughNumbersException();

    std::vector<int> sortedData = _data;
    std::sort(sortedData.begin(), sortedData.end());

    unsigned int minSpan = std::numeric_limits<unsigned int>::max();
    
    for (std::vector<int>::const_iterator it = sortedData.begin(); it != sortedData.end() - 1; ++it)
    {
        unsigned int diff = static_cast<unsigned int>(*(it + 1) - *it);
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

unsigned int Span::longestSpan() const
{
    if (_data.size() < 2)
        throw SpanNotEnoughNumbersException();

    std::vector<int>::const_iterator minIt = std::min_element(_data.begin(), _data.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_data.begin(), _data.end());

    return (static_cast<unsigned int>(*maxIt - *minIt));
}

const char *Span::SpanFullException::what() const throw()
{
    return "Fatal: Cannot add number, Span capacity is full.";
}

const char *Span::SpanNotEnoughNumbersException::what() const throw()
{
    return "Error: At least two numbers are required to calculate a span.";
}
