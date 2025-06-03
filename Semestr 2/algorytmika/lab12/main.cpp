#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent;
};

Node* createNode(int key, Node* parent) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->left = newNode->right = nullptr;
    newNode->parent = parent;
    return newNode;
}

bool isEmpty(Node* root) {
    return root == nullptr;
}

void inorder(Node* node) {
    if (node) {
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }
}

void preorder(Node* node) {
    if (node) {
        cout << node->key << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(Node* node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        cout << node->key << " ";
    }
}

Node* search(Node* node, int key) {
    if (!node || node->key == key)
        return node;
    if (key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

Node* insert(Node* root, int key) {
    Node* parent = nullptr;
    Node* current = root;

    while (current) {
        parent = current;
        if (key == current->key) {
            cout << "Węzeł o kluczu " << key << " już istnieje.\n";
            return root;
        }
        current = (key < current->key) ? current->left : current->right;
    }

    Node* newNode = createNode(key, parent);
    if (!parent)
        return newNode;
    else if (key < parent->key)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

Node* minNode(Node* node) {
    while (node->left)
        node = node->left;
    return node;
}

Node* deleteNode(Node* root, int key) {
    if (!root)
        return nullptr;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

void deleteTree(Node*& node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
        node = nullptr;
    }
}

int main() {
    Node* root = nullptr;
    int choice, key;

    do {
        cout << "\nMenu:\n";
        cout << "1) Sprawdzenie czy drzewo jest puste\n";
        cout << "2) Dodanie nowego węzła\n";
        cout << "3) Sprawdzenie czy klucz istnieje\n";
        cout << "4) Wyświetlenie drzewa (preorder)\n";
        cout << "5) Wyświetlenie drzewa (inorder)\n";
        cout << "6) Wyświetlenie drzewa (postorder)\n";
        cout << "7) Usunięcie węzła\n";
        cout << "8) Usunięcie całego drzewa\n";
        cout << "9) Wyjście\n";
        cout << "Wybór: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << (isEmpty(root) ? "Drzewo jest puste.\n" : "Drzewo NIE jest puste.\n");
            break;

        case 2:
            cout << "Inorder przed dodaniem: ";
            inorder(root);
            cout << "\nPodaj klucz do dodania: ";
            cin >> key;
            root = insert(root, key);
            cout << "Inorder po dodaniu: ";
            inorder(root);
            cout << endl;
            break;

        case 3:
            cout << "Podaj klucz do wyszukania: ";
            cin >> key;
            cout << (search(root, key) ? "Klucz znajduje się w drzewie.\n" : "Klucz NIE znajduje się w drzewie.\n");
            break;

        case 4:
            cout << "Preorder: ";
            preorder(root);
            cout << endl;
            break;

        case 5:
            cout << "Inorder: ";
            inorder(root);
            cout << endl;
            break;

        case 6:
            cout << "Postorder: ";
            postorder(root);
            cout << endl;
            break;

        case 7:
            cout << "Inorder przed usunięciem: ";
            inorder(root);
            cout << "\nPodaj klucz do usunięcia: ";
            cin >> key;
            if (!search(root, key))
                cout << "Klucz NIE istnieje.\n";
            else {
                root = deleteNode(root, key);
                cout << "Inorder po usunięciu: ";
                inorder(root);
                cout << endl;
            }
            break;

        case 8:
            deleteTree(root);
            cout << "Drzewo zostało usunięte.\n";
            break;

        case 9:
            cout << "Zamykanie programu...\n";
            deleteTree(root);
            break;

        default:
            cout << "Niepoprawna opcja!\n";
        }
    } while (choice != 9);

    return 0;
}
