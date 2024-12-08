#include <stdio.h>
#include <stdlib.h>

// Structure definition for a binary tree node
typedef struct tnode {
    char value;
    struct tnode* left;
    struct tnode* right;
} tnode;

// Function prototypes
tnode* make_btree(int x);
void free_btree(tnode** btree_head);

int main(void)
{
    // Create a binary tree with depth 4
    tnode* btree_head = make_btree(4);
    // Print the memory address of the tree's root node
    printf("%p\n", btree_head);

    // Free the binary tree and reset its pointer
    free_btree(&btree_head);
    // Print the tree's root pointer (should be NULL)
    printf("%p\n", btree_head);
}

// Recursively frees memory used by the binary tree
void free_btree(tnode** btree_head)
{
    // Check if the current node exists
    if (*btree_head != NULL)
    {
        // Recursively free the left and right subtrees
        free_btree(&(*btree_head)->left);
        free_btree(&(*btree_head)->right);
        // Free the current node
        free(*btree_head);
        // Set the pointer to NULL to avoid dangling pointers
        *btree_head = NULL;
    }
}

// Creates a binary tree of depth 'x'
tnode* make_btree(int x)
{
    // Allocate memory for a new tree node
    tnode* n = malloc(sizeof(tnode));
    if (n == NULL)
        return NULL; // Handle memory allocation failure

    // Base case: if depth < 3, create a leaf node
    if (x < 3)
    {
        // Leaf nodes have no children
        n->left = n->right = NULL;
        return n;
    }

    // Recursively create left and right subtrees with reduced depth
    n->left = make_btree(x - 1);
    n->right = make_btree(x - 1);
    return n;
}
