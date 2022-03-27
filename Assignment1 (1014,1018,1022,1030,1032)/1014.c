/*
 * Time : 14/02/2022 15:29
 * Student Name : Jiashun Lu
 * Email : psjlu17@liverpool.ac.uk
 * 
 * User : psjlu17
 * 
 * Problem ID : 1014
 * RunID : 43388
 * Result : Accepted
 */

#include<stdio.h>

#define PI 3.14

int main(void) {
    int first_radius, second_radius;
    float circumference = 0, area = 0;
    scanf("%d%d", &first_radius, &second_radius);
    // Loop when the radius of the first input is less than or equal to the radius of the second input, otherwise exit
    while (first_radius <= second_radius) {
        // Calculate the circumference of the circle and add it to the previous calculated circumference
        circumference += PI * first_radius * first_radius;
        // Calculate the area of the circle and add it to the previously calculated area
        area += 2 * PI * first_radius;
        // After each calculation of the perimeter and area is completed, radius + 1
        ++first_radius;
    }
    // Control output format be 3 digits precision
    printf("%.3f\n%.3f", circumference, area);
    return 0;
}
