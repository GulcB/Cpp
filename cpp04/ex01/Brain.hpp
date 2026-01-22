/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:38:04 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/22 12:20:04 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

#define ANIMAL_COUNT 4

using std::string;

class Brain
{
	public:
		string ideas[100];
		Brain();
		Brain(const Brain &brain);
		Brain &operator=(const Brain &brain);
		virtual ~Brain();
};

#endif