/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:18:01 by vburton           #+#    #+#             */
/*   Updated: 2023/07/19 14:37:12 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    if (N < 1){
        std::cout << "less than 2 zombies isn't a horde of zombies..." << std::endl;
        return (NULL);
    }
    Zombie *horde = new Zombie[N];
    if (!horde){
        std::cout << "failed to alloc an horde of zombies" << std::endl;
        return (NULL);
    }
    for (int i = 0; i < N; i++){
        horde[i].setName(name);
    }
    return (horde);
}