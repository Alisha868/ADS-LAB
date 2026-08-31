#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class CircularQueue {
private:
    Node *front, *rear;

public:
    CircularQueue() {
        front = rear = NULL;
    }

    // Enqueue Operation
    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (front == NULL) {
            front = rear = newNode;
            rear->next = front;
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }

        cout << value << " inserted successfully.\n";
    }

    // Dequeue Operation
    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow!\n";
            return;
        }

        if (front == rear) {
            cout << "Deleted Element: " << front->data << endl;
            delete front;
            front = rear = NULL;
        } else {
            Node* temp = front;
            cout << "Deleted Element: " << temp->data << endl;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }

    // Display Operation
    void display() {
        if (front == NULL) {
            cout << "Queue is Empty!\n";
            return;
        }

        Node* temp = front;
        cout << "Circular Queue: ";

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);

        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n--- Circular Queue using Linked List ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
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
                cout << "Program Ended.\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}