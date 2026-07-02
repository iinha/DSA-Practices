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

int countInRange(Node* root, int lo, int hi) {
    if (root == NULL) return 0;
    if (root->data > hi) {
        return countInRange(root->left, lo, hi);
    }
    if (root->data < lo) {
        return countInRange(root->right, lo, hi);
    }
    return 1 + countInRange(root->left, lo, hi) + countInRange(root->right, lo, hi);
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

    int lo, hi;
    cin >> lo >> hi;

    cout << countInRange(root, lo, hi) << endl;
    return 0;
}
