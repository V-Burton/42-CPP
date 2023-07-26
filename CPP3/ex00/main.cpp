#include "ClapTrap.hpp"

int main(){
    std::string nameA = "Clap";
    std::string nameB = "Trap";
    ClapTrap a = ClapTrap(nameA);
    ClapTrap b = ClapTrap(nameB);
    ClapTrap c = a;
    std::cout << "CaptTrap a name is : " << a.getName() << std::endl;
    std::cout << "CaptTrap b name is : " << b.getName() << std::endl;
    std::cout << "CaptTrap c name is : " << c.getName() << std::endl;

    a.setDamage(2);
    b.setDamage(1);
    for (int i = 0; i < 2; i++){
        a.attack(nameB);
        b.takeDamage(a.getDamage());
        b.attack(nameA);
        a.takeDamage(b.getDamage());
    }
    std::cout << "Hit Point ClapTrap " << a.getName() << " are : " << a.getHealth() << " and energie points are : " << a.getEnergie() << std::endl;
    std::cout << "Hit Point ClapTrap " << b.getName() << " are : " << b.getHealth() << " and energie points are : " << b.getEnergie() << std::endl;
    b.beRepaired(10);
    std::cout << "Hit Point ClapTrap " << a.getName() << " are : " << a.getHealth() << " and energie points are : " << a.getEnergie() << std::endl;
    std::cout << "Hit Point ClapTrap " << b.getName() << " are : " << b.getHealth() << " and energie points are : " << b.getEnergie() << std::endl;
    std::cout << "Hit Point ClapTrap " << c.getName() << " are : " << c.getHealth() << " and aDamage is : " << c.getDamage() << std::endl;
    std::cout << "Simulation ended !" << std::endl;
}