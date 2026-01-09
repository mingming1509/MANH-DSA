#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char v;
    struct Node *l;
    struct Node *r;
};

struct Node *newNode(char v)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->v = v;
    n->l = NULL;
    n->r = NULL;
    return n;
}

int main()
{
    struct Node *root = newNode(' ');
    root->l = newNode(' ');
    root->r = newNode(' ');
    root->l->l = newNode('L');
    root->l->r = newNode('S');
    root->r->l = newNode('A');
    root->r->r = newNode('O');

    char s[10];
    scanf("%s", s);

    struct Node *cur = root;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '0')
            cur = cur->l;
        else
            cur = cur->r;
    }

    if (cur->v == 'L')
        printf("LOAD\n");
    else if (cur->v == 'S')
        printf("STORE\n");
    else if (cur->v == 'A')
        printf("AND\n");
    else if (cur->v == 'O')
        printf("OR\n");

    return 0;
}

/*
1. Data Structure (1 pt):
   struct Node { char v; Node *l; Node *r; };

2. Time Complexity (1 pt): O(k)
   - k = code length, one step per bit

3. Rules for Adding/Removing (2 pts):
   - Operations only at leaf nodes
   - No code is prefix of another
   - Internal nodes have 2 children
*/
