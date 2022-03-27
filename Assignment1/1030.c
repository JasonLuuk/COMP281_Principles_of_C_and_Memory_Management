/*
 * Time : 14/02/2022 23:26
 * Student Name : Jiashun Lu
 * Email : psjlu17@liverpool.ac.uk
 * 
 * User : psjlu17
 * 
 * Problem ID : 1030
 * RunID : 43412
 * Result : Accepted
 */
#include<stdio.h>

int main(void) {
    // n_th_digital represents the n-th digit after the decimal point of dividend/divisor
    int dividend, divisor, n_th_digital, result;
    scanf("%d%d%d", &dividend, &divisor, &n_th_digital);
    /*
     * When the n_th_digital is greater than 0, n_th_digital minus one and multiply the dividend by 10
     * The first decimal is obtained by current dividend / divisor
     * Since the result is type int, the number after the decimal point is omitted
     * Taking the remainder of the result of A allows computer to continue to calculate the next digit of the original equation
     */
    while (n_th_digital > 0) {
        n_th_digital--;
        dividend *= 10;
        result = dividend / divisor;
        dividend %= divisor;
    }
    printf("%d", result);
    return 0;
}
