#include <iostream>
#include <string>

void attack() {
    std::cout << "Basic attack" << std::endl;
}

void attack(int power) {
    std::cout << "Attack with power: " << power << std::endl;
}

void attack(const std::string& spell) {
    std::cout << "Attack with spell: " << spell << std::endl;
}

int main() {
    attack();
    attack(5);
    attack("Plasma Beam", 50); 

    return 0;
}
