/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:09:22 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/28 19:07:04 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

using std::string;

class Character : public ICharacter
{
    private:
        string name;
        AMateria* inventory[4];
    public:
        Character(string const & name);
        Character(const Character &src);
        Character &operator=(const Character &src);
        ~Character();
        virtual string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};

#endif
