/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:36:58 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/22 21:17:08 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

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
		cout << "Example: ./fragTrap 5" << endl;
		return (1);
	}
	cout << "You should give a soldier name" << endl;
	cin >> soldier_name;
	if (cin.fail())
	{
		cout << "See you another world, goodbye! " << endl;
		return (1);
	}
	FragTrap fragFirst(soldier_name);
	cout << "\n------ Special Abilities Test for " << soldier_name << " -----" << endl;
	fragFirst.highFivesGuys();
	cout << "--------------------------------------------\n" << endl;
	cout << "You should give a enemy name" << endl;
	cin >> enemy_name;
	if (cin.fail())
	{
		cout << "See you another world, goodbye! " << endl;
		return (1);
	}
	FragTrap fragSecond(enemy_name);
	cout << "\n------ Special Abilities Test for " << enemy_name << " -----" << endl;
	fragSecond.highFivesGuys();
	cout << "-------------------------------------------\n" << endl;
	amountRepair = atoi(argv[1]);
	if (amountRepair < 0)
	{
		cout << "Amount repair must be positive number" << endl;
		return (1);
	}
	cout << "----------------------------- BATTLE START ------------------------------" << endl;
	fragFirst.attack(enemy_name);
	fragSecond.takeDamage(fragFirst.getAttackDamage());
	fragSecond.beRepaired(amountRepair);
	cout << endl;
	fragSecond.attack(soldier_name);
	fragFirst.takeDamage(fragSecond.getAttackDamage());
	fragFirst.beRepaired(amountRepair);
	cout << "------------------------------- BATTLE END -------------------------------" << endl;
	cout << endl;
	return (0);
}
