/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:10:52 by gbodur            #+#    #+#             */
/*   Updated: 2026/08/23 13:35:15 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>
# include <algorithm>
# include <iterator>

class Span
{
	private:
	    unsigned int        _maxSize;
	    std::vector<int>    _data;
	
	public:
		class SpanFullException : public std::exception
	    {
	    	public:
	        	virtual const char* what() const throw();
	    };
	
	    class SpanNotEnoughNumbersException : public std::exception
	    {
	    	public:
	        	virtual const char* what() const throw();
	    };
		
	    Span();
	    Span(unsigned int N);
	    Span(const Span &other);
	    Span &operator=(const Span &other);
	    ~Span();
	
	    void addNumber(int number);
	
	    template <typename Iterator>
	    void addNumber(Iterator begin, Iterator end)
	    {
	        unsigned int distance = static_cast<unsigned int>(std::distance(begin, end));
	        if (_data.size() + distance > _maxSize)
	            throw SpanFullException();
	        _data.insert(_data.end(), begin, end);
	    }
	
	    unsigned int shortestSpan() const;
	    unsigned int longestSpan() const;
};

#endif
