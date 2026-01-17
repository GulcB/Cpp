/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:16:55 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/17 17:24:09 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

using std::cout;
using std::endl;
using std::atoi;
using std::strcmp;

int main(int argc, char **argv)
{
	ClapTrap	clapFirst("Gulc");
	ClapTrap	clapSecond("Enemy");
	int			amountDamage;
	int			amountRepair;

	amountDamage = 0;
	amountRepair = 0;
	if (argc != 3)
	{
		cout << "Usage: <amount of takeDamage> <amount of beRepaired>" << endl;
		cout << "Example: ./clapTrap 5 3" << endl;
		return (1);
	}
	amountDamage = atoi(argv[1]);
	amountRepair = atoi(argv[2]);
	if (amountDamage < 0)
	{
		cout << "Amount damage must be positive number" << endl;
		return (1);
	}
	if (amountRepair < 0)
	{
		cout << "Amount repair must be positive number" << endl;
		return (1);
	}
	clapFirst.attack("Enemy");
	clapSecond.takeDamage(amountDamage);
	clapSecond.beRepaired(amountRepair);

	clapSecond.attack("Gulc");
	clapFirst.takeDamage(amountDamage);
	clapFirst.beRepaired(amountRepair);
	return (0);
}