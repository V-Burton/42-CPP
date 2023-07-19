/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:49:18 by vburton           #+#    #+#             */
/*   Updated: 2023/07/19 18:19:31 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB{
	public:
		HumanB(const std::string &name);
		~HumanB();
		void	attack(void);
		void	setWeapon(Weapon &newWeapon);

	private:
		std::string	_name;
		Weapon 		*_weapon;
};
