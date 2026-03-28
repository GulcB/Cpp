/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array_impl.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:53:25 by gbodur            #+#    #+#             */
/*   Updated: 2026/03/27 17:53:27 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(NULL), _size(n)
{
	if (this->_size > 0)
		this->_array = new T[this->_size]();
}

template <typename T>
Array<T>::Array(const Array &array) : _array(NULL), _size(0)
{
	*this = array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &array)
{
	if (this != &array)
	{
		delete [] this->_array;
		this->_array = NULL;
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
