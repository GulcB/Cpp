/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:54:18 by gbodur            #+#    #+#             */
/*   Updated: 2025/11/16 18:54:15 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

using std::string;

class Contact
{
	private:
		string	first_name;
		string	last_name;
		string	nickname;
		string	phone_number;
		string 	darkest_secret;
	public:
		void setFirstName(string first_name);
		void setLastName(string last_name);
		void setNickname(string nickname);
		void setPhoneNumber(string phone_number);
		void setDarkestSecret(string darkest_secret);
		string getFirstName() const;
		string getLastName() const;
		string getNickname() const;
		string getPhoneNumber() const;
		string getDarkestSecret() const;
};

#endif