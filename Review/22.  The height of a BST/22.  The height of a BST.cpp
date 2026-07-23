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

int height(Node* root) {
    if (!root) return -1;
    int a = height(root->left);
    int b = height(root->right);
    return (a > b ? a : b) + 1;
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
    cout << height(root) << "\n";
    return 0;
}
