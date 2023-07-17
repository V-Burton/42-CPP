#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <sstream>
# include "Contact.hpp"

#define PHONEBOOK_SIZE	8
#define END				"\033[0m"
#define BOLD			"\033[1m"
#define UNDERLINE		"\033[4m"
#define BLUE			"\033[34m"
#define YELLOW			"\033[33m"
#define CYAN			"\033[36m"
#define GREEN			"\033[32m"
#define RED				"\033[31m"

class PhoneBook
{
    public:

   		PhoneBook(void);
    	~PhoneBook(void);
    	void    addContact(const Contact& newContact);
    	void    printPhoneBook() const;
    	void    getContactInfo() const;

    	static void	displayCommands();

    private:
        Contact _contacts[PHONEBOOK_SIZE];
        int     _currentSize;
        int     _lastContactIndex;

       Contact	getContact(int contactIndex) const;

};

#endif
