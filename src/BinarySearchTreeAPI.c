/**************************************
 * Name: Vicky Mohammad
 * ID: 0895381
**************************************/

//import the header of this class
#include "BinarySearchTreeAPI.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Creates a TreeNode. TreeNode children are set to NULL and data is set to the passed in data.
 * @param data - the data to be stored within the Node. 
 * @return Newly created TreeNode
 *
 */
TreeNode* createTreeNode(TreeDataPtr data){
    TreeNode* newTreeNode = malloc(sizeof(TreeNode));
    newTreeNode->data = data;
    newTreeNode->left = NULL;
    newTreeNode->right = NULL;
    return newTreeNode;
}//end func

/**
 * createBinTree allocates memory for Tree and assigned function pointers
 * @param  compare [Function pointer to Compare data in tree nodes]
 * @param  del     [Function pointer to delete data from node]
 * @return Newly created Tree
 */
Tree * createBinTree(CompareFunc compare, DeleteFunc del){
    Tree* newTree = malloc(sizeof(Tree));
    newTree->root = NULL;
    newTree->compareFunc = compare;
    newTree->deleteFunc = del;
    return newTree;
}//end func

/**
 * destroyBinTree - remove all items and free memory
 * @param  toDestroy - the tree
 * @return
 */
void destroyBinTree(Tree * toDestroy){
    deleteTree(toDestroy->root);
}//end func

/**
 * Add data to a tree
 * @param theTree 
 * @param data    
 */
void addToTree(Tree * theTree, TreeDataPtr data){
    //var for start
    TreeNode* currentNode = theTree->root;
    TreeNode* parentNode = theTree->root;
    TreeNode* nodeToBeAdded = createTreeNode(data);    

    //if the tree is null add the node
    if(theTree->root == NULL){
        theTree->root = nodeToBeAdded;
        return;
    }//end if

    //iterate through the list
    while(1) { 
        //save the parent node
        parentNode = currentNode;
        
        //compare the size
        if(theTree->compareFunc(data, parentNode->data) < 0) {
            //go to left of the tree
            currentNode = currentNode->left;          
            
            //insert to the left
            if(currentNode == NULL) {
                parentNode->left = nodeToBeAdded;
                return;
            }//end if
        }else {
            //go to right of the tree
            currentNode = currentNode->right;

            //insert to the right
            if(currentNode == NULL) {
                parentNode->right = nodeToBeAdded;
                return;
            }//end if 
        }//end if
    }//end while
}//end func

/**
 * Remove data from the tree
 * @param theTree 
 * @param data    
 */
void removeFromTree(Tree * theTree, TreeDataPtr data){
    theTree->root = deleteTraversal(theTree->root, data, theTree->compareFunc);
}//end if

/**
 * This function searches the tree for the target data
 * @param  theTree 
 * @param  data    
 * @return         NULL if fail, otherwise return data
 */
TreeDataPtr findInTree( Tree* theTree, TreeDataPtr data ){
    //decalre var
    TreeNode* nodeToBeReturn = searchNode(theTree->root, data, theTree->compareFunc);
    //check if its null
    if(nodeToBeReturn == NULL){
        return NULL;
    }else{
        return nodeToBeReturn->data;
    }//end if 
}//end if

/**
 * Get data from the root of the Tree if it exists.
 * @param  theTree 
 * @return NULL if tree is empty, otherwise return root
 */
TreeDataPtr getRootData(Tree * theTree){
    return theTree->root;
}//end func

/**
 * [printInOrder This function prints the tree using an inOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printInOrder(Tree * theTree, PrintFunc printData){
    printTraversal(theTree->root, IN_ORDER, printData);
}//end func

/**
 * [printPreOrder This function prints the tree using an preOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printPreOrder(Tree * theTree, PrintFunc printData){
    printTraversal(theTree->root, PRE_ORDER, printData);
}//end func

/**
 * [printPostOrder This function prints the tree using an postOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printPostOrder(Tree * theTree, PrintFunc printData){
    printTraversal(theTree->root, POST_ORDER, printData);
}//end func

/**
 * Checks if a tree is empty
 * @param  theTee [description]
 * @return        0 if false, 1 otherwise
 */
int isTreeEmpty(Tree* theTree){
    if(theTree == NULL){
        return 0;
    }//end if
    return 1;
}//end func

/**
 * Helper function for checking if a single node is a leaf (no children)
 * @param  treeNode [description]
 * @return          0 if false, 1 otherwise
 */
int isLeaf( TreeNode * treeNode){
    //check to see if it is a leaf
    //if both are null then return
    if(treeNode->left == NULL && treeNode->right == NULL){
        return 1;
    }else{
        return 0;
    }//end if
}//end if

/**
 * Helper funciton for checking if a single node has two children.
 * @param  treeNode [description]
 * @return         0 if false, 1 otherwise
 */
int hasTwoChildren( TreeNode *treeNode){
    //check to see if it has two children
    //if both are null then return
    if(treeNode->left == NULL && treeNode->right == NULL){
        return 0;
    }else{
        return 1;
    }//end if
}//end fund

/**
 * Helper funciton Get the height of a particulat Node in the tree. 
 * @param  treeNode [description]
 * @return    (1-Based) heigh for the tree. 
 */
int getHeight( TreeNode* treeNode ){
    //check if the first one is null
    if (treeNode == NULL) {
        return -1;
    }//end if

    //assigned the left and right in temp
    int left = getHeight(treeNode->left);
    int right = getHeight(treeNode->right);

    //check which one is greater
    if (left > right) {
        return left + 1;
    } else {
        return right + 1;
    }//end if
}//end func

/*************************************************************************************************
 * You may add additional API functions below this comment if you want to extend the funcitonality.
 *************************************************************************************************/

/**
 * add a string to any ptr
 * @param string for the string to add
 * @return char* of the string
 */
char* addString(const char* string){
    char* temp = malloc(sizeof(char)*99);
    strcpy(temp, string);
    return temp;
}//end func

/**
 * compare func for comapring
 * @param a for the first item to compare
 * @param b for the second item to compare
 * @return an int
 */
int compare(const void* a, const void* b){
    //decalre var
    int number = strcmp((char*)a,(char*)b);
    //check what it should return
    return number;
}//end if

/**
 * delete function for deleting the data
 * @param data
 */
void delete(void* data){
   //does nothing for now
}//end if

/**
 * funtion for printing the data 
 * @param data
 */
void print(void* data){
    printf("%s ", (char*)data);
}//end if

/**
 * print traversal
 * @param root of the tree
 * @param print type
 */
void printTraversal(TreeNode* root, int printType, PrintFunc printFunc) {
    
    //pre order print
    if(printType == PRE_ORDER){
        if(root != NULL) {
            printFunc(root->data);
            printTraversal(root->left, printType, printFunc);
            printTraversal(root->right, printType, printFunc);
        }//end if
    }//end if

    //in in order print
    if(printType == IN_ORDER){
        if(root != NULL) {
            printTraversal(root->left, printType, printFunc);
            printFunc(root->data);         
            printTraversal(root->right, printType, printFunc);
        }//end if
    }//end if

    if(printType == POST_ORDER){
        if(root != NULL) {
            printTraversal(root->left, printType, printFunc);
            printTraversal(root->right, printType, printFunc);
            printFunc(root->data);
        }//end if 
    }//end if
}//end func

/**
 * search the node that match the data
 * @param root of the data
 * @param data that is going to be searched
 * @return node to be search
 */
TreeNode* searchNode(TreeNode* root, TreeDataPtr data, CompareFunc compare){
    //set the root to current node
    TreeNode* currentNode = root;

    //if the root is null of the data being search is on the root, get it
    if (currentNode == NULL){
       return NULL;
    }else if (compare(currentNode->data, data) == 0){
        //if its the one being searhed
        return currentNode;
    }else if (compare(currentNode->data, data) < 0 ){
        //searh the right
        currentNode = searchNode(currentNode->right, data, compare);
        return currentNode;
    }if(compare(currentNode->data, data) > 0 ){
        //search to the left
        currentNode = searchNode(currentNode->left, data, compare);
        return currentNode;
    }else{
        return NULL;
    }//end if
}//end if

/**
 * delete 
 * @param the binary tree to be deleted
 */
void deleteTree(TreeNode* nodeToBeDeleted){
    //check if the root is NULL
    if(nodeToBeDeleted == NULL){
        return;
    }//end if

    //delete the left of the tree
    deleteTree(nodeToBeDeleted->left);
    //delete the right of  the tree
    deleteTree(nodeToBeDeleted->right);
     
    //delete the node
    //if(DEBUG){printf("Deleting Node : %s\n", (char*)nodeToBeDeleted->data);}
    free(nodeToBeDeleted);
    
    //stop the recusion
    return;
}//end if

/**
 * delete the node that is being search for
 * @param root which is the current node
 * @param data for the data to be delete
 * @return
 */
TreeNode* deleteTraversal(TreeNode *root, TreeDataPtr data, CompareFunc compare) {
    //set the root to the current node
    TreeNode* currentNode = root;

    //check if the search is null
    if (currentNode == NULL) {
        return currentNode;
    }//end if

    if (compare(data, currentNode->data) < 0) {  
        //the data is in the left of sub tree
        currentNode->left = deleteTraversal(currentNode->left, data, compare);
    } else if (compare(data, currentNode->data) > 0) { 
        //the data is in the right of sub tree
        currentNode->right = deleteTraversal(currentNode->right, data, compare);
    } else {

        //check through the children
        if (currentNode->left == NULL) {
            //if there is only one child to the right
            TreeNode *temp = currentNode->right;
            free(currentNode);
            return temp;
        } else if (currentNode->right == NULL) {
            //if there is only one child to the left
            TreeNode *temp = currentNode->left;
            free(currentNode);
            return temp;
        }//end if

        //if two children
        TreeNode *temp = findMinimum(currentNode->right);
        currentNode->data = temp->data; 
        currentNode->right = deleteTraversal(currentNode->right, temp->data, compare);
    }//end if

    // update the currentNode
    return currentNode; 
}//end if

/**
 * find the minium
 * @param the current node of the tree
 * @return the next mininum node
 */
TreeNode* findMinimum(TreeNode *root) {
    //check if root is null
    if (root == NULL) {
        return NULL;
    }//end if

    //check if left child is null
    if (root->left != NULL) {
         //then left tree is smaller so return it
        return findMinimum(root->left);
    }//end if

    //if not then return this root
    return root;
}//end if