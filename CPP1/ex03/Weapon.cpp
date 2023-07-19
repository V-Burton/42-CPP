/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:50:50 by vburton           #+#    #+#             */
/*   Updated: 2023/07/19 18:32:12 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &weapon): _type(weapon){}

Weapon::~Weapon(void){}


std::string Weapon::getType(void){
	std::string type = this->_type;
	return (type);
}

void	Weapon::setType(const std::string &newWeapon){
	this->_type = newWeapon;
}

