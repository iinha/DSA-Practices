#include <iostream>
#include <string>
using namespace std;

// Implement a stack of characters yourself (array or linked list, do NOT use std::stack)
// and use it to write the function below:
//   bool isBalanced(const string& s)
//     Return true if the bracket string s is valid (every opener is closed by the
//     matching closer in the correct nesting order), otherwise false.

struct Node {
    char data;
    Node* next;
};

struct CharStack {
    Node* topNode;
    CharStack() {
        topNode = nullptr;
    }
    ~CharStack() {
        while (!isEmpty()) {
            pop();
        }
    }
    void push(char c) {
        Node* newNode = new Node();
        newNode->data = c;
        newNode->next = topNode;
        topNode = newNode;
    }
    void pop() {
        if (topNode != nullptr) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }

    }
    char top() {
        if (topNode != nullptr) {
            return topNode->data;
        }
        return '\0';
    }
    bool isEmpty() {
        return topNode == nullptr;
    }
};

bool isBalanced(const string& s) {
    CharStack stack;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (stack.isEmpty()) {
                return false;
            }
            char topChar = stack.top();
            stack.pop();

            if ((c == ')' && topChar != '(') || (c == '}' && topChar != '{') || (c == ']' && topChar != '[')) return false;
        }
    }
    return stack.isEmpty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    cout << (isBalanced(s) ? "YES" : "NO") << '\n';

    return 0;
}
