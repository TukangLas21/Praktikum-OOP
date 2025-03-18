#include "Pokemon.hpp"
#include "FirePokemon.hpp"
#include "WaterPokemon.hpp"
#include "GrassPokemon.hpp"

#include <iostream>

using namespace std;

int main() {
    FirePokemon charmander("Charmander", 100, 20);

    WaterPokemon squirtle("Squirtle", 100, 20, 10);

    squirtle.heal(10);

    squirtle.attack(charmander);

    charmander.attack(squirtle);

    squirtle.attack(charmander);

    GrassPokemon bulbasaur("Bulbasaur", 100, 50, 20);

    squirtle.attack(bulbasaur);

    bulbasaur.attack(squirtle);
    
    
    return 0;
}