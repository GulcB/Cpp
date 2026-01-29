/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:09:20 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/29 12:16:54 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

using std::cout;
using std::endl;
using std::string;

Character::Character(string const &name) : name(name)
{
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(const Character &materia) : name(materia.name)
{
    for (int i = 0; i < 4; i++)
    {
        if (materia.inventory[i])
            this->inventory[i] = materia.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
}

Character &Character::operator=(const Character &materia)
{
    if (this != &materia)
    {
        this->name = materia.name;
        for (int i = 0; i < 4; i++)
        {
            if (this->inventory[i])
                delete this->inventory[i];
        }
        for (int i = 0; i < 4; i++)
        {
            if (materia.inventory[i])
                this->inventory[i] = materia.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
        }
    }
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i])
            delete this->inventory[i];
    }
}

string const &Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria *m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] == NULL)
        {
            this->inventory[i] = m;
            cout << "Equipped " << m->getType() << " to slot " << i << endl;
            return;
        }
    }
    cout << "Inventory is full!" << endl;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && this->inventory[idx])
    {
        cout << "Unequipped " << this->inventory[idx]->getType()
			<< " from slot " << idx << endl;
        this->inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && this->inventory[idx])
        this->inventory[idx]->use(target);
}
