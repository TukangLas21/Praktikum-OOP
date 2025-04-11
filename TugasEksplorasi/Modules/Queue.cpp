export module Queue;

export struct Queue {
    int *data;
    int front, back; // Index head dan tail
    int N;
    int capacity; 

    Queue(int capacity) : front(0), back(0), N(0), capacity(capacity) {
        data = new int[capacity];
    }
};

bool isFull(const Queue &queue) {
    return queue.N == queue.capacity;
}
bool isEmpty(const Queue &queue) {
    return queue.N == 0;
}

export int getFront(const Queue &queue) {
    if (!isEmpty(queue)) {
        return queue.data[queue.front];
    }
    return -1; // Return -1 if the queue is empty
}

export int getBack(const Queue &queue) {
    if (!isEmpty(queue)) {
        return queue.data[(queue.back - 1 + queue.capacity) % queue.capacity];
    }
    return -1; // Return -1 if the queue is empty
}

export void enqueue(Queue &q, int val) {
    if (!isFull(q)) {
        q.data[q.back] = val;
        q.back = (q.back + 1) % q.capacity;
        q.N++;
    }
}

export void dequeue(Queue &q, int &val) {
    if (!isEmpty(q)) {
        val = q.data[q.front];
        q.front = (q.front + 1) % q.capacity;
        q.N--;
    }
}