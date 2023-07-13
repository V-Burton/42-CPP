#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <sstream>
# include "Contact.hpp"

#define PHONEBOOK_SIZE 8

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