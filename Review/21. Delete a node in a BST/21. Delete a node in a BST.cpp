

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

bool firstPrinted = false;
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    if (firstPrinted) cout << ' ';
    firstPrinted = true;
    cout << root->data;
    inorder(root->right);
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
    int d;
    cin >> d;
    for (int i = 0; i < d; i++) {
        int x;
        cin >> x;
        root = deleteNode(root, x);
    }
    inorder(root);
    cout << "\n";
    return 0;
}
