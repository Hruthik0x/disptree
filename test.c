// Can be used with both g++ and gcc compilers

#include <disptree.h>

void normal_tree () 
{
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    dispTree(root);
}

void RB_tree ()
{
   RBNode* root = createRBNode(10);
    root->color = BLACK; // Root must be black

    root->left = createRBNode(5);
    root->right = createRBNode(15);

    root->left->left = createRBNode(3);
    root->left->left->color = BLACK;

    root->left->right = createRBNode(7);
    root->left->right->color = BLACK;

    root->right->left = createRBNode(13);
    root->right->left->color = BLACK;

    root->right->right = createRBNode(17);
    root->right->right->color = BLACK;

    dispTree(root);
}

int main()
{
    normal_tree();
    RB_tree();
    return 0;
}