#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

static int getContactField(std::string *fieldContent, const std::string& identifier){
    std::cout << identifier << ":";
    std::getline(std::cin, *fieldContent);
    if (std::cin.eof())
        return (1);
    while(fieldContent->empty())
    {
        std::cout << "A contact can't have empty field" << std::endl;
        std::cout << identifier << ": ";
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

    std::cin >> choice;
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
            std::cout << choice << ": is not a valid command" << std::endl;
            PhoneBook::displayCommands();
        }
    }

    return (0);
}