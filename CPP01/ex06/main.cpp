#include "Harl.hpp"
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
		return (1);
	}

	Harl	harl;
	std::string	level = argv[1];

	int	level_index = -1;

	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			level_index = i;
			break ;
		}
	}

	if (level_index == -1)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (0);
	}

	switch (level_index)
	{
		case 0:
			harl.complain("DEBUG");
			std::cout << std::endl;
		case 1:
			harl.complain("INFO");
			std::cout << std::endl;
		case 2:
			harl.complain("WARNING");
			std::cout << std::endl;
		case 3:
			harl.complain("ERROR");
			break ;
	}

	return (0);
}
