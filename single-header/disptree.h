#ifndef DISPTREE_LIB
#define DISPTREE_LIB

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdarg.h>

/***************************/
/*       Macros            */
/***************************/
// For the js file, (canvas).. Refer to script.js in 
#define OUTER_RAD 25                    // Circle outer radius
#define INNER_RAD 21                    // Circle inner radius
#define LINE_WIDTH 4                    // Node connecting lines width
#define DEFAULT_TREE_COLOR "#007bff"    
#define DEFAULT_BG_COLOR "#161617"
#define BLACK_COLOR "#000000"
#define RED_COLOR "#ff0000"
#define GREY_COLOR "#404040"
#define Y_DIS 80                   // Vertical distance between parent and child node
#define X_DIS 60                   // Horizontal distance between two sibling nodes at same level
#define FOLDER_NAME "disptree files"

// Assuming that screen is 1920*1080
#define Y_MAX_ASSUMED 940          // Assumption that browsers max height 
#define X_MAX_ASSUMED 1880         // Assumption that browsers max width


// Macros for functions 
#define max ______BIN_TREE_INTERNAL_FUNC_____0x4
#define inorder ______BIN_TREE_INTERNAL_FUNC_____0x3

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
/*       Constants         */
/***************************/
static const unsigned char jsCode1[] = {
  0x64, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x2e, 0x61, 0x64, 0x64,
  0x45, 0x76, 0x65, 0x6e, 0x74, 0x4c, 0x69, 0x73, 0x74, 0x65, 0x6e, 0x65,
  0x72, 0x28, 0x27, 0x44, 0x4f, 0x4d, 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e,
  0x74, 0x4c, 0x6f, 0x61, 0x64, 0x65, 0x64, 0x27, 0x2c, 0x20, 0x28, 0x29,
  0x20, 0x3d, 0x3e, 0x20, 0x7b, 0x0a, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x63,
  0x6f, 0x6e, 0x73, 0x74, 0x20, 0x63, 0x61, 0x6e, 0x76, 0x61, 0x73, 0x20,
  0x3d, 0x20, 0x64, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74, 0x2e, 0x67,
  0x65, 0x74, 0x45, 0x6c, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x42, 0x79, 0x49,
  0x64, 0x28, 0x27, 0x6d, 0x79, 0x43, 0x61, 0x6e, 0x76, 0x61, 0x73, 0x27,
  0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x63, 0x6f, 0x6e, 0x73, 0x74,
  0x20, 0x63, 0x74, 0x78, 0x20, 0x3d, 0x20, 0x63, 0x61, 0x6e, 0x76, 0x61,
  0x73, 0x2e, 0x67, 0x65, 0x74, 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x78, 0x74,
  0x28, 0x27, 0x32, 0x64, 0x27, 0x29, 0x3b
};
static const unsigned int jsCode1Len = 151;
static const unsigned char jsCode2[] = {
  0x66, 0x75, 0x6e, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x64, 0x72, 0x61,
  0x77, 0x4c, 0x69, 0x6e, 0x65, 0x28, 0x78, 0x31, 0x2c, 0x20, 0x79, 0x31,
  0x2c, 0x20, 0x78, 0x32, 0x2c, 0x20, 0x79, 0x32, 0x29, 0x20, 0x7b, 0x0a,
  0x20, 0x20, 0x20, 0x20, 0x63, 0x74, 0x78, 0x2e, 0x62, 0x65, 0x67, 0x69,
  0x6e, 0x50, 0x61, 0x74, 0x68, 0x28, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20,
  0x20, 0x63, 0x74, 0x78, 0x2e, 0x6d, 0x6f, 0x76, 0x65, 0x54, 0x6f, 0x28,
  0x52, 0x4f, 0x4f, 0x54, 0x5f, 0x58, 0x43, 0x4f, 0x52, 0x2b, 0x78, 0x31,
  0x2c, 0x20, 0x52, 0x4f, 0x4f, 0x54, 0x5f, 0x59, 0x43, 0x4f, 0x52, 0x2b,
  0x79, 0x31, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x63, 0x74, 0x78,
  0x2e, 0x6c, 0x69, 0x6e, 0x65, 0x54, 0x6f, 0x28, 0x52, 0x4f, 0x4f, 0x54,
  0x5f, 0x58, 0x43, 0x4f, 0x52, 0x2b, 0x78, 0x32, 0x2c, 0x20, 0x52, 0x4f,
  0x4f, 0x54, 0x5f, 0x59, 0x43, 0x4f, 0x52, 0x2b, 0x79, 0x32, 0x29, 0x3b,
  0x0a, 0x20, 0x20, 0x20, 0x20, 0x63, 0x74, 0x78, 0x2e, 0x73, 0x74, 0x72,
  0x6f, 0x6b, 0x65, 0x53, 0x74, 0x79, 0x6c, 0x65, 0x20, 0x3d, 0x20, 0x4c,
  0x49, 0x4e, 0x45, 0x5f, 0x43, 0x4f, 0x4c, 0x4f, 0x52, 0x3b, 0x0a, 0x20,
  0x20, 0x20, 0x20, 0x63, 0x74, 0x78, 0x2e, 0x6c, 0x69, 0x6e, 0x65, 0x57,
  0x69, 0x64, 0x74, 0x68, 0x20, 0x3d, 0x20, 0x4c, 0x49, 0x4e, 0x45, 0x5f,
  0x57, 0x49, 0x44, 0x54, 0x48, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x63,
  0x74, 0x78, 0x2e, 0x73, 0x74, 0x72, 0x6f, 0x6b, 0x65, 0x28, 0x29, 0x3b,
  0x0a, 0x7d, 0x0a, 0x0a, 0x66, 0x75, 0x6e, 0x63, 0x74, 0x69, 0x6f, 0x6e,
  0x20, 0x64, 0x72, 0x61, 0x77, 0x43, 0x69, 0x72, 0x63, 0x6c, 0x65, 0x28,
  0x78, 0x2c, 0x79, 0x2c, 0x72, 0x61, 0x64, 0x69, 0x75, 0x73, 0x2c, 0x63,
  0x6f, 0x6c, 0x6f, 0x72, 0x29, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x63,
  0x74, 0x78, 0x2e, 0x62, 0x65, 0x67, 0x69, 0x6e, 0x50, 0x61, 0x74, 0x68,
  0x28, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x63, 0x74, 0x78, 0x2e,
  0x61, 0x72, 0x63, 0x28, 0x78, 0x2c, 0x20, 0x79, 0x2c, 0x20, 0x72, 0x61,
  0x64, 0x69, 0x75, 0x73, 0x2c, 0x20, 0x30, 0x2c, 0x20, 0x32, 0x20, 0x2a,
  0x20, 0x4d, 0x61, 0x74, 0x68, 0x2e, 0x50, 0x49, 0x29, 0x3b, 0x0a, 0x20,
  0x20, 0x20, 0x20, 0x63, 0x74, 0x78, 0x2e, 0x66, 0x69, 0x6c, 0x6c, 0x53,
  0x74, 0x79, 0x6c, 0x65, 0x20, 0x3d, 0x20, 0x63, 0x6f, 0x6c, 0x6f, 0x72,
  0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x63, 0x74, 0x78, 0x2e, 0x66, 0x69,
  0x6c, 0x6c, 0x28, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x63, 0x74,
  0x78, 0x2e, 0x73, 0x74, 0x72, 0x6f, 0x6b, 0x65, 0x53, 0x74, 0x79, 0x6c,
  0x65, 0x20, 0x3d, 0x20, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x3b, 0x0a, 0x20,
  0x20, 0x20, 0x20, 0x63, 0x74, 0x78, 0x2e, 0x73, 0x74, 0x72, 0x6f, 0x6b,
  0x65, 0x28, 0x29, 0x3b, 0x0a, 0x7d, 0x0a, 0x0a, 0x66, 0x75, 0x6e, 0x63,
  0x74, 0x69, 0x6f, 0x6e, 0x20, 0x64, 0x72, 0x61, 0x77, 0x4e, 0x6f, 0x64,
  0x65, 0x28, 0x6e, 0x75, 0x6d, 0x2c, 0x20, 0x78, 0x2c, 0x20, 0x79, 0x2c,
  0x20, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x29, 0x20, 0x7b, 0x0a, 0x20, 0x20,
  0x20, 0x20, 0x64, 0x72, 0x61, 0x77, 0x43, 0x69, 0x72, 0x63, 0x6c, 0x65,
  0x28, 0x52, 0x4f, 0x4f, 0x54, 0x5f, 0x58, 0x43, 0x4f, 0x52, 0x2b, 0x78,
  0x2c, 0x52, 0x4f, 0x4f, 0x54, 0x5f, 0x59, 0x43, 0x4f, 0x52, 0x2b, 0x79,
  0x2c, 0x4f, 0x55, 0x54, 0x45, 0x52, 0x5f, 0x52, 0x41, 0x44, 0x2c, 0x63,
  0x6f, 0x6c, 0x6f, 0x72, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x64,
  0x72, 0x61, 0x77, 0x43, 0x69, 0x72, 0x63, 0x6c, 0x65, 0x28, 0x52, 0x4f,
  0x4f, 0x54, 0x5f, 0x58, 0x43, 0x4f, 0x52, 0x2b, 0x78, 0x2c, 0x52, 0x4f,
  0x4f, 0x54, 0x5f, 0x59, 0x43, 0x4f, 0x52, 0x2b, 0x79, 0x2c, 0x49, 0x4e,
  0x4e, 0x45, 0x52, 0x5f, 0x52, 0x41, 0x44, 0x2c, 0x42, 0x47, 0x5f, 0x43,
  0x4f, 0x4c, 0x4f, 0x52, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x63,
  0x74, 0x78, 0x2e, 0x66, 0x6f, 0x6e, 0x74, 0x20, 0x3d, 0x20, 0x27, 0x32,
  0x30, 0x70, 0x78, 0x20, 0x41, 0x72, 0x69, 0x61, 0x6c, 0x27, 0x3b, 0x0a,
  0x20, 0x20, 0x20, 0x20, 0x63, 0x74, 0x78, 0x2e, 0x66, 0x69, 0x6c, 0x6c,
  0x53, 0x74, 0x79, 0x6c, 0x65, 0x20, 0x3d, 0x20, 0x27, 0x77, 0x68, 0x69,
  0x74, 0x65, 0x27, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x63, 0x74, 0x78,
  0x2e, 0x74, 0x65, 0x78, 0x74, 0x41, 0x6c, 0x69, 0x67, 0x6e, 0x20, 0x3d,
  0x20, 0x27, 0x63, 0x65, 0x6e, 0x74, 0x65, 0x72, 0x27, 0x3b, 0x0a, 0x20,
  0x20, 0x20, 0x20, 0x63, 0x74, 0x78, 0x2e, 0x74, 0x65, 0x78, 0x74, 0x42,
  0x61, 0x73, 0x65, 0x6c, 0x69, 0x6e, 0x65, 0x20, 0x3d, 0x20, 0x27, 0x6d,
  0x69, 0x64, 0x64, 0x6c, 0x65, 0x27, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20,
  0x63, 0x74, 0x78, 0x2e, 0x66, 0x69, 0x6c, 0x6c, 0x54, 0x65, 0x78, 0x74,
  0x28, 0x6e, 0x75, 0x6d, 0x2c, 0x20, 0x78, 0x2b, 0x52, 0x4f, 0x4f, 0x54,
  0x5f, 0x58, 0x43, 0x4f, 0x52, 0x2c, 0x20, 0x79, 0x2b, 0x52, 0x4f, 0x4f,
  0x54, 0x5f, 0x59, 0x43, 0x4f, 0x52, 0x29, 0x3b, 0x0a, 0x7d
};
static const unsigned int jsCode2Len = 754;

/***************************/
/*       Variables         */
/***************************/
static int callTimes = 0;                      // No.of times dispTree is called

/***************************/
/*       Prototypes        */
/***************************/

// Exposed 
Node *createNode(int num);
RBNode *createRBNode(int num);

// Internal
void ______BIN_TREE_INTERNAL_FUNC_____0x0(Node* root, ...);
void ______BIN_TREE_INTERNAL_FUNC_____0x1(RBNode* root, ...);
void ______BIN_TREE_INTERNAL_FUNC_____0x2(void* root, int isRB);
int  ______BIN_TREE_INTERNAL_FUNC_____0x3(void* root, FILE* lineFile, FILE* circleFile,int* xLevel, int yLevel, int* yExtreme, int isRB);
int  ______BIN_TREE_INTERNAL_FUNC_____0x4(int a, int b);

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

/***************************/
/*       Functions         */
/***************************/

// Exposed Functions 
Node *createNode(int num)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->num = num;
    node->left = NULL;
    node->right = NULL;
    return node;
}

RBNode* createRBNode(int num)
{
    RBNode* newNode = (RBNode*)malloc(sizeof(RBNode));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->num = num;
    newNode->color = RED;
    return newNode;
}

// Internal Functions 

void ______BIN_TREE_INTERNAL_FUNC_____0x0(Node* root, ...)
{
    va_list args;
    va_start(args, root);
    char* customString = va_arg(args, char*);

    ______BIN_TREE_INTERNAL_FUNC_____0x2((void *)root, 0);//, customString);
}

void ______BIN_TREE_INTERNAL_FUNC_____0x1(RBNode *root, ...)
{
    va_list args;
    va_start(args, root);
    char* customString = va_arg(args, char*);

    ______BIN_TREE_INTERNAL_FUNC_____0x2((void *)root, 1);//, customString);
}

void ______BIN_TREE_INTERNAL_FUNC_____0x2(void* root, int isRB)
{

    struct stat st;
    if (stat(FOLDER_NAME, &st) == -1) {
        if (mkdir(FOLDER_NAME, 0755) != 0){
            printf("Failed to create folder '%s'.\n", FOLDER_NAME);
            return;
        }
    }

    callTimes++;        //No.of times function called is increased..
    if (root == NULL)
        return;

    char buffer[1024];
    char fileName[50];  //Contains the filename..

    sprintf(fileName,"%s/script-%d.js",FOLDER_NAME, callTimes);
    FILE *jsFile1= fopen(fileName, "wb"); 

    if (jsFile1==NULL){
        printf("\n --- Couldn't create/open a file in this directory --- \n");
        return;
    }

    fwrite(jsCode1, 1, jsCode1Len,jsFile1);     //Writing stuff from jsCode-1.js (which is in hex inside js-code-1.h) into jsCode1 (script-%d.js)
    fclose(jsFile1);

    jsFile1 = fopen(fileName, "a");             //Reopening it to add these.. (refer to script.js in ..)
    fprintf(jsFile1, "const OUTER_RAD = %d;\n", OUTER_RAD);
    fprintf(jsFile1, "const INNER_RAD = %d;\n", INNER_RAD);
    fprintf(jsFile1, "const LINE_WIDTH = %d;\n", LINE_WIDTH);
    fprintf(jsFile1, "const DEFAULT_TREE_COLOR = \"%s\";\n", DEFAULT_TREE_COLOR);

    if (isRB == 1){
        fprintf(jsFile1, "const LINE_COLOR = \"%s\";\n", DEFAULT_BG_COLOR);
        fprintf(jsFile1, "const BG_COLOR = \"%s\";\n", GREY_COLOR);
    }
    else{ 
        fprintf(jsFile1, "const BG_COLOR = \"%s\";\n", DEFAULT_BG_COLOR);
        fprintf(jsFile1, "const LINE_COLOR = \"%s\";\n", DEFAULT_TREE_COLOR);
    }

    FILE *jsFile2 = fopen("jsFile2.js", "wb");
    if (jsFile2==NULL){
        printf("\n --- Couldn't create/open a file in this directory --- \n");
        return;
    }
    fwrite(jsCode2, 1, jsCode2Len,jsFile2);     //Writing stuff from jsCode-2.js (which is in hex inside js-code-2.h) into jsCode2
    fclose(jsFile2);    
    
    //Reopening it, to write the coordinates of lines..
    jsFile2 = fopen("jsFile2.js", "a");         

    sprintf(fileName,"circles-%d.txt",callTimes);   
    FILE *circleFile = fopen(fileName,"w");      //creating circelFile to write the circle coordinates in this file

    int leftXExtreme, leftYExtreme, rightXExtreme, rightYExtreme, childXCor;
    leftXExtreme = -1;  //xLevel for left subtree
    rightXExtreme = 1;  //xLevel for right subtree
    leftYExtreme = rightYExtreme = 0;   //initial heightd of bothe left and right subtrees are 0

    void *address ;
    if (isRB == 1)
        address = (void *)(((RBNode *)root)->left);
    else 
        address = (void *)(((Node *)root)->left);

    childXCor = inorder(address, jsFile2, circleFile,&leftXExtreme, 1, &leftYExtreme, isRB);       //xCor of the left child

    if (childXCor!=0)
        fprintf(jsFile2, "drawLine(%d, %d, %d, %d);\n",(childXCor)*X_DIS, Y_DIS, 0, 0);             //Connecting root and left child
    
    if (isRB == 1)
        address = (void *)(((RBNode *)root)->right);
    else 
        address = (void *)(((Node *)root)->right);

    childXCor = inorder(address, jsFile2, circleFile, &rightXExtreme,1, &rightYExtreme, isRB);    //xcor of the right child
    if (childXCor!=0)
        fprintf(jsFile2, "drawLine(%d, %d, %d, %d);\n",(childXCor)*X_DIS, Y_DIS, 0, 0);             //Connecting root and right child

    fclose(circleFile);
    circleFile = fopen(fileName,"r");

    int num;
    if (isRB == 1)
        num = ((RBNode *)root)->num;
    else 
        num = ((Node *)root)->num;

    if (isRB == 1){
        if (((RBNode *)root)->color == RED)
            fprintf(jsFile2, "drawNode(%d, %d, %d, \"%s\");\n",num, 0,0, RED_COLOR);
        else 
            fprintf(jsFile2, "drawNode(%d, %d, %d, \"%s\");\n",num, 0,0, BLACK_COLOR);
    }
    else 
        fprintf(jsFile2, "drawNode(%d, %d, %d, DEFAULT_TREE_COLOR);\n",num, 0,0);

    while (fgets(buffer, sizeof(buffer), circleFile) != NULL)      //Writing all the circle coordinates from circlefile into js file
        fputs(buffer, jsFile2);

    fclose(circleFile);
    remove(fileName);           //deleting circleFile
    fclose(jsFile2);           

    int treeHeight = max(leftYExtreme, rightYExtreme);          //Height = max(rightSubtree height, leftsubtree hright)        
    int treeWidth = max(-1*leftXExtreme, rightXExtreme)*2;

    int canvasHeight, canvasWidth;

    if (Y_MAX_ASSUMED < (treeHeight+2)*Y_DIS)
        canvasHeight = (treeHeight+2)*Y_DIS;
    else
        canvasHeight = Y_MAX_ASSUMED;

    if (X_MAX_ASSUMED < (treeWidth)*X_DIS)
        canvasWidth = (treeWidth)*X_DIS;
    else 
        canvasWidth = X_MAX_ASSUMED;

    // Creating html file
    sprintf(fileName,"%s/Binary-tree-%d.html",FOLDER_NAME, callTimes);
    FILE* htmlFile = fopen(fileName,"w");

    if (htmlFile==NULL){
        printf("\n --- Couldn't create/open a file in this directory --- \n");
        return;
    }
    // adding the Canvaswidth, canvasheight and linking the js..
    if (isRB == 1)
        fprintf(htmlFile,"<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><title>Binary tree</title><style>body {background-color: %s;margin: 0;}</style></head><body><canvas id=\"myCanvas\" width=\"%d\" height=\"%d\"></canvas><script src=\"script-%d.js\"></script></body></html>",GREY_COLOR,canvasWidth, canvasHeight,callTimes);
    else
        fprintf(htmlFile,"<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><title>Binary tree</title><style>body {background-color: %s;margin: 0;}</style></head><body><canvas id=\"myCanvas\" width=\"%d\" height=\"%d\"></canvas><script src=\"script-%d.js\"></script></body></html>",DEFAULT_BG_COLOR,canvasWidth, canvasHeight,callTimes);

    fclose(htmlFile);

    //Writing the root coordinates in to jsFile1 (script-%d.js)
    fprintf(jsFile1, "const ROOT_XCOR = %d;\n", canvasWidth/2);
    fprintf(jsFile1, "const ROOT_YCOR = %d;\n", (canvasHeight - treeHeight*Y_DIS)/2);

    jsFile2 = fopen("jsFile2.js","r");
    while (fgets(buffer, sizeof(buffer), jsFile2) != NULL) 
        fputs(buffer, jsFile1);                 //adding contents of jsfile2 to jsfile1(script-%d.js)
    fclose(jsFile2);
    remove("jsFile2.js");                      //deleting jsfile2.js

    // if (customString){
    //     fprintf(jsFile1, "\nctx.font = \"24px Arial\";\nctx.fillStyle = \"white\";\nctx.fillText(\"%s\", ROOT_XCOR, ROOT_YCOR);\n",customString);
    // }
    fprintf(jsFile1, "\n});\n");
    fclose(jsFile1);

    sprintf(buffer, "xdg-open \"%s/Binary-tree-%d.html\" 2>/dev/null", FOLDER_NAME, callTimes); //opening the html file..
    system(buffer);
}

int  ______BIN_TREE_INTERNAL_FUNC_____0x3(void* root, FILE* lineFile, FILE* circleFile,int* xLevel, int yLevel, int* yExtreme, int isRB)
{
    if (root == NULL)
        return 0;

    int childXCor, retVal;

    Node *rootNode = NULL;
    RBNode *rootRBNode = NULL;
    void *address;

    if (isRB){
        rootRBNode = (RBNode*)root;
        if ((*xLevel) > 0)      //Inorder Left-Root-Right
            retVal = inorder((void*)(rootRBNode->left), lineFile, circleFile, xLevel,yLevel+1, yExtreme, isRB);
        else                   //Reverse Inorder Right-Root-Left   
            retVal = inorder((void*)(rootRBNode->right), lineFile, circleFile, xLevel,yLevel+1,yExtreme, isRB);
    }
    else {
        rootNode = (Node*)root;
        if ((*xLevel) > 0)      //Inorder Left-Root-Right
            retVal = inorder((void*)(rootNode->left), lineFile, circleFile, xLevel,yLevel+1, yExtreme, isRB);
        else                   //Reverse Inorder Right-Root-Left   
            retVal = inorder((void*)(rootNode->right), lineFile, circleFile, xLevel,yLevel+1,yExtreme, isRB);
    }

    if (retVal != 0)        //if retval is zero, it means it encountered NULL child (refer inorder 1st line..)
        fprintf(lineFile, "drawLine(%d, %d, %d, %d);\n",(*xLevel)*X_DIS, yLevel*Y_DIS, (retVal)*X_DIS, (yLevel+1)*Y_DIS);
    
    if (isRB){
        if (rootRBNode->color == RED)
            fprintf(circleFile, "drawNode(%d, %d, %d, \"%s\");\n",rootRBNode->num, (*xLevel)*X_DIS, (yLevel)*Y_DIS, RED_COLOR);
        else
            fprintf(circleFile, "drawNode(%d, %d, %d, \"%s\");\n",rootRBNode->num, (*xLevel)*X_DIS, (yLevel)*Y_DIS, BLACK_COLOR);
    }
    else 
        fprintf(circleFile, "drawNode(%d, %d, %d, DEFAULT_TREE_COLOR);\n",rootNode->num, (*xLevel)*X_DIS, (yLevel)*Y_DIS);
    
    childXCor = *xLevel;

    if ((*xLevel) < 0)          //for left subtree, shifting away from 0, towards -ve  (refer dispTree)
        (*xLevel) = *xLevel-1;  
    else                        //for right subtree, shifting away from 0, towards +ve  (refer dispTree)
        (*xLevel) = *xLevel+1;

    if (*yExtreme < yLevel)     //yExtreme has the height of the tree..
        *yExtreme = yLevel;

    if (isRB){
        if (*xLevel > 0)       // Inorder Left-Root-Right
            retVal = inorder((void*)(rootRBNode->right), lineFile, circleFile, xLevel, yLevel+1, yExtreme, isRB);
        else                   // Reverse Inorder Right-Root-Left  
            retVal = inorder((void *)(rootRBNode->left), lineFile, circleFile, xLevel, yLevel+1, yExtreme, isRB);
    }
    else{
        if (*xLevel > 0)       // Inorder Left-Root-Right
            retVal = inorder((void*)(rootNode->right), lineFile, circleFile, xLevel, yLevel+1, yExtreme, isRB);
        else                   // Reverse Inorder Right-Root-Left  
            retVal = inorder((void*)(rootNode->left), lineFile, circleFile, xLevel, yLevel+1, yExtreme, isRB);        
    }

    if (retVal !=0 )
        //Using childXCor here as the xLevel is changed in if and else....
        fprintf(lineFile, "drawLine(%d, %d, %d, %d);\n",(childXCor)*X_DIS, (yLevel)*Y_DIS, (retVal)*X_DIS, (yLevel+1)*Y_DIS);

    //returns the X coordinate of the current node
    return childXCor;
}

int  ______BIN_TREE_INTERNAL_FUNC_____0x4(int a, int b)
{
    if (a > b)
        return a;
    else 
    return b;
}

#undef OUTER_RAD
#undef INNER_RAD
#undef LINE_WIDTH 
#undef DEFAULT_TREE_COLOR
#undef DEFAULT_BG_COLOR
#undef BLACK_COLOR
#undef RED_COLOR
#undef GREY_COLOR
#undef Y_DIS
#undef X_DIS
#undef FOLDER_NAME
#undef Y_MAX_ASSUMED
#undef X_MAX_ASSUMED
#undef max
#undef inorder 

#endif