#include <iostream>

using namespace std;

template<typename T>
void PrintArray(T arr[], int N) {
    if (N == 0) {
        cout << "Array kosong" << endl;
        return;
    }
    cout << "Berikut isi dari array: " << endl;
    cout << "[";
    for (int i = 0; i < N; i++) {
        cout << arr[i];
        if (i != N - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

class Point {
private:
    int x;
    int y;
public:
    Point();
    Point(int x, int y);
    friend ostream& operator<<(ostream& os, const Point& p);
    void print();
};