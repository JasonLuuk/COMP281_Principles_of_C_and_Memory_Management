/*
 * Time : 01/03/2022 01:29
 * Student Name : Jiashun Lu
 * Email : psjlu17@liverpool.ac.uk
 *
 * User : psjlu17
 *
 * Problem ID : 1090
 * RunID : 52959
 * Result : Accepted
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Define a constant named MAX_WORD_IN_TEXT with a value of 300
#define MAX_WORD_IN_TEXT 300
// Define a constant named MAX_CHARACTERS with a value of 31 because the last digit of the string is '\0'
#define MAX_CHARACTERS 31
// Define a structure and give this type the name words_struct
typedef struct words_struct {
    char word[MAX_CHARACTERS];
    int count;

} words_struct;

/*
* The purpose of this function is convert all letters of a string to lower case
* This function will return an all lowercase string
*/
char string_to_lowercase(char *string) {
    char *ptr = string;
    // When the defined string pointer exists, turn the character corresponding to the address of the current pointer into lower case and +1 to the current address
    while (*ptr) {
        *ptr = tolower(*ptr);
        ptr++;
    }
    return string;
}

/*
 * The purpose of this function is Sorting words in alphabetical order
 * This function takes a pointer to a structure and an index, and has no return value, the index representing how many unique words there are
 */
void sort_by_alphabet(words_struct *words, int index) {
    /*
     * Define variables i and j for bubble sorting, representing the values of the subscripts of the previous and the next in the array of structures
     * Define variables temp_word_count and temp_word_len as intermediate variables to store the values to be swapped in the bubble sort
     */
    int i, j, temp_word_count, temp_word_len;
    // Perform a bubble sort, compare the size of the first word with the second, if it is greater than 0, then the first word is greater than the second word and swap positions
    for (i = 0; i < index - 1; i++) {
        for (j = i + 1; j < index; j++) {
            if (strcmp(words[i].word, words[j].word) > 0) {
                temp_word_count = words[i].count;
                words[i].count = words[j].count;
                words[j].count = temp_word_count;
                // When swapping values, not only the count but also the corresponding word is swapped, so first get the word length of the array of structures to be swapped
                temp_word_len = strlen(words[i].word);
                // Define an array of characters to hold the strings to be exchanged
                char temp_word[temp_word_len];
                strcpy(temp_word, words[i].word);
                strcpy(words[i].word, words[j].word);
                strcpy(words[j].word, temp_word);
            }
        }
    }
}


int main(void) {
    char word[MAX_CHARACTERS];
    /*
     * The variable i represents the variable that controls the number of loops in the next loop,
     * The variable len_of_word represents the length of the current word, and index represents how many identical words there are.
     */
    int i, len_of_word, index = 0;
    // Allocate the required memory space to the structure and return a pointer to it
    words_struct *words = (words_struct *) calloc( MAX_WORD_IN_TEXT, sizeof *words);
    // Checking for allocation failures
    if (words == NULL) {
        printf("Error. Not enough space available");
        exit(1);
    }
    // Loop read the words one at a time until reach the end of the text
    while (scanf("%s", &word) != EOF) {
        // Define is_unique to mean whether the word is unique or not, 1 means unique, not 1 means not unique, each default occurrence of the word is unique
        int is_unique = 1;
        len_of_word = strlen(word);
        // A while loop determines if the last digit of the current word is a punctuation mark, removes it if it is, and decrements the word length by one
        while (len_of_word && ispunct(word[len_of_word - 1])) {
            word[--len_of_word] = 0;
        }
        /*
         * The variable k is defined to represent the first character in the word, and by means of a while loop, when the kth bit is a character
         * The k th character is skipped and the remaining two parts of the word are put together by defining the variable t
         */
        for (int k = 0; k < len_of_word - 1; ++k) {
            while (ispunct(word[k])) {
                for (int t = k; t < len_of_word; ++t) {
                    word[t] = word[t + 1];
                }
            }
        }
        // Call the function to make words all lowercase
        string_to_lowercase(word);
        // Index is the number of words, strcmp compares the size of characters, when the result is equal to 0 it means equal, so the word is not unique
        for (i = 0; i < index; i++) {
            if (strcmp(words[i].word, word) == 0) {
                is_unique = 0;
                words[i].count++;
                break;
            }
        }
        // If the word is unique, copy this single time into words and increase the count as well as the index
        if (is_unique) {
            strcpy(words[index].word, word);
            words[index++].count++;
        }
    }
    // Reordering by alphabetical order
    sort_by_alphabet(words, index);
    // Print out each result in format through a for loop
    for (i = 0; i < index; i++) {
        printf("%s => %d\n", words[i].word, words[i].count);
    }
    // Release memory
    free(words);
    return 0;
}