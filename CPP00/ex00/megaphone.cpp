#include <iostream>

/**
* @brief	Takes the command-line arguments and prints them to the stdout
*			in uppercase letters. If no arguments are provided, it prints
*			a default message.
*			- If no additional arguments are provided (argc == 1):
*				* Prints the default msg
*			- Otherwise, for each argument (argv[1] to argv[argc-1]):
*				* Iterates through each character of the argument
*				* Convert each char to uppercase with std::toupper
*				* Prints the char
*				* After each argument, prints a space
*			- Finally, prints a newline character
*
* @param argc	The number of commnad-line arguments
* @param argv	Array of command-line arguments as C-style strings
* @return int	Always returns 0 to indicate successful execution.
*/

int main(int argc, char **argv)
{
	int argumentIndex;
	int characterIndex;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (argumentIndex = 1; argumentIndex < argc; argumentIndex++)
		{
			for(characterIndex = 0; argv[argumentIndex][characterIndex]; characterIndex++)
				std::cout << (char) std::toupper(argv[argumentIndex][characterIndex]);
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (0);
}