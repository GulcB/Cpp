/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:04:51 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/29 16:30:45 by gbodur           ###   ########.fr       */
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
	
	cout << endl << "--- EXTRA TESTS (Inventory, Index & Empty Slots) ---" << endl;
	me->equip(materia->createMateria("ice"));
	me->equip(materia->createMateria("cure"));
	
	tmp = materia->createMateria("ice");
	me->equip(tmp);

	cout << "Using invalid index (-1): ";
    me->use(-1, *bob); 
    cout << endl << "Using invalid index (10): ";
    me->use(10, *bob);
	cout << endl;

	AMateria* floor = ((Character*)me)->getMateria(1); 
    me->unequip(1); 
    delete floor;

	cout << endl << "--- DEEP COPY & INVENTORY TEST ---" << endl;
    
    Character* c1 = new Character("Original");
    c1->equip(materia->createMateria("ice"));
    
    Character* c2 = new Character(*c1);
    
    cout << "Original uses: ";
    c1->use(0, *bob);
    
    cout << "Copy uses: ";
    c2->use(0, *bob);
	
	delete c1;
    cout << "After deleting Original, Copy still uses: ";
    c2->use(0, *bob);

	delete c2;
	delete bob;
    delete me;
    delete materia;
	
    return (0);
}
