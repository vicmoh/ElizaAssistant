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
#include <ctype.h>
#include "BinarySearchTreeAPI.h"
#include "Eliza.h"


/**
 *change to lower case
 *@param string for the string to change to lowercaser
 */
char * lowerCase(char * string){
    for(int x=0; x <strlen(string);x++){
        string[x] = tolower(string[x]);
    }//end if
    return string;
}//end func 

/**
 * get the user input and convert it to int
 * @param the string for new user input
 * @return the int
 */
int userInputToInt(char* input){
    //declare var
    int num;
    //ask for user input
    input[0] = '\0';
    fgets(input, 99, stdin);
    input[strlen(input)-1] = '\0';
    num = atoi(input);
    //return
    return num;
}//end func

/**
 * get the user input and convert it to double
 * @param the string for new user input
 * @return the double
 */
double userInputToDouble(char* input){
    //declare var
    double num;
    //ask for user input
    input[0] = '\0';
    fgets(input, 99, stdin);
    input[strlen(input)-1] = '\0';
    num = atof(input);
    //return
    return num;
}//end func

/**
 * a function to get the user input
 * @param the string for new user input
 * @return the string
 */
char* userInput(char* input){
    input = malloc(sizeof(char*)*99);
    //ask for user input
    input[0] = '\0';
    fgets(input, 99, stdin);
    if(input[0] == '\n'){  
        input[1] = '\0';
    }else{
        input[strlen(input)-1] = '\0';
    }//end if
    //return
    return input;
}//end func

/**
 * function to check the validity for error checking
 * @param string to be checked
 * @return true or false (1 or 0)
 */
int checkValidity(char* string){
    //go through the string
    for(int x=0; x<strlen(string); x++){
        if(string[0] == '\n'){
            return TRUE;
        }else if(string[x] == ' '){
            return TRUE;
        }//end if
    }//end if
    //else return false
    return FALSE;
}//end if

/**
 * copy function to copy to a new string
 * @param string
 * @return the string
 */
char* copy(char* string){
    char* newString = malloc(sizeof(char*)*99);
    strcpy(newString, string);
    return newString;
}//end if

/**
 * main program
 * @param argc for the number of commad string
 * @param argv for the string of the array
 */
int main( int argc, char **argv){
    /*declare var for file*/
    char const* const fileName = argv[1];
    FILE* filePointer = fopen(fileName, "r");
    int numOfLine = 0;
    char line[150];
    //char tempArray[200][200];
    //declare var
    char userString[99];
    int menu;
    //create the binary tree
    Tree* binaryTree = createBinTree(compareKeyword, delete);

    /*if file doesnt exist*/
    if(filePointer == NULL) {
        printf("No such file\n");
        return 0;
    }/*end if*/
    
    printf("Loading keywords...\n");
    /*scan until end of file*/
    while (fgets(line, sizeof(line), filePointer)!=NULL) {
        line[strcspn(line, "\r\n")] = 0;
        //display what the file reads
        printf("%s \n", line);
        //read first line
        char* readKey = copy(line);
        readKey = lowerCase(readKey);
        numOfLine = numOfLine + 1;
        //read the second line
        fgets(line, sizeof(line), filePointer);    
        char* readPhrase = copy(line);
        //added to the tree
        Eliza* readData = createAI(readKey, readPhrase, 0.5);
        addToTree(binaryTree, readData);
        //go to the next
        numOfLine = numOfLine + 1;   
    }//end loop
    printf("Keywords loaded...\n\n");
    fclose(filePointer);
    
    //loop till user exit
    do{
        //print the options
        printf("1) Add a new rule\n");
        printf("2) Remove a rule\n");
        printf("3) Display rules\n");
        printf("4) Modify rule rating\n");
        printf("5) Discuss\n");
        printf("9) Quit\n");
        printf("Enter valid options: \n");

        //ask the user
        menu = userInputToInt(userString);

        //check the options
        if(menu == 1){
            //declare var
            int noSpace = TRUE;
            char* keyword;
            char* phrase;
            char* buffer = malloc(sizeof(buffer)*99);
            double userRating = -99;

            //ask for the keyword
            do{
                noSpace = TRUE;
                //ask the user for the keyword
                printf("Enter a keyword: \n");
                keyword = userInput(keyword);
                keyword = lowerCase(keyword);
                //check if there is space
                noSpace = checkValidity(keyword);
                if(noSpace == TRUE){
                    printf("keyword cannot be blank or has a space, please re-enter.\n");
                }//end if
            }while(noSpace == TRUE);

            Eliza* elizaSearched = createAI(keyword, "", 0);
            //searching
            TreeDataPtr searched = findInTree(binaryTree, (void*)elizaSearched);//seg fault
             //if exist remove, if not print
            if(searched != NULL){
                printf("Keyword alread exist.\n");
            }else{
                //ask for the phrase
                do{
                    printf("Enter the phrase: \n");
                    phrase = userInput(phrase);
                    if(phrase[0] == '\n'){
                        printf("Phrase cannot be blank, please re-enter.\n");
                    }
                }while(phrase[0] == '\n');

                //enter the rate
                do{
                    userRating = -99;
                    //ask the user
                    printf("Enter the rating from 0 to 1: \n");
                    userRating = userInputToDouble(buffer);
                    //validity check
                    if((userRating < 0) || (userRating > 1)){
                        printf("Please enter the valid rating.\n");
                    }//end if
                }while((userRating < 0) || (userRating > 1));
                
                //add to the tree
                Eliza* rule = createAI(keyword, phrase, userRating);
                printf("Keyword '%s', phrase '%s', and user rating '%0.2f' has been added.\n", keyword, phrase, userRating);
                addToTree(binaryTree, rule);
            }//end if for key word exist

        }else if(menu == 2){
            //declare var
            int noSpace;
            char* keywordSearch;
            TreeDataPtr searched;

            //ask for the keyword
            do{
                noSpace = TRUE;
                //ask the user for the keyword
                printf("Enter a keyword: \n");
                keywordSearch = userInput(keywordSearch);
                keywordSearch = lowerCase(keywordSearch);
                //check if there is space
                noSpace = checkValidity(keywordSearch);
                if(noSpace == TRUE){
                    printf("keyword cannot be blank or has a space, please re-enter.\n");
                }//end if
            }while(noSpace == TRUE);

            //create eliza for searching
            Eliza* elizaSearched = createAI(keywordSearch, "", 0);
            //searching
            printf("Searching '%s'.\n", keywordSearch);
            searched = findInTree(binaryTree, (void*)elizaSearched);//seg fault
             //if exist remove, if not print
            if(searched == NULL){
                printf("Keyword not found.\n");
            }else{
                printf("Removing '%s'.\n", getKeyword(searched));
                removeFromTree(binaryTree, (void*)elizaSearched);
            }//end if
            
        }else if(menu == 3){
            printf("Printing in alphabetic order...\n");
            printInOrder(binaryTree, printEliza);
        }else if(menu == 4){
            //declare var
            int noSpace;
            char* keywordSearch;
            Eliza* searched = malloc(sizeof(searched));

            //ask for the keyword
            do{
                noSpace = TRUE;
                //ask the user for the keyword
                printf("Enter a keyword: \n");
                keywordSearch = userInput(keywordSearch);
                keywordSearch = lowerCase(keywordSearch);
                //check if there is space
                noSpace = checkValidity(keywordSearch);
                if(noSpace == TRUE){
                    printf("keyword cannot be blank or has a space, please re-enter.\n");
                }//end if
            }while(noSpace == TRUE);

            //create eliza to be searched
            Eliza* elizaSearched = createAI(keywordSearch, "", 0);

            //searching
            printf("Searching '%s'.\n", keywordSearch);
            searched = findInTree(binaryTree, (void*)elizaSearched);//seg fault
             //if exist remove, if not print
            if(searched == NULL){
                printf("Keyword not found.\n");
            }else{
                //print
                printf("Found '%s' with user rating %0.2f.\n", getKeyword(searched), getUserRating(searched) );

                //declare var for the keyword
                char* buffer = malloc(sizeof(buffer)*99);
                double userRating = -99;
                //edit the user rating
                do{
                    userRating = -99;
                    //ask the user
                    printf("Enter the rating from 0 to 1: \n");
                    userRating = userInputToDouble(buffer);
                    //validity check
                    if((userRating < 0) || (userRating > 1)){
                        printf("Please enter the valid rating.\n");
                    }//end if
                }while((userRating < 0) || (userRating > 1));

                //set the user new rating
                setUserRating(searched, userRating);
                printf("The keyword '%s' rating has been set to '%0.2f'.\n", getKeyword(searched), getUserRating(searched) );

            }//end if            
        }else if(menu == 5){
            //create var
            char* phrase;
            
            //ask ELIZA
            do{
                printf("Ask any question: \n");
                phrase = userInput(phrase);
                phrase = lowerCase(phrase);
                if(phrase[0] == '\n'){
                    printf("Phrase cannot be blank, please re-enter.\n");
                }//end if
            }while(phrase[0] == '\n');

            //count how many words in the sentences 
            int numberOfSpace = 1;
            for(int x=0; x < strlen(phrase); x++){
                if( (phrase[x] != ' ') && (phrase[x+1] == ' ' || phrase[x+1] == '\n' || phrase[x+1] == '\0' )){
                    numberOfSpace = numberOfSpace + 1;
                }//end if
            }//end for
            //create an array best of number words
            char stringArray[numberOfSpace][99];

            //tokenize through thw code
            char *token;
            int iterate = 0;
            token = strtok(phrase, " ,.?!&:;");
            int found = FALSE;
            //print the list of word in split
            Eliza* highestPriority = malloc(sizeof(Eliza));

            //iterate through the tokem
            while( token != NULL ) {
                //word
                strcpy(stringArray[iterate], token);
                iterate++;
                //keep going
                token = strtok(NULL, "  ,.?!&:;");
            }//end if
            
            //check for the highest one
            for(int x=0; x<iterate; x++){
                //check the if there is that word
                Eliza* searchEliza = createAI(stringArray[x], "", 0);
                searchEliza = findInTree(binaryTree, (void*)searchEliza);
                //check which one is higher
                if(searchEliza != NULL){
                    if(getPriority(searchEliza) > getPriority(highestPriority) ){
                        highestPriority = searchEliza;
                        found = TRUE;
                    }//end if
                }//end if
            }//end for

            //ask if it was helpful for the rating
            int exit = FALSE;
            char* yesOrNo;

            if(found == FALSE){
                printf("Personal Assistant: Sorry could not help you at the moment.\n");
            }else{
                printf("%s\n", getPhrase(highestPriority) );
                //ask if it was helpful for the rating
                do{
                    printf("Personal Assistant: Was this feedback was helpful ‘y’ or ‘n’:\n");
                    yesOrNo = userInput(yesOrNo);
                    yesOrNo = lowerCase(yesOrNo);
                    if(strcmp(yesOrNo, "y") == 0 || strcmp(yesOrNo, "n") == 0){
                        exit = TRUE;
                    }else{
                        printf("Plese re-enter with 'y' or 'n'.\n");
                    }//end if
                }while(exit == FALSE);

                //ste the tiime
                addTotalTimesUsed(highestPriority);
                updateRating(highestPriority, yesOrNo[0]);

            }//end if
        }//end if
    }while(menu != 9);
    //exit the program
    destroyBinTree(binaryTree);
    return 0;
}/*end main*/ 