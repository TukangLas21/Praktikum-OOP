#include "Goalkeeper.hpp"
#include <iostream>

using namespace std;

// Default constructor
// set atribut Footballer dengan nilai default,
// set cleanSheets, saves, totalShotsOnGoal ke 0, playPosition ke "goalkeeper"
// ...
Goalkeeper::Goalkeeper() : Footballer() {
    this->playPosition = "goalkeeper";
    this->cleanSheets = 0;
    this->saves = 0;
    this->totalShotsOnGoal = 0;
}

// User-defined constructor
// parameter: string name, int birthYear, int cleanSheets, int saves, int totalShotsOnGoal
// set atribut dengan nilai parameter, playPosition tetap "goalkeeper"
// nationality, height, dan weight gunakan nilai default superclass
// ...
Goalkeeper::Goalkeeper(string name, int birthYear, int cleanSheets, int saves, int totalShotsOnGoal) : Footballer() {
    this->name = name;
    this->birthYear = birthYear;
    this->playPosition = "goalkeeper";
    this->cleanSheets = cleanSheets;
    this->saves = saves;
    this->totalShotsOnGoal = totalShotsOnGoal;
}

// Getter dan Setter untuk cleanSheets
// setCleanSheets(...)
// getCleanSheets()
void Goalkeeper::setCleanSheets(int cleanSheets) {
    this->cleanSheets = cleanSheets;
}
int Goalkeeper::getCleanSheets() const {
    return this->cleanSheets;
}
// Getter dan Setter untuk saves
// setSaves(...)
// getSaves()
void Goalkeeper::setSaves(int saves) {
    this->saves = saves;
}
int Goalkeeper::getSaves() const {
    return this->saves;
}

// Getter dan Setter untuk totalShotsOnGoal
void Goalkeeper::setTotalShotsOnGoal(int shots) {
    this->totalShotsOnGoal = shots;
}
int Goalkeeper::getTotalShotsOnGoal() const {
    return this->totalShotsOnGoal;
}

// Method tambahan: savePercentage
// rumus: (saves / totalShotsOnGoal) * 100
// return dalam bentuk float
// ...
float Goalkeeper::savePercentage() const {
    if (totalShotsOnGoal == 0) {
        return 0.0;
    }
    return (static_cast<float> (saves) / totalShotsOnGoal) * 100;
}

// Override transferRate:
// rumus: (700.000 * cleanSheets) + (50.000 * saves)
// hasil berupa int
// ...
int Goalkeeper::transferRate() {
    return (700000 * this->cleanSheets) + (50000 * this->saves);
}

// Override displayInfo():
// Cetak info Footballer + atribut tambahan goalkeeper (cleanSheets, saves, savePercentage)
// Format:
// Clean Sheets: <cleanSheets>
// Saves: <saves>
// Save Percentage: <savePercentage>%
void Goalkeeper::displayInfo() {
    Footballer::displayInfo();
    cout << "Clean Sheets: " << this->cleanSheets << endl;
    cout << "Saves: " << this->saves << endl;
    cout << "Save Percentage: " << fixed << setprecision(2) << this->savePercentage() << "%" << endl;
}

// Hint: Gunakan fixed dan setprecision(2) untuk menampilkan conversionRate
// Contoh: cout << fixed << setprecision(2) << conversionRate() << "%" << endl;
// ...