/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:13:13 by vburton           #+#    #+#             */
/*   Updated: 2023/07/18 09:55:05 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string &name) : _name(name) {
    std::cout << "Zombie " << _name << " created" << std::endl;
}

Zombie::~Zombie(void){
    std::cout << _name << " is definitly dead and destroyed itself" << std::endl;
}

void    Zombie::announce() const{
    std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}