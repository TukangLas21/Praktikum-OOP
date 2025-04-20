#include "Footballer.hpp"
#include <iostream>

using namespace std;

// Default cosntructor set nilai attribut sebagai berikut:
// name = "noname"; birthYear = 2000; playPosition = "none";
// nationality = "Indonesia"; height = 180, weight = 70
// ...
Footballer::Footballer() {
    name = "noname";
    birthYear = 2000;
    playPosition = "none";
    nationality = "Indonesia";
    height = 180;
    weight = 70;
}

// User-defined constructor:
// set nilai atribut berdasarkan nilai parameter masukan
// dengan urutan: name, birthYear, playPosition, nationality, height, weight
// ...
Footballer::Footballer(string name, int birthYear, string playPosition, string nationality, int height, int weight) {
    this->name = name;
    this->birthYear = birthYear;
    this->playPosition = playPosition;
    this->nationality = nationality;
    this->height = height;
    this->weight = weight;
}

// Copy constructor
// ...
Footballer::Footballer(const Footballer& other) {
    this->name = other.name;
    this->birthYear = other.birthYear;
    this->playPosition = other.playPosition;
    this->nationality = other.nationality;
    this->height = other.height;
    this->weight = other.weight;
}

// Destructor
// ...
Footballer::~Footballer() {}

// Operator assignment
// ...
Footballer& Footballer::operator=(const Footballer& other) {
    if (this == &other) {
        return *this;
    }
    this->name = other.name;
    this->birthYear = other.birthYear;
    this->playPosition = other.playPosition;
    this->nationality = other.nationality;
    this->height = other.height;
    this->weight = other.weight;
    return *this;
}

// Getter dan setter name
// setName(...)
// getName()
void Footballer::setName(string name) {
    this->name = name;
}
string Footballer::getName() const {
    return this->name;
}

// Getter dan setter playPosition
// setPlayPosition(...)
// getPlayPosition()
void Footballer::setPlayPosition(string pos) {
    this->playPosition = pos;
}
string Footballer::getPlayPosition() const {
    return this->playPosition;
}

// Getter dan setter nationality
// setNationality(...)
// getNationality()
void Footballer::setNationality(string nation) {
    this->nationality = nation;
}
string Footballer::getNationality() const {
    return this->nationality;
}

// Getter dan setter height and weight
// setHeight(...)
// getHeight()
// setWeight(...)
// getWeight()
void Footballer::setHeight(int height) {
    this->height = height;
}
int Footballer::getHeight() const {
    return this->height;
}
void Footballer::setWeight(int weight) {
    this->weight = weight;
}
int Footballer::getWeight() const {
    return this->weight;
}

// gunakan CURRENT_YEAR untuk menghitung umur
// getAge()
int Footballer::getAge() const {
    return (CURRENT_YEAR - this->birthYear);
}

// gunakan height and weight untuk menghitung BMI
// BMI = weight(kg) / (height(m))²
// getBMI()
double Footballer::getBMI() const {
    double heightInMeters = this->height / 100.0; 
    return (this->weight / (heightInMeters * heightInMeters));
}

// gunakan BMI untuk mendapat category
// BMI < 18.5         -> Underweight
// 18.5 ≤ BMI < 25.0  -> Normal
// 25.0 ≤ BMI < 30.0  -> Overweight
// BMI ≥ 30.0         -> Obese
// getCategory() -> string
string Footballer::getCategory() const {
    double BMI = this->getBMI();
    if (BMI < 18.5) return "Underweight";
    if (18.5 <= BMI && BMI < 25.0) return "Normal";
    if (25.0 <= BMI && BMI < 30.0) return "Overweight";
    if ( BMI >= 30.0) return "Obese";
    return "Unknown";
}

// Mencetak informasi footballer dengan format sebagai berikut:
// Name: {name}
// Age: {hasil pemanggilan getAge()}
// Position: {playPosition}
// Nationality: {nationality}
// BMI: {<BMI> (<getCategory()>)}, BMI 2 angka di belakang koma, HINT: "cout << fixed << setprecision(2);"
// Transfer Rate: {hasil pemanggilan transferRate()}
// displayInfo()
void Footballer::displayInfo() {
    cout << "Name: " << this->name << endl;
    cout << "Age: " << this->getAge() << endl;
    cout << "Position: " << this->playPosition << endl;
    cout << "Nationality: " << this->nationality << endl;
    cout << fixed << setprecision(2);
    cout << "BMI: " << this->getBMI() << " (" << this->getCategory() << ")" << endl;
    cout << "Transfer Rate: " << this->transferRate() << endl;
}