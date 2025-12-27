
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"	//Contact class
# include <iostream>	//std::cin, std::cout, std::endl
# include <string>		//std::string
# include <sstream>		//std::istringstream (convert strings to numbers)
# include <iomanip>		//std::setw (column alignment for output)

class PhoneBook {
	private:
		Contact _contacts[8];	//Array to store up to 8 contacts
		int		_totalContacts;	//Total number contacts (used for circular buffer)
		
		//-----------------------PRIVATE HELPER FUNCTIONS-----------------------
		std::string	_getNonEmptyInput(const std::string& prompt);
		void		_printTableHeader();
		std::string _truncate(const std::string& str, std::size_t width);
		void		_printContactRow(const Contact& contact);
		int			_getValidIndex(int validContactsCount);
		void		_printFullContact(const Contact& contact);
	
	public: 
		//-----------------------CONSTRUCTOR/DESTRUCTOR  -----------------------
		PhoneBook();		//Constructor: initialize _totalContacts to 0
		~PhoneBook();		//Destructor

		//-----------------------PUBLIC FUNCTIONS        -----------------------		
		void	add();		//Add a new contact
		void	search();	//Search for a contact and display full info
};

#endif