#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(Node*& root, Node* node) {
    if (root == NULL) {
        root = node;
        return;
    }

    if (node->data < root->data) {
        if (root->left == NULL) {
            root->left = node;
            return;
        }
        insertNode(root->left, node);
        return;
    }

    if (root->right == NULL) {
        root->right = node;
        return;
    }
    insertNode(root->right, node);
}

//   predecessor(root, x, out_found, out_val) -> largest value strictly less than x
//   successor(root, x, out_found, out_val)   -> smallest value strictly greater than x

void predecessor(Node* root, int x, bool& out_found, int& out_val) {
    out_found = false;
    while (root != NULL) {
        if (root->data < x) {
            out_found = true;
            out_val = root->data;
            root = root->right;
        }
        else {
            root = root->left;
        }
    }

}

void successor(Node* root, int x, bool& out_found, int &out_val) {
    out_found = false;
    while (root != NULL) {
        if (root->data > x) {
            out_found = true;
            out_val = root->data;
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
}

int main() {
    Node* root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        insertNode(root, createNode(data));
    }

    int x;
    cin >> x;

    bool pf, sf;
    int pv, sv;
    predecessor(root, x, pf, pv);
    successor(root, x, sf, sv);

    cout << "Pred: ";
    if (pf) cout << pv; else cout << "NONE";
    cout << "\nSucc: ";
    if (sf) cout << sv; else cout << "NONE";
    cout << "\n";
    return 0;
}
