#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue {
private:
    int queue[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Enqueue Operation
    void enqueue(int value) {
        if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
            cout << "Queue Overflow!" << endl;
            return;
        }

        if (front == -1) {
            front = rear = 0;
        }
        else if (rear == MAX - 1) {
            rear = 0;
        }
        else {
            rear++;
        }

        queue[rear] = value;
        cout << value << " inserted successfully." << endl;
    }

    // Dequeue Operation
    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow!" << endl;
            return;
        }

        cout << "Deleted Element: " << queue[front] << endl;

        if (front == rear) {
            front = rear = -1;
        }
        else if (front == MAX - 1) {
            front = 0;
        }
        else {
            front++;
        }
    }

    // Display Operation
    void display() {
        if (front == -1) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Circular Queue: ";

        int i = front;
        while (true) {
            cout << queue[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }

        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n--- Circular Queue Menu ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Program Ended." << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}