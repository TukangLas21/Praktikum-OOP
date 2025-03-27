#include <iostream>

using namespace std;

#define MAX_CAP 10

template<class Key, class Val>
class KeyValue {
private:
    Key *keys;
    Val *values;
    int numOfPairs;
public:
    KeyValue() {
        this->keys = new Key[10];
        this->values = new Val[10];
        this->numOfPairs = 0;
    }

    KeyValue(const KeyValue<Key, Val>& kv) {
        this->keys = kv.keys;
        this->values = kv.values;
        this->numOfPairs = kv.numOfPairs;
    } 

    KeyValue<Key, Val> operator=(const KeyValue<Key, Val>& kv) {
        this->keys = kv.keys;
        this->values = kv.values;
        this->numOfPairs = kv.numOfPairs;
        return this;
    }

    ~KeyValue() {
        delete[] this->keys;
        delete[] this->values;
    }

    void set(Key k, Val v) {
        if (this->numOfPairs == MAX_CAP) {
            cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << endl;
            return;
        } 

        bool found = false;
        for (int i = 0; i < numOfPairs; i++) {
            if (k == this->keys[i]) {
                this->values[i] = v;
                found = true;
                break;
            }
        }
        if (!found) {
            this->keys[this->numOfPairs] = k;
            this->values[this->numOfPairs] = v;
            this->numOfPairs++;
        }
    }

    void display(Key k) {
        int idx = 0;
        bool found = false;
        for (int i = 0; i < numOfPairs; i++) {
            if (k == this->keys[i]) {
                idx = i;
                found = true;
                break;
            }
        }
        if (found) {
            cout << this->values[idx] << endl;
        } else {
            cout << "Key tidak ditemukan!" << endl;
        }
    }
};

template<class Val>
class KeyValue <double, Val>{
private:
    double *keys;
    Val *values;
    int numOfPairs;
public:
    KeyValue() {
        this->keys = new double[10];
        this->values = new Val[10];
        this->numOfPairs = 0;
    }

    KeyValue(const KeyValue<double, Val>& kv) {
        this->keys = kv.keys;
        this->values = kv.values;
        this->numOfPairs = kv.numOfPairs;
    } 

    KeyValue<double, Val> operator=(const KeyValue<double, Val>& kv) {
        this->keys = kv.keys;
        this->values = kv.values;
        this->numOfPairs = kv.numOfPairs;
        return this;
    }

    ~KeyValue() {
        delete[] this->keys;
        delete[] this->values;
    }

    void set(double k, Val v) {
        if (this->numOfPairs == MAX_CAP) {
            cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << endl;
            return;
        } 

        bool found = false;
        for (int i = 0; i < numOfPairs; i++) {
            if (k == this->keys[i]) {
                this->values[i] = v;
                found = true;
                break;
            } else if (k - keys[i] < 0.01 || keys[i] - k > 0.01) {
                this->values[i] = v;
                found = true;
                break;
            }
        }
        if (!found) {
            this->keys[this->numOfPairs] = k;
            this->values[this->numOfPairs] = v;
            this->numOfPairs++;
        }
    }

    void display(double k) {
        int idx = 0;
        bool found = false;
        for (int i = 0; i < numOfPairs; i++) {
            if (k == this->keys[i]) {
                idx = i;
                found = true;
                break;
            } else if (k - keys[i] < 0.01 || keys[i] - k > 0.01) {
                idx = i;
                found = true;
                break;
            }
        }
        if (found) {
            cout << this->values[idx] << endl;
        } else {
            cout << "Key tidak ditemukan!" << endl;
        }
    }
};