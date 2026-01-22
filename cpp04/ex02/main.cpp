/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:23:09 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/22 15:45:28 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
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
	original.makeSound();
}

int main()
{
	cout << "--- SINGLE INSTANCE TEST ---" << endl;
	const AAnimal *cat = new Cat();
	const AAnimal *dog = new Dog();
	
	cout << "Cat Type: " << cat->getType() << endl;
	cout << "Dog Type: " << dog->getType() << endl;

	cout << "Cat Sound: ";
    cat->makeSound(); 
    cout << "Dog Sound: ";
    dog->makeSound();

    cout << endl << "--- WRONG Animal TEST ---" << endl;
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
	
    cout << "wrongCat type: " << wrongCat->getType() << endl;
    cout << "WrongCat Sound: ";
    wrongCat->makeSound(); 
    cout << "WrongAnimal Sound: ";
    wrongAnimal->makeSound();

    delete cat;
    delete dog;
    delete wrongAnimal;
    delete wrongCat;

	cout << "--- ARRAY OF ANIMALS TEST ---" << endl;
	const AAnimal *animals[ANIMAL_COUNT];
	for (int i = 0; i < ANIMAL_COUNT; i++)
	{
		if (i < ANIMAL_COUNT / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	cout << "--- DELETE ARRAY ---" << endl;
	for (int i = 0; i < ANIMAL_COUNT; i++)
	{
		delete animals[i];
	}
	deepCopyTest();
    return 0;
}
