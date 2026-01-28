/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:09:44 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/28 19:25:04 by gbodur           ###   ########.fr       */
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

MateriaSource::MateriaSource(const MateriaSource &src)
{
    for (int i = 0; i < 4; i++)
    {
        if (src.learnInventory[i])
            this->learnInventory[i] = src.learnInventory[i]->clone();
        else
            this->learnInventory[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
    if (this != &src)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->learnInventory[i])
                delete this->learnInventory[i];
        }
        for (int i = 0; i < 4; i++)
        {
            if (src.learnInventory[i])
                this->learnInventory[i] = src.learnInventory[i]->clone();
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

void MateriaSource::learnMateria(AMateria* m)
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

AMateria* MateriaSource::createMateria(string const & type)
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
