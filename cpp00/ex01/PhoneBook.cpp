/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:57:08 by gbodur            #+#    #+#             */
/*   Updated: 2025/11/17 12:56:12 by gbodur           ###   ########.fr       */
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

bool	PhoneBook::input_check(string prompt, string &result, bool phone_num)
{
	bool has_non_ascii;
	bool valid_number;
	unsigned char c;
	
	while (true)
	{
		has_non_ascii = false;
		
		cout << "Please, enter the " << prompt << ": " << endl;
		getline(cin, result);
		if (cin.fail())
		{
			cout << "\nInput cancelled. Returning to main menu." << endl;
			return (false);
		}
		if (result.empty())
		{
			cout << "You supposed to give a detail, table cannot be empty. " << endl;
			continue;
			
		}
		if (phone_num)
		{
			valid_number = true;
			for (size_t i = 0; i < result.length(); i++)
			{
				if (!isdigit(result[i]))
				{
					valid_number = false;
					break;
				}
			}
			if (!valid_number)
			{
				cout << "Phone number must contain only digits (0-9)." << endl;
                continue;
			}
		}
		for (size_t i = 0; i < result.length(); i++)
        {
			c = static_cast<unsigned char>(result[i]);
            if (c > 127)
            {
                has_non_ascii = true;
                break;
            }
		}
		if (has_non_ascii)
        {
            cout << "Input contains non-ASCII (e.g., Turkish) characters." << endl;
            cout << "Please use only standard English characters." << endl;
            continue; 
        }
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
		bool	check_digit = (i == 3);
		
		if (!input_check(prompts[i], temp_data, check_digit))
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
	int		search_i;
	
	while (true)
	{
		cout << "Please, choose a specific line (1-" << this->_contact_count << "):" << endl;
		cin >> search_i;
		if (cin.fail())
		{
			cout << "\nExit request has been detected. See you!." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		else if (search_i < 1 || search_i > this->_contact_count)
		{
			cout << "Your choose is empty or out of range. My range between 1 to 8." << endl;
			continue;
		}
		else
			break ;
	}
	const Contact& C = this->_contact[search_i - 1];
	cout << endl;
    cout << "--- Contact Details ---" << endl;
    cout << "First Name:     " << C.getFirstName() << endl;
    cout << "Last Name:      " << C.getLastName() << endl;
    cout << "Nickname:       " << C.getNickname() << endl;
    cout << "Phone Number:   " << C.getPhoneNumber() << endl;
    cout << "Darkest Secret: " << C.getDarkestSecret() << endl;

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
			given_nickname = given_nickname.substr(0, 9) + ".";
		cout << setw(10) << given_nickname << "|";

		cout << endl;

	}
	detail_search();
}

int main(int argc, char **argv)
{
	PhoneBook	mydata;
	string		command;
	
	(void)argv;
	
	if (argc != 1)
		return (1);
	while(true)
	{
		cout << "Please, enter what will you do as ADD, SEARCH or EXIT: ";
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
