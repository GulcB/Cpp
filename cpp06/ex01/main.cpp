/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:40:24 by gbodur            #+#    #+#             */
/*   Updated: 2026/03/28 12:27:10 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::stringstream;

static bool parseInt(char *arg, int &output)
{
	stringstream	ss;

	ss << arg;
	ss >> output;
	if (ss.fail() || !ss.eof())
		return (false);
	return (true);
}

static bool parseDouble(char *arg, double &output)
{
	stringstream	ss;

	ss << arg;
	ss >> output;
	if (ss.fail() || !ss.eof())
		return (false);
	return (true);
}

int main(int argc, char **argv)
{
	Data		data;
	uintptr_t	raw;
	Data		*decodedData;

	if (argc != 4)
	{
		cerr << "Error: Invalid number of arguments." << endl;
		cerr << "Usage: ./serializer <name> <id> <score>" << endl;
		return (1);
	}
	if (argv[1][0] == '\0')
	{
		cerr << "Error: Name cannot be empty." << endl;
		return (1);
	}
	if (!parseInt(argv[2], data.id))
	{
		cerr << "Error: Id must be a pure integer within int range." << endl;
		return (1);
	}
	if (!parseDouble(argv[3], data.score))
	{
		cerr << "Error: Score must be a valid number." << endl;
		return (1);
	}
	data.name = argv[1];
	raw = Serializer::serialize(&data);
	decodedData = Serializer::deserialize(raw);
	cout << "--- ORIGINAL DATA ---" << endl;
	cout << "Address: " << static_cast<void *>(&data) << endl;
	cout << "Name: " << data.name << endl;
	cout << "Id: " << data.id << endl;
	cout << "Score: " << data.score << endl;
	cout << "\n--- SERIALIZED VALUE ---" << endl;
	cout << raw << endl;
	cout << "\n--- DESERIALIZED DATA ---" << endl;
	cout << "Address: " << static_cast<void *>(decodedData) << endl;
	cout << "Name: " << decodedData->name << endl;
	cout << "Id: " << decodedData->id << endl;
	cout << "Score: " << decodedData->score << endl;
	cout << "\n--- RESULT ---" << endl;
	if (decodedData == &data)
		cout << "Serialization test passed." << endl;
	else
		cout << "Serialization test failed." << endl;
	return (0);
}
