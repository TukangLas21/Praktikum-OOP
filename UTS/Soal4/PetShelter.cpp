#include "PetShelter.hpp"

using namespace std;

template <typename T>
PetShelter<T>::PetShelter(string shelterName) {
    this->shelterName = shelterName;
    this->dogCapacity = 8; 
    this->catCapacity = 12; 
    this->petCount = 0;
    this->currentDogs = 0;
    this->currentCats = 0;
}

template <typename T>
PetShelter<T>::PetShelter(string shelterName, int dogCapacity, int catCapacity) {
    if (dogCapacity + catCapacity > MAX_SHELTER_CAPACITY) {
        std::cout << "The total capacity you construct is " << (dogCapacity + catCapacity) << ", meanwhile the shelter capacity is " << MAX_SHELTER_CAPACITY << std::endl;
    } else {
        this->shelterName = shelterName;
        this->dogCapacity = dogCapacity;
        this->catCapacity = catCapacity;
        this->petCount = 0;
        this->currentDogs = 0;
        this->currentCats = 0;
    }
}

template <typename T>
PetShelter<T>::~PetShelter() {
    for (int i = 0; i < petCount; ++i) {
        delete pets[i]; // Delete semua pet
    }
}

template <typename T>
std::string PetShelter<T>::getShelterName() const {
    return shelterName;
}

template <typename T>
void PetShelter<T>::addPet(const string &petName, int age, bool isDog, const string &extraInfo) {
    if (petCount >= dogCapacity + catCapacity) {
        cout << "Error: Shelter is at full capacity!" << endl;
        return;
    }
    if (isDog) {
        if (currentDogs >= dogCapacity) {
            cout << "Error: No space for more dogs!" << endl;
            return;
        }
        pets[petCount++] = new Dog(petName, age, extraInfo);
        pets[petCount - 1]->setId("D" + to_string(currentDogs + 1)); 
        currentDogs++;
        cout < "Success: " << petName << " has been added as a Dog! Pet ID: " << pets[petCount - 1]->getId() << endl;
    } else {
        if (currentCats >= catCapacity) {
            cout << "Error: No space for more cats!" << endl;
            return;
        }
        pets[petCount++] = new Cat(petName, age, extraInfo);
        pets[petCount - 1]->setId("C" + to_string(currentCats + 1));
        currentCats++;
        cout << "Success: " << petName << " has been added as a Cat! Pet ID: " << pets[petCount - 1]->getId() << endl;
    }
}

template <typename T>
T* PetShelter<T>::findPet(const string &petID) const {
    int id = -1;
    for (int i = 0; i < petCount; i++) {
        if (pets[i]->getId == petID) {
            id = i;
            break;
        }
    }
    if (id == -1) {
        cout << "Pet ID is invalid!" << endl;
        return nullptr;
    } else {
        Pet pet = dynamic_cast<T*>(pets[id]); 
        pet.displayInfo(); 
        return pet; // Return the found pet
    }
}

template <typename T>
void PetShelter<T>::listAllPets() const {
    if (petCount == 0) {
        cout << "No pets in the shelter." << endl;
        return;
    }
    for (int i = 0; i < petCount; ++i) {
        cout << i+1 << ". ";
        pets[i]->displayInfo();
    }
}

template <typename T>
int PetShelter<T>::calculateCost() const {
    int total = 0;
    for (int i = 0; i < petCount; i++) {
        if (dynamic_cast<Dog*>(pets[i])) {
            total += 75; 
        } else if (dynamic_cast<Cat*>(pets[i])) {
            total += 60; 
        }
    }
    return total;
}

template <typename T>
void PetShelter<T>::removePet(const string &petID) {
    int id = -1;
    for (int i = 0; i < petCount; i++) {
        if (pets[i]->getId() == petID) {
            id = i;
            break;
        }
    }
    if (id == -1) {
        cout << "Pet ID is invalid!" << endl;
        return;
    } else {
        if (dynamic_cast<Dog*>(pets[id])) {
            currentDogs--;
        } else if (dynamic_cast<Cat*>(pets[id])) {
            currentCats--;
        }
        delete pets[id]; // Hapus pet dari memori
        for (int j = id; j < petCount - 1; j++) {
            pets[j] = pets[j + 1]; // Geser pet ke kiri
        }
        petCount--;
    }
}