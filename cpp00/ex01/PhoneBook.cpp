/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:57:08 by gbodur            #+#    #+#             */
/*   Updated: 2025/11/16 18:35:16 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

using	std::cin;
using	std::cout;
using	std::getline;
using	std::endl;
using	std::string;
using	std::setw;
using	std::right;

PhoneBook::PhoneBook()
{
	this->_check = 0;
	this->_contact_count = 0;
}

bool	PhoneBook::input_check(string prompt, string &result)
{
	
	while (true)
	{
		cout << "Please, enter the " << prompt << ": " << endl;
		getline(cin, result);
		if (cin.fail())
		{
			cout << "\nInput cancelled. Returning to main menu." << endl;
			return (false);
		}
		if (result.empty())
			cout << "You supposed to give a detail, table cannot be empty. " << endl;
		else
			break ;
	}
	return (true); 
}
void PhoneBook::addContact()
{
	string	prompts[5] = 
	{
		"first name",
		"last name",
		"nickname",
		"phone number",
		"darkest secret"	
	};
	
	string	temp_data;
	
	if (this->_check == 8)
		this->_check = 0;

	for(int i = 0; i < 5; i++)
	{
		if (!input_check(prompts[i], temp_data))
			return;

		switch (i)
		{
			case 0:
				this->_contact[this->_check].setFirstName(temp_data);
				break ;
			case 1:
				this->_contact[this->_check].setLastName(temp_data);
				break ;
			case 2:
				this->_contact[this->_check].setNickname(temp_data);
				break ;
			case 3:
				this->_contact[this->_check].setPhoneNumber(temp_data);
				break ;
			case 4:
				this->_contact[this->_check].setDarkestSecret(temp_data);
				break ;
		}
	}
	this->_check++;
	if (this->_contact_count < 8)
    	this->_contact_count++;
	cout << "Contact has been added successfully, easy peasy" << endl;
}

void	PhoneBook::detail_search() const
{
	string	temp_name;
	string	temp_surname;
	string	temp_nickname;
	string	temp_number;
	string	temp_secret;
	int		search_i;
	string	title[6] = 
	{
		"index",
		"first name",
		"last name",
		"nickname",
		"phone number",
		"darkest secret",
	};
	cout << "Please, choose a specific line" << endl;
	cin >> search_i;
	if (cin.fail())
	{
		cout << "\nExit request has been detected. See you!." << endl;
		return ;
	}
	if (search_i < 1 || search_i > this->_contact_count)
	{
		cout << "Please, ask a valid line" << endl;
		detail_search();
	}
	cout << endl;
	cout << right;
	cout << "     -------------------------------------------------------------" << endl;
	for (int i = 0; i < 6; i++)
	{
		if (title[i].length() > 10)
			title[i] = title[i].substr(0, 9) + ".";
		cout << setw(10) << title[i] << "|"; 
	}
	cout << endl;
	cout << "     -------------------------------------------------------------" << endl;
	cout << setw(10) << search_i << "|";
	temp_name =  this->_contact[search_i - 1].getFirstName();
	if (temp_name.length() > 10)
		temp_name = temp_name.substr(0, 9) + ".";
	cout << setw(10) << temp_name << "|";
	
	temp_surname = this->_contact[search_i - 1].getLastName();
	if (temp_surname.length() > 10)
		temp_surname = temp_surname.substr(0, 9) + ".";
	cout << setw(10) << temp_surname << "|";
	
	temp_nickname = this->_contact[search_i - 1].getNickname();
	if (temp_nickname.length() > 10)
		temp_nickname = temp_nickname.substr(0 ,9) + ".";
	cout << setw(10) << temp_nickname << "|";
	
	temp_number = this->_contact[search_i - 1].getPhoneNumber();
	if (temp_number.length() > 10)
		temp_number = temp_number.substr(0, 9) + ".";
	cout << setw(10) << temp_number << "|";
	
	temp_secret = this->_contact[search_i - 1].getDarkestSecret();
	if (temp_secret.length() > 10)
		temp_secret = temp_secret.substr(0, 9) + ".";
	cout << setw(10) << temp_secret << "|";
	cout << endl;

}

void	PhoneBook::searchContact() const
{
	string	given_name;
	string	given_surname;
	string	given_nickname;
	string	content[4] =
	{
		"index",
		"first name",
		"last name",
		"nickname",
	};
	
	cout << right;
	
	cout << "     ---------------------------------------" << endl;
	for (int j = 0; j < 4; j++)
	{
		if (content[j].length() > 10)
			content[j] = content[j].substr(0, 9) + ".";
		cout << setw(10) << content[j] << "|";
	}
	cout << endl;
	cout << "     ---------------------------------------" << endl;
	for(int i = 0; i < 8; i++)
	{
		cout << setw(10) << i + 1 << "|";
		
		given_name =  this->_contact[i].getFirstName();
		if (given_name.length() > 10)
			given_name = given_name.substr(0, 9) + ".";
		cout << setw(10) << given_name << "|";

		given_surname = this->_contact[i].getLastName();
		if (given_surname.length() > 10)
			given_surname = given_surname.substr(0, 9) + ".";
		cout << setw(10) << given_surname << "|";


		given_nickname = this->_contact[i].getNickname();
		if (given_nickname.length() > 10)
			given_nickname = given_nickname.substr(0 ,9) + ".";
		cout << setw(10) << given_nickname << "|";

		cout << endl;

	}
	detail_search();
}

int main()
{
	PhoneBook	mydata;
	string		command;
	
	while(true)
	{
		cout << "Please, enter what will you do as ADD, SEARCH or EXIT: "<< endl;
		cin >> command;
		if (cin.fail())
		{
			cout << "See you another world, goodbye! " << endl;
			break;
		}
		if (command ==  "ADD")
		{
			cin.ignore();
			mydata.addContact();
		}
		else if (command ==  "SEARCH")
			mydata.searchContact();
		else if (command ==  "EXIT")
			break ;
	}
	return (0);
}
