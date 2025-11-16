/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:55:29 by gbodur            #+#    #+#             */
/*   Updated: 2025/11/16 19:11:33 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

using std::string;

class PhoneBook
{
	private:
		Contact _contact[8];
		int     _contact_count;
		int	_check;
		
	public:
		PhoneBook();
		void	addContact() ;
		void	searchContact() const;
		bool	input_check(string prompt, string &result);
		void	detail_search() const;
		
};

#endif