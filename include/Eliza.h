/**************************************
 * Name: Vicky Mohammad
 * ID: 0895381
**************************************/

#ifndef ELIZA_H
#define ELIZA_H

/*
 * struct for the AI
 */
typedef struct elizasPhrase{
	char* keyword;
    char* phrase;
    double userRating;
    double systemRating;
    int totalTimesUsed;
    double priority;
} Eliza;

/**
 * create a rule for the ai
 * @param keyword for the ai
 * @param phrase for the ai
 * @param userRating for the ai
 * @return Eliza the object of the new rule
 */
Eliza* createAI(char* keyword, char* phrase, double userRating);

/**
 * get the priority
 * @param Eliza for the object to get the priority
 * @return the priority
 */
double getPriority(Eliza* eliza);

/**
 * get the keyword
 * @param Eliza
 * @return ketword
 */
char* getKeyword(Eliza* eliza);

/**
 * get the phrase
 * @param eliza
 * @return the phrase
 */
char* getPhrase(Eliza* eliza);

/**
 * get the user rating
 * @param Eliza
 * @return the user rating
 * */
double getUserRating(Eliza* eliza);

/**
 * @get the system rating
 * @param eliza
 * @sreturn the system rating
 */
double getSystemRating(Eliza* eliza);

/**
 * get totat times it has been used
 * @param eliza
 * @return the total times used
 */
int getTotalTimesUsed(Eliza* eliza);

/**
 * print eliza which is meant for option 4
 * @param eliza
 */
void printEliza(void * eliza);

/**
 * a compare function for be able to compare the keyword
 * @param a is the first string to be compare
 * @param b is the second string to be comapare
 */
int compareKeyword(const void* a, const void* b);

/**
 * set the user rating
 * @oaram eliza
 * @param newRating
 */
void setUserRating(Eliza *eliza, double newRating);

/**
 * calulate the rating for eliza
 * @param eliza
 */
void caluculateRating(Eliza *eliza);

/**
 * add the total times used
 * @param eliza
 */
void addTotalTimesUsed(Eliza *eliza);

/*
 * update the total times used
 * @param eliza
 * @param choice of either a char or 'y' or 'n'
 */
void updateRating(Eliza * eliza, char choice);

#endif