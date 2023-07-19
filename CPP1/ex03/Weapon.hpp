/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:51:49 by vburton           #+#    #+#             */
/*   Updated: 2023/07/19 18:32:30 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Weapon
{
	public:
		Weapon(const std::string &weapon);
		~Weapon();
		std::string getType(void);
		void	setType(const std::string &newWeapon);

	private:
		std::string _type;
};
