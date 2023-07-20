/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:38:35 by vburton           #+#    #+#             */
/*   Updated: 2023/07/20 13:20:21 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA{
	public:
		HumanA(const std::string &name, Weapon &weapon);
		~HumanA();
		void	attack();

	private:
		std::string _name;
		Weapon &_weapon;
};
