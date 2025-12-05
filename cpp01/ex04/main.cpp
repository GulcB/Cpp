/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:58:01 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/05 17:33:18 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.hpp"

using   std::cout;
using   std::cerr;
using   std::endl;

int main(int argc, char **argv)
{
    string  filename;
    string  s1;
    string  s2;

    if (argc != 4)
    {
        cerr << "Usage: <./program name> <filename> <word that will find> <word that will change>" << endl;
        return (1);
    }
    filename = argv[1];
    cout << "filename is: " << filename << endl;
    s1 = argv[2];
    cout << "s1 is: " << s1 << endl;
    s2 = argv[3];
    cout << "s2 is: " << s2 << endl;
    
    SedIsForLosers  sed_command(filename);
    sed_command.ft_replace(s1, s2);
    
    return (0);
}