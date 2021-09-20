/*Design a union ‘product’ to store the details of the product purchased like product name, price 
per unit, number of quantities purchased and amount spend. Get the name. price per unit and number of 
quantities of the product purchased. Calculate the amount spend on the product and display all the details of 
the procured product. */
#define _POSIX_C_SOURCE 200112L 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
struct product{char name[10];int qty;float price,amount;}; 
int main()
{ 
    struct product lap;
    struct product *P; 
    P=&lap;
    char name[10]; 
    printf("enter product name:");
    scanf("%s",&lap.name);
    printf("Enter price:");
    scanf("%f",&lap.price);
    printf("Enter quantity: ");
    scanf("%d",&lap.qty);
    (*P).amount=(*P).qty*(*P).price; 
    setenv("TZ", "/usr/share/zoneinfo/Asia/Calcutta", 1); 
    struct tm tm = *localtime(&(time_t){time(NULL)});
    printf("\nDate:%s", asctime(&tm));
    printf("Name: %s",(*P).name);
    printf("\nPrice: %f",(*P).price);
    printf("\nQuantity: %d",(*P).qty); 
    printf("\nTotal Amount: %f",(*P).amount); 
} 