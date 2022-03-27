/*
 * Time : 28/02/2022 15:21
 * Student Name : Jiashun Lu
 * Email : psjlu17@liverpool.ac.uk
 * 
 * User : psjlu17
 * 
 * Problem ID : 1086
 * RunID : 51358
 * Result : Accepted
 */

#include <stdio.h>


/*
 * The purpose of this function is to compress string
 * This function has no return value
 */
void compress_string() {
    /*
     * The variable first_character represents the first character read, the variable second_character represents the second character read
     * The variable count represents the number of times the current character has been repeated
     */
    char first_character, second_character;
    int count;
    // Nested while loop, reading in one character at a time, exit loop if EOF is read
    while (scanf("%c", &first_character) != EOF) {
        count = 1;
        while (scanf("%c", &second_character) != EOF) {
            if (first_character == second_character) {
                count++;
            } else {
                /*
                 * When count is greater than or equal to 2, output in the compressed format and reset count, otherwise output the original characters directly
                 * And assign the second character to the first, continue reading the next character and compare it with the first character
                 */
                if (count >= 2) {
                    printf("%c%c%d*", first_character, first_character, count);
                    first_character = second_character;
                    // Reset the count value at the end of each print
                    count = 1;
                } else {
                    printf("%c", first_character);
                    first_character = second_character;
                    count = 1;
                }
            }
        }
        //The last character, there is no latter to compare, so write a separate output statement
        if (count >= 2) {
            printf("%c%c%d*", first_character, first_character, count);
        } else {
            printf("%c", first_character);
        }
    }
}

/*
 * The purpose of this function is to expand string
 * This function has no return value
 */
void expand_string() {
    /*
     * The variable first_character represents the first character read, the variable second_character represents the second character read
     * The variable repeated_character represents the character that will be repeated, the digital_character represents the number read as a character
     * digital_character starts with a numeric character after the second character if the first and second characters are equal
     * Flag = 1 represents the case where digital_character is not * if the first_character and second_character are equal, if not this case,Flag = 0
     */
    char first_character, second_character, repeated_character, digital_character, flag = 0;
    // loop_times represents the number of times the repeating character is to be printed, and is obtained by converting the digital_character to a number
    int loop_times = 0;
    // Nested while loop, reading in one character at a time
    while (scanf("%c", &first_character) != EOF) {
        while (scanf("%c", &second_character) != EOF) {
            // On each re-loop, set digital_character to a number that is not * so that programme can enter the following while loop
            digital_character = 1;
            if (first_character != second_character) {
                // If the previous character has been compressed, start a loop again
                if (flag == 1) {
                    first_character = second_character;
                    flag = 0;
                }
                    // If the previous character has not been compressed, means that the current one is a single character and print first_character
                else {
                    printf("%c", first_character);
                    first_character = second_character;
                    flag = 0;
                }
            } else {
                repeated_character = first_character;
                // When the first_character and second_character are the same, read the number that follow it until read * and stop loop
                while (digital_character != '*') {
                    scanf("%c", &digital_character);
                    // Make sure that the digital_character currently being read is not *
                    if (digital_character != '*') {
                        // Determine if this is the first time the loop has been entered
                        if (loop_times == 0) {
                            // Converting character types of numbers to int types
                            loop_times = ((int) digital_character) - 48;
                        }
                            // If it is not the first to enter the loop, expand it by a factor of 10 and add the new number
                        else {
                            loop_times = loop_times * 10;
                            loop_times = ((int) digital_character) - 48 + loop_times;
                        }
                    }
                        // If the * is read, print out the previous repeated_character and reset loop_times
                    else {
                        for (int i = 0; i < loop_times; i++) {
                            printf("%c", repeated_character);
                        }
                        loop_times = 0;
                    }
                    // When finished printing a compressed string, set flag to 1
                    flag = 1;
                    // If the EOF is read, exit the loop
                    if (digital_character == EOF) {
                        break;
                    }
                }
            }
        }
    }
}

int main(void) {
    char letter;
    // Get the first character by getchar, compress the string if it is C or c, expand it if it is E or e
    switch (letter = getchar()) {
        case 'c':
        case 'C':
            // Use the getchar() function to clear the cache after the first character
            getchar();
            compress_string();
            break;
        case 'e':
        case 'E':
            getchar();
            expand_string();
            break;
        default:
            printf("Error");
    }
    return 0;
}
