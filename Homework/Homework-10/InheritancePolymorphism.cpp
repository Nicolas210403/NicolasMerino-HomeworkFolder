#include <iostream>
#include <string>
// NOTE: When testing final changes to my main function my exe file was deleted and I could not run the code.
class Pokemon {
protected:
    std::string name;
    int health;
    int level;

public:
    Pokemon(std::string n, int h, int l) : name(n), health(h), level(l) {}
    virtual ~Pokemon() = default;

    virtual void attack() const = 0;
    virtual void defend() const = 0;
    virtual void evolve() = 0;
    virtual void useSpecialAbility() = 0;
    virtual void makeSound() const = 0;
};

class ElectricPokemon : public Pokemon {
protected:
    int voltageCapacity;

public:
    ElectricPokemon(std::string n, int h, int l, int volt) 
        : Pokemon(n, h, l), voltageCapacity(volt) {}

    void defend() const override {
        std::cout << name << " surrounds itself with an electric barrier!\n";
    }

    virtual void recharge() {
        voltageCapacity += 20;
        std::cout << name << " absorbed static energy. Voltage is now " << voltageCapacity << "V.\n";
    }
};


class Pikachu : public ElectricPokemon {
public:
    Pikachu(int lvl) : ElectricPokemon("Pikachu", 35, lvl, 100) {}

    void attack() const override {
        std::cout << name << " uses Spark!\n";
    }

    void evolve() override {
        std::cout << name << " evolved into Raichu!\n";
    }

    void useSpecialAbility() override {
        std::cout << name << " discharges " << voltageCapacity << "V in a Discharge attack!\n";
    }

    void makeSound() const override {
        std::cout << "Pika-Pika!\n";
    }
};

int main() {

    Pokemon* myPokemon = new Pikachu(15);

    myPokemon->makeSound();
    myPokemon->attack();
    myPokemon->defend();
    myPokemon->useSpecialAbility();
    myPokemon->evolve();

    Pikachu pika(25);
    
    pika.recharge();
    pika.useSpecialAbility();

    delete myPokemon;

    return 0;
}