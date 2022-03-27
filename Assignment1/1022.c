/*
 * Time : 14/02/2022 16:42
 * Student Name : Jiashun Lu
 * Email : psjlu17@liverpool.ac.uk
 * 
 * User : psjlu17
 * 
 * Problem ID : 1022
 * RunID : 43404
 * Result : Accepted
 */

#include <stdio.h>

int main(void) {
    char letter;
    int english_characters = 0, digits = 0, spaces = 0, other_characters = 0;
    // Read character from getchar and assign them to letters, when the end-of-file character is read, exit the while loop
    while ((letter = getchar()) != EOF) {
        /*
         * When the ASCII code of the character read is greater than or equal to a and A and less than or equal to z and Z
         * Meaning there is an english character
         */
        if (letter >= 'a' && letter <= 'z' || letter >= 'A' && letter <= 'Z') {
            english_characters++;
        }
        /*
         * When the ASCII code of the character read is equal to a space
         * Meaning there is a space
         */
        else if (letter == ' ') {
            spaces++;
        }
        /*
         * When the ASCII code of the character read is greater than or equal to the number 0 and less than or equal to the number 9
         * Meaning there is a digit
         */
        else if (letter >= '0' && letter <= '9') {
            digits++;
        }
        // If it is not one of the above, it means it is another character
        else {
            other_characters++;
        }
    }
    printf("%d %d %d %d", english_characters, digits, spaces, other_characters);
    return 0;
}
