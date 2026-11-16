
#include <iostream>
using namespace std;

template <typename type>
class Tree {

    struct Node {
        type data;
        Node* left;
        Node* right;

        Node(type d) {
            data = d;
            left = right = nullptr;
        }
    };

public:
    Node* Root = nullptr;

    Tree() {
        Node* f = new Node('F');
        Node* b = new Node('B');
        Node* g = new Node('G');
        Node* a = new Node('A');
        Node* d = new Node('D');
        Node* i = new Node('I');
        Node* c = new Node('C');
        Node* e = new Node('E');
        Node* h = new Node('H');

        f->left = b;
        f->right = g;

        b->left = a;
        b->right = d;

        g->right = i;

        d->left = c;
        d->right = e;

        i->left = h;

        Root = f;
    }

    // Preorder: Root -> Left -> Right
    void preOrder(Node* ptr) {
        if (ptr != nullptr) {
            cout << " " << ptr->data;
            preOrder(ptr->left);
            preOrder(ptr->right);
        }
    }

    // Inorder: Left -> Root -> Right
    void inOrder(Node* ptr) {
        if (ptr != nullptr) {
            inOrder(ptr->left);
            cout << " " << ptr->data;
            inOrder(ptr->right);
        }
    }

    // Postorder: Left -> Right -> Root
    void postOrder(Node* ptr) {
        if (ptr != nullptr) {
            postOrder(ptr->left);
            postOrder(ptr->right);
            cout << " " << ptr->data;
        }
    }
};

int main() {
    Tree<char> obj;

    if (obj.Root == nullptr) {
        cout << "Tree is empty" << endl;
    }
    else {
        cout << "Preorder Traversal: ";
        obj.preOrder(obj.Root);
        cout << endl;

        cout << "Inorder Traversal: ";
        obj.inOrder(obj.Root);
        cout << endl;

        cout << "Postorder Traversal: ";
        obj.postOrder(obj.Root);
        cout << endl;
    }

    return 0;
}
