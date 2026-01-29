/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:50:38 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/29 12:14:19 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>

using std::string;

class ICharacter;

class AMateria
{
	protected:
		string type;
	public:
		AMateria();
		AMateria(string const &type);
        AMateria(const AMateria &materia);
        AMateria &operator=(const AMateria &materia);
		virtual ~AMateria();
		string const &getType() const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif
