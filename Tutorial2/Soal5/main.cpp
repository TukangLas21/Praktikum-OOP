#include "Pokemon.hpp"
#include "FirePokemon.hpp"
#include "WaterPokemon.hpp"
#include "GrassPokemon.hpp"

#include <iostream>

using namespace std;

int main() {
    FirePokemon* charmander = new FirePokemon("Charmander", 100, 20);
    Pokemon* f1 = new FirePokemon(*charmander);

    WaterPokemon* squirtle = new WaterPokemon("Squirtle", 100, 20, 10);
    squirtle->heal(10);
    Pokemon* w3(squirtle);

    WaterPokemon* magikarp = new WaterPokemon("Magikarp", 100, 20, 0);
    
    *squirtle = *squirtle;

    squirtle->attack(*charmander);
    squirtle->attack(*charmander);

    f1->~Pokemon();
    w3->~Pokemon();

    return 0;
}

// Charmander is born
// Charmander is born with type: fire | HP: 100 | ATT: 20 | attack count: 0
// Charmander is copied
// Charmander (copy) is born with type: fire | HP: 100 | ATT: 20 | attack count: 0
// Squirtle is born
// Squirtle is born with type: water | HP: 100 | ATT: 20 | attack boost: 10
// Squirtle heals 10 points | HP: 110
// Magikarp is born
// Magikarp is born with type: water | HP: 100 | ATT: 20 | attack boost: 0
// Squirtle is assigned with type: water | HP: 110 | ATT: 20 | attack boost: 10
// Squirtle used Water Gun on Charmander for 40 damage and it's super effective!
// Charmander took 40 damage and now has 60 HP
// Squirtle's Flow State increases! Current damage: 30
// Squirtle used Water Gun on Charmander for 60 damage and it's super effective!
// Charmander took 60 damage and now has 0 HP
// Charmander has fainted
// Squirtle's Flow State increases! Current damage: 40
// Charmander has run away
// Squirtle has run away