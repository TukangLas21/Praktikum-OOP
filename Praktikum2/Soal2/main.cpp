#include "Creature.hpp"
#include "Dragon.hpp"

int main() {
    // Lengkapi disini

    Dragon Draco("Draco");
    Creature& temp1 = Draco;
    Draco.speak();
    Draco.wound();
    Draco.wound();
    Draco.print();
    Draco.speak();
    temp1.wound();
    temp1.print();
    Draco.print();
    Creature temp = temp1;
    temp.speak();
    temp.wound();
    temp.print();
    Draco.print();

    return 0;
}

// A creature has been born!
// A dragon has been born!
// I am the mighty dragon Draco! Beware of my flames!
// Base Health: 100; Additional Health: 80
// I am the mighty dragon Draco! Beware of my flames!
// Base Health: 90
// Base Health: 90; Additional Health: 80
// I am a mystical creature named Draco!
// Base Health: 80
// Base Health: 90; Additional Health: 80