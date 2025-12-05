/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedIsForLosers.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:10:04 by gbodur            #+#    #+#             */
/*   Updated: 2025/12/05 17:33:00 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.hpp"

using   std::ofstream;
using   std::ifstream;
using   std::cerr;
using   std::endl;
using   std::getline;
using   std::find;

SedIsForLosers::SedIsForLosers(const string &filename) : _filename(filename)
{
}

SedIsForLosers::~SedIsForLosers()
{
}

void    SedIsForLosers::ft_replace(string s1, string s2)
{
    string  content = "";
    string  line;
    size_t  pos = 0;
    size_t  foundPos = 0;

    ifstream infile(this->_filename.c_str());
    if (!infile.is_open())
    {
        cerr << "Error: Infile could not open." << endl;
        return;
    }
    while(getline(infile, line))
    {
        content += line;
        if (!infile.eof())
            content += "\n";
        
    }
    infile.close();
    ofstream outfile((this->_filename + ".replace").c_str());
    if (!outfile.is_open())
    {
        cerr << "Error: Outfile could not open." << endl;
        return;
    }
    while(true)
    {
        foundPos = content.find(s1, pos);
        if (foundPos == string::npos)
            break;
        outfile << content.substr(pos, foundPos - pos);
        outfile << s2;
        pos = foundPos + s1.length();
    }
    outfile << content.substr(pos);
    outfile.close();
}