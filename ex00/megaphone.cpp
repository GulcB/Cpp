#include <iostream>
#include <ctype.h>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;

int main(int ac, char **av)
{

	if (ac < 2)
		return (0);
	for(int i=0; i < ac; i++)
	{
		cout << av[i] << endl;
	}
	return (0);
}