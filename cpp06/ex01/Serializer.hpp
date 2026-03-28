/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:40:40 by gbodur            #+#    #+#             */
/*   Updated: 2026/03/28 12:27:14 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>
#include <string>
#include <iostream>
#include <sstream>

using std::string;

struct Data
{
	string	name;
	int		id;
	double	score;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &serializer);
		Serializer &operator=(const Serializer &serializer);
		~Serializer();

	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif
