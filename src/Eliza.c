/**************************************
 * Name: Vicky Mohammad
 * ID: 0895381
**************************************/

//import the header of this class
#include "BinarySearchTreeAPI.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Eliza.h"

//create a costructor for eliza
Eliza* createAI(char* keyword, char* phrase, double userRating){
    Eliza* newEliza = malloc(sizeof(Eliza));
    newEliza->keyword = keyword;
    newEliza->phrase = phrase;
    newEliza->userRating = userRating;
    newEliza->systemRating = 0.5;
    newEliza->totalTimesUsed = 0;
    newEliza->priority = 0;
    return newEliza;
}//end construcctor

double getPriority(Eliza* eliza){
    double total;
    total = eliza->userRating + eliza->systemRating;
    return total;
}//end if

char* getKeyword(Eliza* eliza){
    return eliza->keyword;
}//end func

char* getPhrase(Eliza* eliza){
    return eliza->phrase;
}//end func

double getUserRating(Eliza* eliza){
    return eliza->userRating;
}//end func

double getSystemRating(Eliza* eliza){
    return eliza->systemRating;
}//end func

int getTotalTimesUsed(Eliza* eliza){
    return eliza->totalTimesUsed;
}//end func

void updateRating(Eliza * eliza, char choice){
    if(choice == 'y'){
        eliza->systemRating = eliza->systemRating + (eliza->systemRating*0.05/eliza->totalTimesUsed);
    }else if(choice == 'n'){
        eliza->systemRating = eliza->systemRating - (eliza->systemRating*0.05/eliza->totalTimesUsed);
    }//end if
}//end if

int compareKeyword(const void* a, const void* b){
    int num = strcmp(getKeyword((Eliza*)a) , getKeyword((Eliza*)b));
    return num;
}//end if

void setUserRating(Eliza *eliza, double newRating){
    eliza->userRating = newRating;
}//end if

void caluculateRating(Eliza *eliza){
    //caluclate the system rating
    eliza->systemRating = eliza->systemRating + 1;
}//end if

void addTotalTimesUsed(Eliza *eliza){
    eliza->totalTimesUsed = eliza->totalTimesUsed + 1;
}//end if

void printEliza(void * eliza){
    printf("%s Rating: %0.2f System: %0.2f Occurences: %d\n", getKeyword(eliza), getUserRating(eliza), getSystemRating(eliza), getTotalTimesUsed(eliza));
}//end if