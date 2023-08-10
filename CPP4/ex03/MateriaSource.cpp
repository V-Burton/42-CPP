#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for(int i = 0; i < NB_SLOT; i++)
		this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &rhs){
	*this = rhs;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs){
	for(int i = 0; i < NB_SLOT; i++){
		if (this->_inventory[i])
			delete(this->_inventory[i]);
		this->_inventory[i] = rhs._inventory[i];
	}
	return (*this);
}

MateriaSource::~MateriaSource(){
	for(int i = 0; i < NB_SLOT; i++){
		if(this->_inventory[i])
			delete (this->_inventory[i]);
	}
}

void	MateriaSource::learnMateria(AMateria *src){
	int	idx = 0;
	while (idx < NB_SLOT && _inventory[idx] != NULL)
		idx++;
	if(idx != NB_SLOT)
		_inventory[idx] = src;
	else
		std::cout << "Can't learn more materia\n";
}

AMateria	*MateriaSource::createMateria(std::string const & type){
	for(int i = 0; i < NB_SLOT; i++){
		if (this->_inventory[i] && this->_inventory[i]->getType() == type)
			return (this->_inventory[i]->clone());
	}
	std::cout << "Unknown type\n";
	return (NULL);
}
