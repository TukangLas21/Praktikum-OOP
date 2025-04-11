#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 

int main() {
    /* Mengurutkan angka-angka ganjil pada vector yang diakarkan */
    std::vector<int> vecLengkap = {10, 8, 27, 64, 89, 25, 73, 135, 182, 12, 83}; 
    std::vector<int> vecBaru;

    std::copy_if(vecLengkap.begin(), vecLengkap.end(), std::back_inserter(vecBaru), [](int x) {
        return x % 2 != 0; 
    });

    std::transform(vecBaru.begin(), vecBaru.end(), vecBaru.begin(), [](int x) { 
        return sqrt(x); 
    });

    std::sort(vecBaru.begin(), vecBaru.end());

    for (int hasil : vecBaru) {
        std::cout << hasil << " ";
    }
    std::cout << std::endl;

    return 0;
}

