/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedIsForLosers.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:10:23 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/04 19:32:32 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDISFORLOSERS_HPP
#define SEDISFORLOSERS_HPP

#include <string>
#include <fstream>
#include <iostream>

using   std::string;

class SedIsForLosers
{
    private:
        string  _filename;
    public:
        SedIsForLosers(const string &filename);
        ~SedIsForLosers();
        void    ft_replace(string s1, string s2);
};

#endif