#include <iostream>
#include "PhoneBook.hpp"

void    displayCommands();
void    PhoneBook::printPhoneBook();
void    PhoneBook::getContact(int contactIndex) const;
void    PhoneBook::getContactInfo() const;
void    PhoneBook::addContact(const Contact& newContact);


PhoneBook::PhoneBook(void) : _currentSize(0), _lastContactIndex(0){}

PhoneBook::~PhoneBook(void){}

void    PhoneBook::addContact(const Contact& newContact){
    if (this->_currentSize < PHONEBOOK_SIZE)
    {
        this->_contacts[_currentSize] = newContact;
        _currentSize++;
        return ;
    }
    this->_contacts[_lastContactIndex] = newContact;
    this->_lastContactIndex = (this->_lastContactIndex + 1) % PHONEBOOK_SIZE;
        
}

void    PhoneBook::getContactInfo() const{
    std::string indexInput;
    int entryIndex = -1;

    while (entryIndex == -1){
        std::cout << "contact index to display: ";
        std::getline(std::cin, indexInput);
        if (std::cin.eof())
            return;
        if (indexInput.length() == 1 && std::isdigit(indexInput[0])) {
            std::istringstream s(indexInput);
            s >> entryIndex;
            if (entryIndex > this->_currentSize - 1){
                std::cout << indexInput << " is not a valid index, please give an index between 0 and " << this->_currentSize - 1 << std::endl;
                entryIndex = -1;
            }
        }
        else
        {
            std::cout << indexInput << " is not a valid index, please give an index between 0 and " << this->_currentSize - 1 << std::endl;
            indexInput.clear();
        }
        Contact contact = this->getContact(entryIndex);
        std::cout << std::setw(15) << std::right << std::setfill(' ') << "First Name: " << contact.getFirstName() << std::endl;
        std::cout << std::setw(15) << std::right << std::setfill(' ') << "Last Name: " << contact.getLastName() << std::endl;
        std::cout << std::setw(15) << std::right << std::setfill(' ') << "Nickname: " << contact.getNickName() << std::endl;
        std::cout << std::setw(15) << std::right << std::setfill(' ') << "Phone number: " << contact.getPhoneNumber() << std::endl;
        std::cout << std::setw(15) << std::right << std::setfill(' ') << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
    }
}

void    PhoneBook::getContact(int contactIndex) const{
    return this->_contact[contactIndex];
}

void    PhoneBook::printPhoneBook(){
    if (this->_currentSize == 0)
    {
        std::cout << "Your phonebook is empty" << std::endl;
        return ;
    }
    Contact::printLine("INDEX");
    Contact::printLine("FIRST NAME");
    Contact::printLine("LAST NAME");
    Contact::printLine("NICKNAME");
    std::cout << std::endl;
    for (int i = 0; i < this->_currentSize; i++)
    {
        std::cout << std::setw(10) << std::right << std::setfill(' ') << i << "|";
        this->getContact(i).printContactInfo();
    }
    this->getContactInfo();
}

void    displayCommands(){
    std::cout << "You're option are :" << std::endl;
    std::cout << "ADD : To save a new contact in your phonebook" << std::endl;
    std::cout << "SEARCH : To display the information of one specific contact already in your phonebook" << std::endl;
    std::cout << "EXIT : if you want to close your phonebook" << std::endl; 
}