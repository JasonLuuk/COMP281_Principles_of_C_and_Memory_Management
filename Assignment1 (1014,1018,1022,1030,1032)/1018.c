/*
 * Time : 14/02/2022 16:09
 * Student Name : Jiashun Lu
 * Email : psjlu17@liverpool.ac.uk
 * 
 * User : psjlu17
 * 
 * Problem ID : 1018
 * RunID : 43399
 * Result : Accepted
 */

#include<stdio.h>

/*
 * The purpose of this function is to invert the string by recursively calling itself
 * The function will not start printing characters until the end-of-file character is read
 * So that the string is output in reverse
 */
void reverse_string(void) {
    char letter;
    // Reading data via scanf, when the end-of-file character is read, Skip the following statements
    if (scanf("%c", &letter) != EOF) {
        // Calling the function itself
        reverse_string();
        printf("%c", letter);
    }
}

int main(void) {
    reverse_string();
    return 0;
}