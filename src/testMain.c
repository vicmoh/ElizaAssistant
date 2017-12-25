/**************************************
 * Name: Vicky Mohammad
 * ID: 0895381
**************************************/

/*import library*/
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>
#include "BinarySearchTreeAPI.h"

/**
 *program for testing
 */
int main( int argc, char **argv){
    printf("\nTesting the binary tree.\n");
    Tree* tree = createBinTree(compare, delete);
    printf("Creating the binary tree seems to be working.\n");

    TreeDataPtr data1 = addString("one");
    TreeDataPtr data2 = addString("two");
    TreeDataPtr data3 = addString("three");
    TreeDataPtr data4 = addString("four");

    printf("\nTesting to add some stuff on the binary tree.\n");
    addToTree(tree, data1);
    addToTree(tree, data2);
    addToTree(tree, data3);
    addToTree(tree, data4);
    printf("Aswell as the three print function.\n");
    printPostOrder(tree, print);
    printf("\n");
    printInOrder(tree, print);
    printf("\n");
    printPreOrder(tree, print);
    printf("\nAll string number from one to four should work.\n\n");

    printf("Testing the delete function. Deleting 'one' and 'two'.\n");
    removeFromTree(tree, "one");
    removeFromTree(tree, "two");
    printPostOrder(tree, print);
    printf("\nThere should be only 'three' and 'four'.\n\n");
    
    printf("Add two more word: 'one' and 'two'.\n");
    addToTree(tree, "one");
    addToTree(tree, "two");
    printf("Testing the search function, searching 'two' and 'three'.\n");
    TreeDataPtr search1 = findInTree(tree, "two");
    TreeDataPtr search2 = findInTree(tree, "three");
    printf("%s\n", ((char*)search1));
    printf("%s\n", ((char*)search2));

    printf("Test if the destroy, if it doesnt seg fault, then it is probably a pass\n");
    destroyBinTree(tree);
    printf("\n");

}/*end main*/ 