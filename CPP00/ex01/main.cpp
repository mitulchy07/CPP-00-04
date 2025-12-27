
#include "Contact.hpp"
#include "PhoneBook.hpp"

/**
* @brief	Entry point of the program.
*			This function acts as the user interface for the phonebook app.
*			It handles user input and calls the appropriate PhoneBook methods.
*			Possible user commands:
*			- ADD: Prompts the user to add a new contact. Delegates the logic
*			to PhoneBook::add()
*			- SEARCH: Displays a summary table of stored contacts. Then asks
*			the user to enter an index and displays the full contact details.
*			Delegates the logic to PhoneBook::search().
*			- EXIT: Exits the program gracefully
*			
*/

int	main(void)
{
	PhoneBook myPhoneBook;
	std::string command;
	bool	continueProgram;

	std::cout << "Welcome to your PhoneBook!" << std::endl;
	std::cout << "Choose the action: ADD, SEARCH, EXIT" << std::endl;

	continueProgram = true;
	while (continueProgram)
	{
		std::cout << "> ";
		std::getline(std::cin, command);

		if (std::cin.eof())
		{
			std::cout << "\nEOF detected. Exiting ..." << std::endl;
			continueProgram = false;
		}
		else if (command == "ADD")
			myPhoneBook.add();
		else if (command == "SEARCH")
			myPhoneBook.search();
		else if (command == "EXIT")
		{
			std::cout << "See you soon!" << std::endl;
			continueProgram = false;
		}
		else
		{
			std::cout << "Invalid command. Try again." << std::endl;
		}	
	}
	return (0);
}
