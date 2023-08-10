#include "Character.hpp"

Character::Character(){
	this->_name = "Default Character";
	for(int i = 0; i < NB_SLOT; i++){
		this->_inventory[i] = NULL;
	}
}

Character::Character(std::string name){
	this->_name = name;
	for(int i = 0; i < NB_SLOT; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character &rhs){
	*this = rhs;
}

Character &Character::operator=(const Character &rhs){
	this->_name = rhs._name;
	for(int i = 0; i < NB_SLOT; i++){
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = rhs._inventory[i];
	}
	return (*this);
}

Character::~Character(){
	for(int i = 0; i < NB_SLOT; i++){
		if(this->_inventory[i])
			delete (this->_inventory[i]);
	}
}

const std::string &Character::getName() const{
	return (this->_name);
}

void	Character::equip(AMateria *m){
	int	i = 0;

	while (i < NB_SLOT){
		if (this->_inventory[i] == NULL)
			break;
		i++;
	}
	if (i == NB_SLOT){
		std::cout << "Can't store more materia.\n";
		delete m;
		return ;
	}
	this->_inventory[i] = m;
}

void	Character::unequip(int idx){
	if (this->_inventory[idx] == NULL)
		return;
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target){
	if	(this->_inventory[idx] == NULL)
		return ;
	this->_inventory[idx]->use(target);
	delete this->_inventory[idx];
	this->_inventory[idx] = NULL;
}
