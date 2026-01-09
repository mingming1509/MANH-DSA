#include <stdio.h>
#include <stdlib.h>

struct Node {
    char op;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(char op) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->op = op;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    struct Node *root = createNode(' ');
    root->left = createNode(' ');
    root->right = createNode(' ');
    root->left->left = createNode('L');
    root->left->right = createNode('S');
    root->right->left = createNode('A');
    root->right->right = createNode('O');

    char code[10];
    scanf("%s", code);

    struct Node *cur = root;
    for (int i = 0; code[i] != '\0'; i++) {
        if (code[i] == '0')
            cur = cur->left;
        else
            cur = cur->right;
    }

    if (cur->op == 'L') printf("LOAD\n");
    else if (cur->op == 'S') printf("STORE\n");
    else if (cur->op == 'A') printf("AND\n");
    else if (cur->op == 'O') printf("OR\n");

    return 0;
}

/*
1. Data Structure (1 pt):
   struct Node {
       char op;            // operation: L=LOAD, S=STORE, A=AND, O=OR
       struct Node *left;  // pointer to left child (0 branch)
       struct Node *right; // pointer to right child (1 branch)
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
