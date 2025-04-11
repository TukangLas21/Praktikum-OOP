module Hello;

#include <iostream>;
using namespace std;

export void sayHello() {
    sayHi();
    cout << "Hello, ITB!" << endl;
} 

void sayHi() {
    cout << "Hi, ITB!" << endl;
}