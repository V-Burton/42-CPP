#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

static int getContactField(std::string *fieldContent, const std::string& identifier){
    std::cout << "\t" << BOLD << UNDERLINE << identifier << END << ":";
    std::getline(std::cin, *fieldContent);
    if (std::cin.eof())
        return (1);
    while(fieldContent->empty())
    {
        std::cout << RED << BOLD "A contact can't have empty field" << END << std::endl;
        std::cout << "\t" << BOLD << UNDERLINE << identifier << END << ":";
        std::getline(std::cin, *fieldContent);
    }
    return (0);
}

static void addContact(PhoneBook *phoneBook){

    std::string contactInformation[5];

    if (getContactField(&contactInformation[0], "First Name"))
        return;
    if (getContactField(&contactInformation[1], "Last Name"))
        return;
    if (getContactField(&contactInformation[2], "Nickname"))
        return;
    if (getContactField(&contactInformation[3], "Phone number"))
        return;
    if (getContactField(&contactInformation[4], "Darkest secret"))
        return;
    Contact newContact(contactInformation);
    phoneBook->addContact(newContact);
}

int main(void){

    std::string choice;
    PhoneBook phoneBook;

	std::cout << GREEN << "Welcome to your Awesome PhoneBook" << END << std::endl;
	PhoneBook::displayCommands();
    while (true)
    {
        std::cout << "Enter a command: ";
        std::getline(std::cin, choice);
        if (std::cin.eof())
            return (1);
        if (choice == "ADD")
            addContact(&phoneBook);
        else if (choice == "SEARCH")
            phoneBook.printPhoneBook();
        else if (choice == "EXIT")
            return (0);
        else
        {
            std::cout << RED << BOLD << choice << ": is not a valid command" << END << std::endl;
            PhoneBook::displayCommands();
        }
    }

    return (0);
}
