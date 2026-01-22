/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:37:31 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/22 21:16:25 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

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
		cout << "Usage: ./diamondTrap <amount of beRepaired>" << endl;
		cout << "Example: ./diamondTrap 30" << endl;
		return (1);
	}
	cout << "You should give a soldier name" << endl;
	cin >> soldier_name;
	if (cin.fail())
	{
		cout << "See you another world, goodbye! " << endl;
		return (1);
	}
	DiamondTrap diamondFirst(soldier_name);
	cout << "\n---------------------- Special Abilities Test for " << soldier_name << " ---------------------" << endl;
	diamondFirst.whoAmI();
	diamondFirst.guardGate();    
	diamondFirst.highFivesGuys();
	cout << "-------------------------------------------------------------------------\n" << endl;
	cout << "You should give a enemy name: " << endl;
	cin >> enemy_name;
	if (cin.fail())
	{
		cout << "See you another world, goodbye! " << endl;
		return (1);
	}
	DiamondTrap diamondSecond(enemy_name);
	cout << "\n---------------------- Special Abilities Test for " << enemy_name << " ---------------------" << endl;
	diamondSecond.whoAmI();
	diamondSecond.guardGate();
	diamondSecond.highFivesGuys();
	cout << "-------------------------------------------------------------------------\n" << endl;
	amountRepair = atoi(argv[1]);
	if (amountRepair < 0)
	{
		cout << "Amount repair must be positive number" << endl;
		return (1);
	}
	cout << "----------------------------- BATTLE START ------------------------------" << endl;
	diamondFirst.attack(enemy_name); 
	diamondSecond.takeDamage(diamondFirst.getAttackDamage());
	diamondSecond.beRepaired(amountRepair);
	cout << endl;
	diamondSecond.attack(soldier_name);
	diamondFirst.takeDamage(diamondSecond.getAttackDamage());
	diamondFirst.beRepaired(amountRepair);
	cout << "------------------------------- BATTLE END -------------------------------" << endl;
	cout << endl;
	return (0);
}
