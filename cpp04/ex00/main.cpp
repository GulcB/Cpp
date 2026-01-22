/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:23:09 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/22 11:25:04 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	cout << "--- SUBJECT TEST ---" << endl;
	const Animal *animal = new Animal();
	const Animal *i = new Cat();
	const Animal *j = new Dog();
	
	cout << i->getType() << " " << endl;
	cout << j->getType() << " " << endl;

	cout << "Cat Sound: ";
    i->makeSound(); 
    cout << "Dog Sound: ";
    j->makeSound();
    cout << "Animal Sound: ";
    animal->makeSound();

    cout << endl << "--- WRONG ANIMAL TEST ---" << endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
	
    cout << "wrongCat type: " << wrongCat->getType() << endl;

    cout << "WrongCat Sound: ";
    wrongCat->makeSound(); 

    cout << "WrongAnimal Sound: ";
    wrongMeta->makeSound();

    delete animal;
    delete j;
    delete i;
    delete wrongMeta;
    delete wrongCat;

    return 0;
}
