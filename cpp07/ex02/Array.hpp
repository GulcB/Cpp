/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:53:17 by gbodur            #+#    #+#             */
/*   Updated: 2026/03/27 17:53:19 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

using std::exception;

template <typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &array);
		Array &operator=(const Array &array);
		~Array();

		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;
		unsigned int size() const;

		class IndexOutOfBoundsException : public exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#include "Array_impl.hpp"

#endif
