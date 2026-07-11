#include <iostream>
#include <string>
#include <vector>
#include <queue>
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

// Build tree from level-order tokens where "N" denotes null.
Node* buildFromLevelOrder(const vector<string>& tokens) {
    if (tokens.empty() || tokens[0] == "N") return NULL;

    Node* root = createNode(stoi(tokens[0]));
    queue<Node*> q;
    q.push(root);
    size_t i = 1;
    while (!q.empty() && i < tokens.size()) {
        Node* cur = q.front(); q.pop();

        if (i < tokens.size()) {
            if (tokens[i] != "N") {
                cur->left = createNode(stoi(tokens[i]));
                q.push(cur->left);
            }
            i++;
        }
        if (i < tokens.size()) {
            if (tokens[i] != "N") {
                cur->right = createNode(stoi(tokens[i]));
                q.push(cur->right);
            }
            i++;
        }
    }
    return root;
}
int isValidBST(Node* root, Node* minNode = NULL, Node* maxNode = NULL) {
    if (root == NULL) return 1;

    if (minNode != NULL && root->data <= minNode->data) return 0;
    if (maxNode != NULL && root->data >= maxNode->data) return 0;

    return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
}
int main() {
    int k;
    cin >> k;

    vector<string> tokens(k);
    for (int i = 0; i < k; i++) cin >> tokens[i];

    Node* root = buildFromLevelOrder(tokens);
    cout << (isValidBST(root) ? "YES" : "NO") << endl;
    return 0;
}

