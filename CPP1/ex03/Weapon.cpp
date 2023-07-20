/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:50:50 by vburton           #+#    #+#             */
/*   Updated: 2023/07/20 19:06:10 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &weapon): _type(weapon){}

Weapon::~Weapon(void){}


const std::string &Weapon::getType(void) const{
	return (this->_type);
}

void	Weapon::setType(const std::string &newWeapon){
	this->_type = newWeapon;
}

