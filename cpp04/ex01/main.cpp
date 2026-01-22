/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:23:09 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/22 12:25:15 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void deepCopyTest()
{
	cout << "--- Real Dog ---" << endl;
    Dog original;
    cout << "--- Copy Dog ---" << endl;
    {
        Dog copy = original;
    }
}

int main()
{
	cout << "--- SUBJECT TEST ---" << endl;
	const Animal *animals[ANIMAL_COUNT];
	for (int i = 0; i < ANIMAL_COUNT; i++)
	{
		if (i < ANIMAL_COUNT / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < ANIMAL_COUNT; i++)
	{
		delete animals[i];
	}
    cout << endl << "--- DEEP COPY TEST ---" << endl;
	deepCopyTest();
    return 0;
}
