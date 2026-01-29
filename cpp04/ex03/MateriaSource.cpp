/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:09:44 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/29 12:19:31 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

using std::cout;
using std::endl;
using std::string;

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->learnInventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &materia)
{
    for (int i = 0; i < 4; i++)
    {
        if (materia.learnInventory[i])
            this->learnInventory[i] = materia.learnInventory[i]->clone();
        else
            this->learnInventory[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materia)
{
    if (this != &materia)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->learnInventory[i])
                delete this->learnInventory[i];
        }
        for (int i = 0; i < 4; i++)
        {
            if (materia.learnInventory[i])
                this->learnInventory[i] = materia.learnInventory[i]->clone();
            else
                this->learnInventory[i] = NULL;
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->learnInventory[i])
            delete this->learnInventory[i];
    }
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (this->learnInventory[i] == NULL)
        {
            this->learnInventory[i] = m;
            cout << "MateriaSource learned " << m->getType() << endl;
            return;
        }
    }
    cout << "MateriaSource memory is full!" << endl;
    delete m;
}

AMateria *MateriaSource::createMateria(string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->learnInventory[i] && this->learnInventory[i]->getType() == type)
        {
            return (this->learnInventory[i]->clone());
        }
    }
    return (0);
}
