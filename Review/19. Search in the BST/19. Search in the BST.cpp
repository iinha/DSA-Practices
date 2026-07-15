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

int searchNode(Node* root, int x) {
    if (root == NULL) return 0;
    if (root->data == x) return 1;
    if (x < root->data) {
        return searchNode(root->left, x);
    }
    else {
        return searchNode(root->right, x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Node* root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        insertNode(root, createNode(data));
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        cout << (searchNode(root, x) ? "YES" : "NO") << "\n";
    }
    return 0;
}
