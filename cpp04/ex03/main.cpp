/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:04:51 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/29 12:24:48 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

using std::cout;
using std::endl;

int main()
{
    cout << "--- SUBJECT TEST ---" << endl;
    IMateriaSource *materia = new MateriaSource();
    materia->learnMateria(new Ice());
    materia->learnMateria(new Cure());

    ICharacter *me = new Character("me");

    AMateria *tmp;
    tmp = materia->createMateria("ice");
    me->equip(tmp);
    tmp = materia->createMateria("cure");
    me->equip(tmp);

    ICharacter *bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete materia;
	
    return (0);
}
