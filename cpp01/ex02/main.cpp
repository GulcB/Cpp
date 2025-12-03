/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:29:18 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/03 16:19:11 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

using   std::string;
using   std::cout;
using   std::endl;

int main (int argc, char **argv)
{
    string  *stringPTR = NULL;
    string  init = "HI THIS IS BRAIN";;
    string  &stringREF = init;
    stringPTR = &init;
    
    (void) argv;
    if (argc != 1)
        return (1);
    cout << "---------- address ----------" << endl;
    cout <<  "variable: " << &init << endl;
    cout <<  "pointer: " << stringPTR << endl;
    cout <<  "reference: " << &stringREF << endl;
    cout << "---------- value ----------" << endl;
    cout << "variable: " << init << endl;
    cout <<  "pointer: " << *stringPTR << endl;
    cout <<  "reference: " << stringREF << endl;
    return (0);
}