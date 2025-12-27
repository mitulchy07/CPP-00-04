
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string> //std::string
# include <iostream>	//std::cin, std::cout, std::endl

class Contact {
	public:
		//-----------------------CONSTRUCTOR/DESTRUCTOR  -----------------------
		Contact(); //Constructor: initializes a new contact
		~Contact(); //Destructor

		//-----------------------PUBLIC ATRIBUTES        -----------------------
		int			index;			//Contact index (1-8) 
		std::string firstName;		//First name
		std::string lastName;		//Last name
		std::string nickname;		//Nickname
		std::string phoneNumber;	//Phone number
		std::string darkestSecret;	//Darkest secret
};

#endif