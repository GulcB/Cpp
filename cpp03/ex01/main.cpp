/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:36:38 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/18 15:50:40 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::atoi;
using std::strcmp;

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
	ClapTrap clapFirst(soldier_name);
	cout << "You should give a enemy name" << endl;
	cin >> enemy_name;
	if (cin.fail())
	{
		cout << "See you another world, goodbye! " << endl;
		return (1);
	}
	ClapTrap clapSecond(enemy_name);
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
	clapFirst.attack(enemy_name);
	clapSecond.takeDamage(amountDamage);
	clapSecond.beRepaired(amountRepair);

	clapSecond.attack(soldier_name);
	clapFirst.takeDamage(amountDamage);
	clapFirst.beRepaired(amountRepair);
	return (0);
}
