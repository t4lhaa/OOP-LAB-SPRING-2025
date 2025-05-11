#include <iostream>
#include <exception>
using namespace std;

class QueueOverflowException : public exception {};
class QueueUnderflowException : public exception {};

template<typename T>
class Queue {
private:
    int front, rear, size, capacity;
    T* data;

public:
    Queue(int cap) : front(0), rear(-1), size(0), capacity(cap) {
        data = new T[capacity];
    }

    ~Queue() {
        delete[] data;
    }

    void enqueue(const T& value) {
        if (size == capacity)
            throw QueueOverflowException();

        rear = (rear + 1) % capacity;
        data[rear] = value;
        size++;
    }

    T dequeue() {
        if (size == 0)
            throw QueueUnderflowException();

        T value = data[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }
};

int main() {
    Queue<int> q(3);

    
    try {
        cout << "Attempting to enqueue to a full queue..." << endl;
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);  
    }
    catch (const QueueOverflowException& e) {
        cout << "Caught QueueOverflowException" << endl;
        cout << "what(): " << e.what() << endl;
    }

   
    try {
        cout << "\nDequeuing all elements..." << endl;
        cout << q.dequeue() << endl;
        cout << q.dequeue() << endl;
        cout << q.dequeue() << endl;

        cout << "Attempting to dequeue from an empty queue..." << endl;
        cout << q.dequeue();  
    }
    catch (const QueueUnderflowException& e) {
        cout << "Caught QueueUnderflowException" << endl;
        cout << "what(): " << e.what() << endl;
    }

    return 0;
}
