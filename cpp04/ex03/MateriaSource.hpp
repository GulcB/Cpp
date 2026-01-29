/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:09:15 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/29 12:19:15 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

using std::string;

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* learnInventory[4];

    public:
        MateriaSource();
        MateriaSource(const MateriaSource &materia);
        MateriaSource &operator=(const MateriaSource &materia);
        ~MateriaSource();
        virtual void learnMateria(AMateria *m);
        virtual AMateria* createMateria(string const &type);
};

#endif
