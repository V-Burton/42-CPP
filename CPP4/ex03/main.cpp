#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	Character *me = new Character("me");
	std::cout << GREEN << "My player name is : " << me->getName() << "\n" << END;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << GREEN << "I have creat two materia that I have equip in slot 0 and 1 the use them \n" << END;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << GREEN << "A second call to them do nothing\n" << END;

	for (int i = 0; i < NB_SLOT; i++){
		tmp = src->createMateria("ice");
		me->equip(tmp);
	}
	std::cout << GREEN << "I created and equip my player with 'ice' materia on all his slot\n" << END;
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << GREEN << "I used slot 0 and 1\n" << END;
	std::cout << GREEN << "I haven't call the materia store in slot 3 of my inventory but let's try to unequip it and then call it.\n" << END;
	me->unequip(3);
	me->unequip(3);
	me->unequip(5);
	me->use(3, *bob);
	std::cout << GREEN << "Nothing has display since the slot 3 has been unequip. Plus try to unequip a materia at a slot that doesn't exits doesn't do anything aswell.\n" << END;
	delete tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << GREEN << "I created a new materia 'cure' and immedialtely equip it. Sould be on slot 0 so let's call it:\n" << END;
	me->use(0, *bob);
	me->use(0, *bob);
	std::cout << GREEN << "We called it twice and it display only one message wich is normal since a materia should delete itself after use.\n" << END;
	me->use(2, *bob);
	std::cout << GREEN << "The slot 2 was still equip so I called it and it displayed his message.\n" << END;

	for (int i = 0; i < NB_SLOT; i++){
		tmp = src->createMateria("cure");
		me->equip(tmp);
	}
	me->use(3, *bob);
	for (int i = 0; i < NB_SLOT; i++){
		tmp = src->createMateria("ice");
		me->equip(tmp);
	}
	for (int i = 0; i < NB_SLOT; i++)
		me->use(i, *bob);
	std::cout << GREEN << "I creat a new materia ice then done a loop on my player to equip every of his empty slot with it's new materia. I previously only use the materia store in slot three, so a call to every materia of it's inventory called three 'cure' and one 'ice'.\n" << END;
	std::cout << GREEN << "Let's now check that unequip a materia doesn't delete it.\n" << END;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->unequip(0);
	me->use(0, *bob);
	std::cout << GREEN << "I creat the new materia 'ice' store in the varaible 'tmp' then equip it in slot 0 of my inventory since i previously use all of my materia. Then I unequip my slot 0. Nothing happend. Let's now equip again the tmp materia.\n" << END;
	me->equip(tmp);
	me->use(0, *bob);
	std::cout << GREEN << "Has we can see, the materia hasn't been deleted and equip it has allow me to call it.\n" << END;

	delete bob;
	delete me;
	delete src;
	return 0;
}
