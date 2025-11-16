/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:12:37 by gbodur            #+#    #+#             */
/*   Updated: 2025/11/11 21:33:36 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(string first_name)
{
	this->first_name = first_name;
}

void	Contact::setLastName(string last_name)
{
	this->last_name = last_name;
}

void	Contact::setNickname(string nickname)
{
	this->nickname = nickname;
}

void	Contact::setPhoneNumber(string phone_number)
{
	this->phone_number = phone_number;
}

void	Contact::setDarkestSecret(string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

string Contact::getFirstName() const
{
	return (this->first_name);
}

string	Contact::getLastName() const
{
	return (this->last_name);
}

string	Contact::getNickname() const
{
	return (this->nickname);
}

string	Contact::getPhoneNumber() const
{
	return (this->phone_number);
}

string	Contact::getDarkestSecret() const
{
	return (this->darkest_secret);
}