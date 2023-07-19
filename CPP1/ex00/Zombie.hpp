/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:13:09 by vburton           #+#    #+#             */
/*   Updated: 2023/07/19 14:17:39 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Zombie
{
    public:
        Zombie(const std::string &name);
        ~Zombie(void);
        void    announce(void) const;zz

    private:
        std::string _name;
};