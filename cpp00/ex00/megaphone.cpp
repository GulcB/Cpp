#include <iostream>
#include <ctype.h>
#include <string.h>

using std::cout;
using std::endl;

int main(int ac, char **av)
{
	char upper_case;

	if (ac < 2)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return (0);
	}
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; av[i][j]; j++)
		{
			upper_case = toupper(av[i][j]);
			cout << upper_case;
		}
	}
	cout << endl;
	return (0);
}
