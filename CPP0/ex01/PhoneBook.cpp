/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:19:23 by vburton           #+#    #+#             */
/*   Updated: 2023/07/17 11:19:24 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

// void    displayCommands();
// void    PhoneBook::printPhoneBook();
// void    PhoneBook::getContact(int contactIndex) const;
// void    PhoneBook::getContactInfo() const;
// void    PhoneBook::addContact(const Contact& newContact);


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
        std::cout << GREEN << "Contact index to display: " << END;
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
            std::cout << indexInput << " is not a valid index, please give an index between 0 and " << this->_currentSize - 1 << std::endl;
        indexInput.clear();
    }
    Contact contact = this->getContact(entryIndex);
    std::cout << BOLD << "\tFirst Name: " << END << contact.getFirstName() << std::endl;
    std::cout << BOLD << "\tLast Name: " << END << contact.getLastName() << std::endl;
    std::cout << BOLD << "\tNickname: " << END << contact.getNickname() << std::endl;
    std::cout << BOLD << "\tPhone number: " << END << contact.getPhoneNumber() << std::endl;
    std::cout << BOLD << "\tDarkest Secret: " << END << contact.getDarkestSecret() << std::endl;
}

Contact    PhoneBook::getContact(int contactIndex) const {
    return this->_contacts[contactIndex];
}

void    PhoneBook::printPhoneBook() const{
    if (this->_currentSize == 0)
    {
        std::cout << RED << BOLD << "Your phonebook is empty" << END << std::endl;
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

void    PhoneBook::displayCommands(){
    std::cout << "You're option are :" << std::endl;
    std::cout << CYAN << BOLD << "\tADD :" << END << " To save a new contact in your phonebook" << std::endl;
    std::cout << CYAN << BOLD << "\tSEARCH :" << END << " To display the information of one specific contact already in your phonebook" << std::endl;
    std::cout << CYAN << BOLD << "\tEXIT :" << END << " If you want to close your phonebook" << std::endl;
}
