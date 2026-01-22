/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:50:38 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/22 16:29:57 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMateria
# define AMateria

#include <string>
#include <iostream>
#include "ICharacter.hpp"

using std::string;

class AMateria
{
	protected:

	public:
		AMateria(string const &type);
		string const &getType() const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
}

#endif