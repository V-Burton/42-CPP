#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(){
    std::string nameA = "Clap";
    std::string nameB = "Trap";
    ClapTrap a = ClapTrap(nameA);
    ClapTrap b = ClapTrap(nameB);
    ClapTrap c = a;
    std::cout << "ClaptTrap a name is : " << a.getName() << std::endl;
    std::cout << "ClaptTrap b name is : " << b.getName() << std::endl;
    std::cout << "ClaptTrap c name is : " << c.getName() << std::endl;

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
    
    std::cout <<"\n----------------------------------------------------\n" << std::endl;

    std::string nameC = "Scav";
    ScavTrap d = ScavTrap(nameC);
    ScavTrap e = d;
    std::cout << "ScavTrap e name is : " << e.getName() << std::endl;
    std::cout << "Hit Point ScavTrap " << e.getName() << " are : " << e.getHealth() << " and energie points are : " << e.getEnergie() << std::endl;
    std::cout << "ScavTrap d name is : " << d.getName() << std::endl;
    d.guardGate();
    d.attack(a.getName());
    a.takeDamage(d.getDamage());
    a.attack(d.getName());
    std::cout << "Hit Point ClapTrap " << d.getName() << " are : " << d.getHealth() << " and energie points are : " << d.getEnergie() << std::endl;
    std::cout << "Hit Point ClapTrap " << a.getName() << " are : " << a.getHealth() << " and energie points are : " << a.getEnergie() << std::endl;
    a.beRepaired(10);
    std::cout << "Hit Point ScapTrap " << d.getName() << " are : " << d.getHealth() << " and energie points are : " << d.getEnergie() << std::endl;
    std::cout << "Hit Point ClapTrap " << a.getName() << " are : " << a.getHealth() << " and energie points are : " << a.getEnergie() << std::endl;
    
    std::cout <<"\n----------------------------------------------------\n" << std::endl;
    
    std::string nameF = "Frag";
    FragTrap f = FragTrap(nameF);
    FragTrap g(f);
    FragTrap h;
    h = f;
    std::cout << "FragTrap f name is : " << f.getName() << std::endl;
    std::cout << "FragTrap g name is : " << g.getName() << std::endl;
    std::cout << "FragTrap h name is : " << h.getName() << std::endl;
    g.highFivesGuys();

    std::cout << "Simulation ended !" << std::endl;
}