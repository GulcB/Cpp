/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:23:09 by gbodur            #+#    #+#             */
/*   Updated: 2026/01/29 12:58:17 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

using std::stringstream;

void deepCopyTest()
{
	cout << "--- Real Dog ---" << endl;
    Dog original;
    cout << "--- Copy Dog ---" << endl;
    {
        Dog copy = original;
    }
	cout << endl;
	cout << "--- Real Cat ---" << endl;
	Cat real;
    cout << "--- Copy Cat ---" << endl;
    {
        Cat fake = real;
    }
}

int main(int argc, char **argv)
{
	long long tempCount;
	int animalCount;
	stringstream ss;

	animalCount = 0;
	tempCount = 0;
	if (argc != 2)
	{
		cout << "You have to give an even number for animal amount." << endl;
		cout << "Usage: ./brain <number_of_animals>" << endl;
		return (1);
	}
	ss << argv[1];
	ss >> tempCount;
	if (ss.fail() || tempCount > INT_MAX || tempCount < 0)
	{
		cout << "Animal amount should be between integer maximum and minimum." << endl;
		return (1);
	}
	if (tempCount > 1000) 
    {
        cout << "That's too many animals! Try something smaller." << endl;
        return (1);
    }
	animalCount = static_cast<int>(tempCount);
	if (animalCount % 2 != 0 || animalCount < 2)
	{
		cout << "Animal amount should be a positive even number greater than or equal to 2." << endl;
		return (1);
	}
	cout << "--- SINGLE INSTANCE TEST ---" << endl;
	const AAnimal *cat = new Cat();
	const AAnimal *dog = new Dog();
	cout << cat->getType() << " " << "Sound: ";
    cat->makeSound(); 
	cout << dog->getType() << " " << "Sound: ";
    dog->makeSound();
	
    cout << endl << "--- WRONG Animal TEST ---" << endl;
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
	
    cout << wrongCat->getType() << " " << "Sound: ";
    wrongCat->makeSound(); 
    cout << wrongAnimal->getType() << " " << "Sound: ";
    wrongAnimal->makeSound();
	cout << "-------------------------------------------------------------" << endl;

    delete cat;
    delete dog;
    delete wrongAnimal;
    delete wrongCat;

	cout << "--- ARRAY OF ANIMALS TEST (" << animalCount << " animals) ---" << endl;
	const AAnimal **animals = new const AAnimal*[animalCount];
	for (int i = 0; i < animalCount; i++)
	{
		if (i < animalCount / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	cout << "--- DELETE ARRAY ---" << endl;
	for (int i = 0; i < animalCount; i++)
	{
		delete animals[i];
	}
	delete [] animals;
	cout << "--- DEEP COPY TEST ---" << endl;
	deepCopyTest();
    return (0);
}
