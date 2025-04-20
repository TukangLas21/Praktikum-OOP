#include "Midfielder.hpp"
#include <iostream>

using namespace std;

// Default constructor
// set atribut Footballer dengan nilai default,
// set assist dan keyPasses ke 0, dan playPosition ke "midfielder"
// ...
Midfielder::Midfielder() : Footballer() {
    this->playPosition = "midfielder";
    this->assist = 0;
    this->keyPasses = 0;
}

// User-defined constructor
// parameter: string name, int birthYear, int assist, int keyPasses
// set atribut dengan nilai parameter, playPosition tetap "midfielder"
// nationality, height, dan weight gunakan nilai default superclass
// ...
Midfielder::Midfielder(string name, int birthYear, int assist, int keyPasses) : Footballer() {
    this->name = name;
    this->birthYear = birthYear;
    this->assist = assist;
    this->keyPasses = keyPasses;
    this->playPosition = "midfielder";
}

// Getter dan Setter untuk assist
void Midfielder::setAssist(int assists) {
    this->assist = assists;
}
int Midfielder::getAssist() const {
    return this->assist;
}


// Getter dan Setter untuk keyPasses
void Midfielder::setKeyPasses(int passes) {
    this->keyPasses = passes;
}
int Midfielder::getKeyPasses() const {
    return this->keyPasses;
}

// Method tambahan: menghitung playmakerRating
// rumus: (assist * 3) + keyPasses
// return dalam bentuk int
// ...
int Midfielder::playmakerRating() const {
    return (this->assist * 3) + this->keyPasses;
}

// Override transferRate:
// rumus: (800.000 * assist) + (30.000 * keyPasses)
// hasil berupa int
// ...
int Midfielder::transferRate() {
    return (800000 * this->assist) + (30000 * this->keyPasses);
}

// Override displayInfo():
// Cetak info Footballer + atribut tambahan midfielder (assist, keyPasses, playmakerRating)
// Format:
// Assists: <assist>
// Key Passes: <keyPasses>
// Playmaker Rating: <playmakerRating>
void Midfielder::displayInfo() {
    Footballer::displayInfo();
    cout << "Assists: " << this->assist << endl;
    cout << "Key Passes: " << this->keyPasses << endl;
    cout << "Playmaker Rating: " << this->playmakerRating() << endl;
}