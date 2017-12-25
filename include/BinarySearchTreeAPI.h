/**************************************
 * Name: Vicky Mohammad
 * ID: 0895381
**************************************/

#ifndef BST_GUARD
#define BST_GUARD

//define macros
#define TRUE 1
#define FALSE 0
#define PRE_ORDER 1
#define IN_ORDER 2
#define POST_ORDER 3
#define DEBUG 0
#define SEARCH 1
#define DELETE 0

/**
 * Function pointer tyepdefs
 */
typedef int (*CompareFunc)(const void* a, const void* b);
typedef void (*DeleteFunc)(void* data);
typedef void (*PrintFunc)(void* data);

/*
 * Typedef the void* to make the API cleaner and more readable.
 */
typedef void* TreeDataPtr;

/*
 * A Single Binary Tree Node.
 * Left and Right branches
 * void* data
 */
typedef struct binTreeNode TreeNode;
struct binTreeNode{
	TreeDataPtr data;
	TreeNode * left;
	TreeNode * right;
	//TreeNode * parent; Optional but useful
    //Tree* parentTree;  Optional but gets you access to function pointers.
};

/**
 * This is the definition of the Binary Tree.
 *
 */
typedef struct binTree
{
	TreeNode *root;
	CompareFunc compareFunc;
	DeleteFunc deleteFunc;

	// Additions must work with abstract data types.
	// Additional function pointers to generalize tree.
	// Additional properties can be added such as count.
} Tree;

/**
 * Creates a TreeNode. TreeNode children are set to NULL and data is set to the passed in data.
 * @param data - the data to be stored within the Node. 
 * @return Newly created TreeNode
 *
 */
TreeNode* createTreeNode(TreeDataPtr data);

/**
 * createBinTree allocates memory for Tree and assigned function pointers
 * @param  compare [Function pointer to Compare data in tree nodes]
 * @param  del     [Function pointer to delete data from node]
 * @return Newly created Tree
 */
Tree * createBinTree(CompareFunc compare, DeleteFunc del);

/**
 * destroyBinTree - remove all items and free memory
 * @param  toDestroy - the tree
 * @return
 */
void  destroyBinTree(Tree * toDestroy);

/**
 * Add data to a tree
 * @param theTree 
 * @param data    
 */
void addToTree(Tree * theTree, TreeDataPtr data);

/**
 * Remove data from the tree
 * @param theTree 
 * @param data    
 */
void removeFromTree(Tree * theTree, TreeDataPtr data);

/**
 * This function searches the tree for the target data
 * @param  theTree 
 * @param  data    
 * @return         NULL if fail, otherwise return data
 */
TreeDataPtr findInTree( Tree* theTree, TreeDataPtr data );

/**
 * Get data from the root of the Tree if it exists.
 * @param  theTree 
 * @return NULL if tree is empty, otherwise return root
 */
TreeDataPtr getRootData(Tree * theTree);

/**
 * [printInOrder This function prints the tree using an inOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printInOrder(Tree * theTree, PrintFunc printData);

/**
 * [printPreOrder This function prints the tree using an preOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printPreOrder(Tree * theTree, PrintFunc printData);

/**
 * [printPostOrder This function prints the tree using an postOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printPostOrder(Tree * theTree, PrintFunc printData);

/**
 * Checks if a tree is empty
 * @param  theTee [description]
 * @return        0 if false, 1 otherwise
 */
int isTreeEmpty(Tree* theTree);

/**
 * Helper function for checking if a single node is a leaf (no children)
 * @param  treeNode [description]
 * @return          0 if false, 1 otherwise
 */
int isLeaf( TreeNode * treeNode);

/**
 * Helper funciton for checking if a single node has two children.
 * @param  treeNode [description]
 * @return         0 if false, 1 otherwise
 */
int hasTwoChildren( TreeNode *treeNode);

/**
 * Helper funciton Get the height of a particulat Node in the tree. 
 * @param  treeNode [description]
 * @return    (1-Based) heigh for the tree. 
 */
int getHeight( TreeNode* treeNode );

/**************************************************************************************************
 * You may add additional API functions below this comment if you want to extend the funcitonality.
 *************************************************************************************************/

/**
 * add a string to any ptr
 * @param string for the string to add
 * @return char* of the string
 */
char* addString(const char* string);

/**
 * compare func for comapring
 * @param a for the first item to compare
 * @param b for the second item to compare
 * @return an int
 */
int compare(const void* a, const void* b);

/**
 * delete function for deleting the data
 * @param data
 */
void delete(void* data);

/**
 * funtion for printing the data 
 * @param data
 */
void print(void* data);

/**
 * print traversal
 * @param root of the tree
 * @param print type
 */
void printTraversal(TreeNode* root, int printType, PrintFunc printFunc) ;

/**
 * delete 
 * @param the binary tree to be deleted
 */
void deleteTree(TreeNode* nodeToBeDeleted);

/**
 * search the node that match the data
 * @param root of the data
 * @param data that is going to be searched
 * @return node to be search
 */
TreeNode* searchNode(TreeNode* root, TreeDataPtr data, CompareFunc compare);

/**
 * find the minium
 * @param the current node of the tree
 * @return the next mininum node
 */
TreeNode* findMinimum(TreeNode *root);

/**
 * delete the node that is being search for
 * @param root which is the current node
 * @param data for the data to be delete
 * @return
 */
TreeNode* deleteTraversal(TreeNode *root, TreeDataPtr data, CompareFunc compare);

#endif