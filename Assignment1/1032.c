/*
 * Time : 14/02/2022 23:26
 * Student Name : Jiashun Lu
 * Email : psjlu17@liverpool.ac.uk
 *
 * User : psjlu17
 *
 * Problem ID : 1032
 * RunID : 43440
 * Result : Accepted
 */

#include<stdio.h>

/*
 * The purpose of this function is to calculate the size of a string
 * The function will accept a pointer and return size the string
 */
int calculate_string_size(char *ptr) {
    int size = 0;
    // Ends the loop when the data at the address pointed to by the pointer is the end of the string
    while (*ptr != '\0') {
        ptr++;
        size++;
    }
    return size;
}

/*
 * The purpose of this function is to calculate the number of times that a string has been used as a substring of other string
 * The function will accept two pointer and return the times
 */
int calculate_sub_string(char *parent_string, char *sub_string) {
    /*
     * Define and initialize variables
     * Variable count represents the number of occurrences,variable i represent the position of the characters in the parent_string
     * Variable j represent the position of the characters in the sub_string
     */
    int count = 0, i, j;
    /*
     * The first loop starts with the first character of the parent string and compares it with the child string one by one
     * Moving back one character if it is the same and ending the comparison if there is a character that is not the same
     * The second loop will start with the second character of the parent string, and so on
     */
    for (i = 0; i < calculate_string_size(parent_string); i++) {
        for (j = 0; j < calculate_string_size(sub_string); j++) {
            // Exit the loop if the parent string and the sub string have different characters at the current position
            if (parent_string[i + j] != sub_string[j]) {
                break;
            }
        }
        // If the value of j is equal to the length of the sub_string after exiting the loop, then the sub string exists
        if (j == calculate_string_size(sub_string)) {
            count++;
        }
    }
    return count;
}

int main(void) {
    char parent_string[52], first_sub_string[52], second_sub_string[52];
    fgets(parent_string, sizeof(parent_string), stdin);
    // Because fgets reads enter, the last character needs to be replaced with ‘\0’
    parent_string[calculate_string_size(parent_string) - 1] = '\0';
    fgets(first_sub_string, 52, stdin);
    first_sub_string[calculate_string_size(first_sub_string) - 1] = '\0';
    fgets(second_sub_string, 52, stdin);
    // If the last character is enter, replace it with ‘\0’
    if (second_sub_string[calculate_string_size(second_sub_string) - 1] == '\n') {
        second_sub_string[calculate_string_size(second_sub_string) - 1] = '\0';
    }
    // If the last character is not a enter, add a '\0' to the end of the string
    else {
        second_sub_string[calculate_string_size(second_sub_string)] = '\0';
    }
    printf("%d %d", calculate_sub_string(parent_string, first_sub_string),
           calculate_sub_string(parent_string, second_sub_string));
    return 0;
}
