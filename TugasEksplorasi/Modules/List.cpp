export module ListStatik;

export struct ListStatik {
    int *data; 
    int N; // Ukuran efektif list
    int capacity; // Ukuran maksimal list

    // Constructor
    ListStatik(int capacity) : N(0), capacity(capacity) {
        data = new int[capacity];
    }
};

bool isFull(const ListStatik &list) {
    return list.N == list.capacity;
}
bool isEmpty(const ListStatik &list) {
    return list.N == 0;
}

export void insertAt(ListStatik &list, int value, int index) {
    if (!isFull(list) && index >= 0 && index <= list.N) {
        for (int i = list.N; i > index; i--) {
            list.data[i] = list.data[i - 1];
        }
        list.data[index] = value;
        list.N++;
    }
}

export void removeAt(ListStatik &list, int index) {
    if (!isEmpty(list) && index >= 0 && index < list.N) {
        for (int i = index; i < list.N - 1; i++) {
            list.data[i] = list.data[i + 1];
        }
        list.N--;
    }
}

export ListStatik addTwoLists(const ListStatik &list1, const ListStatik &list2) {
    if (list1.N == list2.N) {
        ListStatik result(list1.N);
        for (int i = 0; i < list1.N; i++) {
            result.data[i] = list1.data[i] + list2.data[i];
        }
        result.N = list1.N;
        return result;
    }
}