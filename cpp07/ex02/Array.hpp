/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:53:17 by gbodur            #+#    #+#             */
/*   Updated: 2026/08/01 17:04:34 by gbodur           ###   ########.fr       */
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

template <typename T>
Array<T>::Array() : _array(0), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(0), _size(n)
{
	if (this->_size > 0)
		this->_array = new T[this->_size]();
}

template <typename T>
Array<T>::Array(const Array &array) : _array(0), _size(0)
{
	*this = array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &array)
{
	if (this != &array)
	{
		delete [] this->_array;
		this->_array = 0;
		this->_size = array._size;
		if (this->_size > 0)
		{
			this->_array = new T[this->_size]();
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = array._array[i];
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete [] this->_array;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw IndexOutOfBoundsException();
	return (this->_array[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_size)
		throw IndexOutOfBoundsException();
	return (this->_array[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->_size);
}

template <typename T>
const char *Array<T>::IndexOutOfBoundsException::what() const throw()
{
	return ("Index is out of bounds.");
}

#endif
