#include <iostream>
using namespace std;

struct Node {
    char op;
    Node *left;
    Node *right;
};

Node* createNode(char op) {
    Node *node = new Node;
    node->op = op;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    Node *root = createNode(' ');
    root->left = createNode(' ');
    root->right = createNode(' ');
    root->left->left = createNode('L');
    root->left->right = createNode('S');
    root->right->left = createNode('A');
    root->right->right = createNode('O');

    char code[10];
    cin >> code;

    Node *cur = root;
    for (int i = 0; code[i] != '\0'; i++) {
        if (code[i] == '0')
            cur = cur->left;
        else
            cur = cur->right;
    }

    if (cur->op == 'L') cout << "LOAD" << endl;
    else if (cur->op == 'S') cout << "STORE" << endl;
    else if (cur->op == 'A') cout << "AND" << endl;
    else if (cur->op == 'O') cout << "OR" << endl;

    return 0;
}

/*
1. Data Structure (1 pt):
   struct Node {
       char op;      // operation: L=LOAD, S=STORE, A=AND, O=OR
       Node *left;   // pointer to left child (0 branch)
       Node *right;  // pointer to right child (1 branch)
   };

2. Time Complexity of Decoding (1 pt): O(k)
   - k is the length of the binary code
   - Each bit requires one step from parent to child
   - Total: O(k)

3. Rules for Adding/Removing Operations (2 pts):
   - Operations must be at leaf nodes only
   - No code can be prefix of another code
   - Internal nodes must have exactly 2 children
   - When adding: expand a leaf into internal node with 2 children
   - When removing: if sibling is leaf, merge parent with sibling
*/
