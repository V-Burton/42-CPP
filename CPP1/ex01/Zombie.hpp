/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:19:39 by vburton           #+#    #+#             */
/*   Updated: 2023/07/19 14:17:34 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Zombie{
    public:
        Zombie(void);
        Zombie(const std::string &name);
        ~Zombie(void);
        void    announce(void);
        void    setName(const std::string &name);

    private:
       std::string _name;
};
