#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 
#include <ranges> // Range Library

int main() {
    /* Mengurutkan angka-angka ganjil pada vector yang diakarkan */
    std::vector<int> vecLengkap = {10, 8, 27, 64, 89, 25, 73, 135, 182, 12, 83}; 

    auto vecBaru = vecLengkap 
        | std::views::filter([](int x) {
            return x % 2 != 0; 
        })
        | std::views::transform([](int x) { 
            return sqrt(x); 
        });

    std::vector<int> vecHasil(vecBaru.begin(), vecBaru.end());
    std::ranges::sort(vecHasil);

    for (int hasil : vecHasil) {
        std::cout << hasil << " ";
    }
    std::cout << std::endl;

    return 0;
}

