/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:23:09 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/26 12:08:01 by gbodur           ###   ########.fr       */
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
	const Animal *cat = new Cat();
	const Animal *dog = new Dog();
	
	cout << cat->getType() << " " << "Sound: ";
    cat->makeSound(); 
	cout << dog->getType() << " " << "Sound: ";
    dog->makeSound();
	cout << animal->getType() << " " << "Sound: ";
    animal->makeSound();

    cout << endl << "--- WRONG ANIMAL TEST ---" << endl;
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
	
    cout << wrongCat->getType() << " " << "Sound: ";
    wrongCat->makeSound(); 
    cout << wrongAnimal->getType() << " " << "Sound: ";
    wrongAnimal->makeSound();
	cout << "-------------------------------------------------------------" << endl;
    delete animal;
    delete dog;
    delete cat;
    delete wrongAnimal;
    delete wrongCat;

    return (0);
}
