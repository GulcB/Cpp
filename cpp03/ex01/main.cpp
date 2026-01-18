/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:36:38 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/18 20:43:16 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::atoi;

int main(int argc, char **argv)
{
	int			amountDamage;
	int			amountRepair;
	string		soldier_name;
	string		enemy_name;

	amountDamage = 0;
	amountRepair = 0;
	if (argc != 3)
	{
		cout << "Usage of amount: <amount of takeDamage> <amount of beRepaired>" << endl;
		cout << "Example: ./clapTrap 5 3" << endl;
		return (1);
	}
	cout << "You should give a soldier name" << endl;
	cin >> soldier_name;
	if (cin.fail())
	{
		cout << "See you another world, goodbye! " << endl;
		return (1);
	}
	ScavTrap scavFirst(soldier_name);
	scavFirst.guardGate();
	cout << "You should give a enemy name" << endl;
	cin >> enemy_name;
	if (cin.fail())
	{
		cout << "See you another world, goodbye! " << endl;
		return (1);
	}
	ScavTrap scavSecond(enemy_name);
	scavSecond.guardGate();
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
	scavFirst.attack(enemy_name);
	scavSecond.takeDamage(amountDamage);
	scavSecond.beRepaired(amountRepair);

	scavSecond.attack(soldier_name);
	scavFirst.takeDamage(amountDamage);
	scavFirst.beRepaired(amountRepair);
	return (0);
}
