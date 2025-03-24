#include <iostream>

using namespace std;

template<typename T>
T MinArray(T arr[], int N) {
    T min = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

class Jam {
private:
    int j;
    int m;
    int d;
public:
    Jam(); // default constructor
    Jam(int j, int m, int d); // ctor dengan parameter
    bool operator<(const Jam& other) const; // Overload operator < untuk memudahkan perbandingan Jam
    void print(); // print dalam HH:MM:SS
};