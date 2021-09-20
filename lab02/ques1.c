//Design a structure to represent complex number. Get two complex numbers and find the sum of using a function to which structure is passed as argument.
#include<stdio.h> 
struct complex_num {float real, imag;}; 
struct complex_num add(struct complex_num a, struct complex_num b){ 
    struct complex_num sum; 
    sum.real=a.real+b.real;
    sum.imag=a.imag+b.imag; 
    return sum;
} 
int main(){ 
    struct complex_num n1, n2; 
    printf("Enter a complex number (1)\nReal part: ");
    scanf("%f", &n1.real);
    printf("Imaginary part: ");
    scanf("%f", &n1.imag);
    printf("Enter a complex number (2)\nReal part: ");
    scanf("%f", &n2.real);
    printf("Imaginary part: ");
    scanf("%f", &n2.imag);
    struct complex_num sum=add(n1, n2); 
    printf("\nSum is: %f + i%f.", sum.real, sum.imag); 
} 