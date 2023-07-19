/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:52:29 by vburton           #+#    #+#             */
/*   Updated: 2023/07/19 18:29:15 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon): _name(name), _weapon(weapon){}

HumanA::~HumanA(){}

void	HumanA::attack(){
	std::cout << _name << " attacks with their " << _weapon.getType() <<std::endl;
}
