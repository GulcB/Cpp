/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:16:55 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/23 00:01:53 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::atoi;

int main(int argc, char **argv)
{
	int			amountRepair;
	string		soldier_name;
	string		enemy_name;

	amountRepair = 0;
	if (argc != 2)
	{
		cout << "Usage of amount: <amount of beRepaired>" << endl;
		cout << "Example: ./clapTrap 5 " << endl;
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
	amountRepair = atoi(argv[1]);
	if (amountRepair < 0)
	{
		cout << "Amount repair must be positive number" << endl;
		return (1);
	}
	cout << "----------------------------- BATTLE START ------------------------------" << endl;
	clapFirst.attack(enemy_name);
	clapSecond.takeDamage(clapFirst.getAttackDamage());
	clapSecond.beRepaired(amountRepair);
	cout << endl;
	clapSecond.attack(soldier_name);
	clapFirst.takeDamage(clapSecond.getAttackDamage());
	clapFirst.beRepaired(amountRepair);
	cout << "------------------------------- BATTLE END -------------------------------" << endl;
	return (0);
}
