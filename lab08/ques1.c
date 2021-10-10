//Store n numbers in an array in an unsorted order. Using menu driven logic perform search for a given number and report success or failure in the form of suitable message.

#include <stdio.h>
#include <stdlib.h>

void linear_search(int search_key,int array[100],int n)
{
    int i,location;
    for(i=1;i<=n;i++)
    {
        if(search_key == array[i])
        {
            location = i;
            printf("The location of seached value is = %d is %d\n",location,search_key);
        }
    }
}


void binary_search(int search_key,int array[100],int n)
{
    int mid,i,low,high;
    low = 1;
    high = n;
    mid = (low + high)/2;
    i=1;
    while(search_key != array[mid])
    {
        if(search_key <= array[mid])
        {
            low = 1;
            high = mid+1;
            mid = (low+high)/2;
        }
        else
        {
            low = mid+1;
            high = n;
            mid = (low+high)/2;
        }
    }

    printf("location=%d\t",mid);
    printf("Search_Key=%d Found!\n",search_key);

}

int main()
{
    int array[100],search_key,i,j,n,low,high,location,choice;
    int getch(void);
    void linear_search(int search_key,int array[100],int n);
    void binary_search(int search_key,int array[100],int n);


    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter the elements of array:\n");

    for(i=1;i<=n;i++)
    {
        scanf("%d",&array[i]);
    }

    printf("Enter the value you want to search:");
    scanf("%d",&search_key);

    printf("**********\n");

    printf("1.LINEAR SEARCH\n");
    printf("2.BINARY SEARCH\n");

    printf("*********\n");

    printf("Input Your Choice:");
    scanf("%d",&choice);

    switch(choice)
    {

    case 1:
        linear_search(search_key,array,n);
        break;

    case 2:
        binary_search(search_key,array,n);
        break;

    default:
        exit(0);
    }

    getch();
    return 0;
}
