/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:19:35 by vburton           #+#    #+#             */
/*   Updated: 2023/07/19 14:25:20 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::Zombie(const std::string &name) : _name(name){
        std::cout << "Zombie " << _name << " created" << std::endl;
}

Zombie::~Zombie(void){
    std::cout << "Zombie " << _name << " destroyed" << std::endl;
}

void    Zombie::announce(void){
    std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(const std::string &name){
    this->_name = name;
}