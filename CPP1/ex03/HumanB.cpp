/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:07:37 by vburton           #+#    #+#             */
/*   Updated: 2023/07/20 14:14:51 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name): _name(name){
	_weapon = NULL;
}

HumanB::~HumanB(){}

void	HumanB::attack(void){
	if (!this->_weapon)
		std::cout << _name << " don't have any weapon to attack." << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &newWeapon){
	this->_weapon = &newWeapon;
}


