/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:04:51 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/28 19:30:15 by gbodur           ###   ########.fr       */
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
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    cout << endl << "--- DEEP COPY & INVENTORY TEST ---" << endl;
    
    Character* c1 = new Character("Original");
    c1->equip(src->createMateria("ice"));
    
    Character* c2 = new Character(*c1);
    
    cout << "Original uses: ";
    c1->use(0, *bob);
    
    cout << "Copy uses: ";
    c2->use(0, *bob);

    cout << "Unequip Test: ";
    c1->unequip(0); 

    delete bob;
    delete me;
    delete src;
    delete c1;
    delete c2;

    return (0);
}
