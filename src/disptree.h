#ifndef DISPTREE_LIB
#define DISPTREE_LIB

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdarg.h>

/***************************/
/*       Structs           */
/***************************/
typedef struct Node{
    int num;
    struct Node *left;
    struct Node *right;
}Node;

typedef enum Color {RED, BLACK} Color;

typedef struct RBNode{
    int num;
    struct RBNode *left;
    struct RBNode *right;
    Color color;
}RBNode;


/***************************/
/*       Prototypes        */
/***************************/

// Exposed 
Node *createNode(int num);
RBNode *createRBNode(int num);

void ______BIN_TREE_INTERNAL_FUNC_____0x0(Node* root, ...);
void ______BIN_TREE_INTERNAL_FUNC_____0x1(RBNode* root, ...);

// For dispTree to accept both Node and RBNode
#ifndef __cplusplus

// Internal

#define dispTree(x) _Generic((x),\
    Node* : ______BIN_TREE_INTERNAL_FUNC_____0x0,\
    RBNode* : ______BIN_TREE_INTERNAL_FUNC_____0x1 \
)(x)

#else 

inline void dispTree(Node* root)
{
    ______BIN_TREE_INTERNAL_FUNC_____0x0(root);
}

inline void dispTree(RBNode* root)
{
    ______BIN_TREE_INTERNAL_FUNC_____0x1(root);
}

#endif

#endif