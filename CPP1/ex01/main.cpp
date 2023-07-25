/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:17:17 by vburton           #+#    #+#             */
/*   Updated: 2023/07/25 09:47:48 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main(void){
    
    int sizeHorde = 5;
    Zombie zombie("regular zombie");
    zombie.announce();
    Zombie *horde = zombieHorde(sizeHorde, "Horde de Zombies");
    if (!horde){
        std::cout << "failed to alloc an horde of zombies" << std::endl;
        return (1);
    }
    for(int i = 0; i < sizeHorde; i++){
        horde[i].announce();
    }
    delete[] horde;
    return (0);
}