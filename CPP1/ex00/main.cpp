/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:13:19 by vburton           #+#    #+#             */
/*   Updated: 2023/07/18 10:30:10 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void    randomChump(std::string name);

int main(void){
    Zombie zombie("foo");
    zombie.announce();
    Zombie *newOne = newZombie("newZombieOnHeap");
    if(!newOne){
        std::cerr << "Failed to creat zombie" << std::endl;
    }
    newOne->announce();
    delete(newOne);
    randomChump("RandomZombieOnStack");
    return (0);
}