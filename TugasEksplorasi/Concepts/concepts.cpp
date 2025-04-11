#include <iostream>
#include <concepts>
#include <type_traits>

using namespace std;

/* Basic Syntax */
template<typename T> 
concept AngkaGanjil = requires(T x) {
    {x % 2 == 1} -> same_as<bool>;
};

template<AngkaGanjil T>
void print(T x) {
    cout << x << " adalah angka ganjil." << endl;
}


/* Contoh Program */
/* Concept Numerik memastikan tipe data bersifat numerik */
template<typename T>
concept Numerik = (integral<T> || floating_point<T>) && !is_same_v<T, char>;

template<Numerik T>
T operasiAritmatika(T a, T b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            cerr << "Operator tidak valid." << endl;
            return 0; // Bisa juga throw exception
    }
}

template<typename T>
concept NumerikPositif = Numerik<T> && requires(T x) {
    {x > 0} -> same_as<bool>;
};


int main() {
    int a = 13, b = 5;
    int c = operasiAritmatika(a, b, '+'); 
    int d = operasiAritmatika(a, b, '*');
    cout << c << endl;
    cout << d << endl;

    double x = 3.5;
    double y = 2.0;
    double z = operasiAritmatika(x, y, '/'); 
    cout << z << endl;

    /* Menimbulkan error karena beda tipe
        double m = 1.8    
        int n = 2;
        double mn = operasiAritmatika(m, n, '+');
    */

    /* Menimbulkan error karena bukan numerik
        char c1 = 'I';
        char c2 = 'F';
        char c3 = operasiAritmatika(c1, c2, '+'); 
        cout << c3 << endl;
    */

    return 0;
}
