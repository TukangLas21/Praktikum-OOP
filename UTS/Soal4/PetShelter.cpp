#include "PetShelter.hpp"

using namespace std;

int idDog = 1;
int idCat = 1;

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
    this->shelterName = shelterName;
    this->dogCapacity = dogCapacity;
    this->catCapacity = catCapacity;
    this->petCount = 0;
    this->currentDogs = 0;
    this->currentCats = 0;
    if (dogCapacity + catCapacity > MAX_SHELTER_CAPACITY) {
        std::cout << "The total capacity you construct is " << (dogCapacity + catCapacity) << ", meanwhile the shelter capacity is " << MAX_SHELTER_CAPACITY << endl;
    }
}

template <typename T>
PetShelter<T>::~PetShelter() {
    for (int i = 0; i < petCount; ++i) {
        delete pets[i]; 
        pets[i] = nullptr; 
    }
}

template <typename T>
std::string PetShelter<T>::getShelterName() const {
    return shelterName;
}

template <typename T>
void PetShelter<T>::addPet(const string &petName, int age, bool isDog, const string &extraInfo) {
    if (petCount >= MAX_SHELTER_CAPACITY) {
        cout << "Error: Shelter is at full capacity!" << endl;
        return;
    }
    if (isDog) {
        if (currentDogs >= dogCapacity) {
            cout << "Error: No space for more dogs!" << endl;
            return;
        }
        Dog* dog = new Dog(petName, age, extraInfo);
        string id = "D" + to_string(idDog++); 
        dog->setId(id);
        pets[petCount++] = dog;
        currentDogs++;
        cout << "Success: " << petName << " has been added as a Dog! Pet ID: " << id << endl;
    } else {
        if (currentCats >= catCapacity) {
            cout << "Error: No space for more cats!" << endl;
            return;
        }
        Cat* cat = new Cat(petName, age, extraInfo);
        string id = "C" + to_string(idCat++);
        cat->setId(id);
        pets[petCount++] = cat;
        currentCats++;
        cout << "Success: " << petName << " has been added as a Cat! Pet ID: " << id << endl;
    }
}

template <typename T>
T* PetShelter<T>::findPet(const string &petID) const {
    for (int i = 0; i < petCount; ++i) {
        if (pets[i]->getId() == petID) {
            T* pet = dynamic_cast<T*>(pets[i]);
            if (pet) {
                pet->displayInfo();
                return pet;
            }
        }
    }
    cout << "Pet ID is invalid!" << endl;
    return nullptr;
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
    for (int i = 0; i < petCount; i++) {
        if (pets[i]->getId() == petID) {
            cout << pets[i]->getName() << " has been removed from the shelter." << endl;
            if (dynamic_cast<Dog*>(pets[i])) {
                currentDogs--;
            } else if (dynamic_cast<Cat*>(pets[i])) {
                currentCats--;
            }
            delete pets[i]; 
            for (int j = i; j < petCount - 1; j++) {
                pets[j] = pets[j + 1]; 
            }
            pets[petCount - 1] = nullptr; 
            petCount--;
            return;
        }
    }
    cout << "Pet ID is invalid!" << endl;
}

template class PetShelter<Pet>;
template class PetShelter<Dog>;
template class PetShelter<Cat>;