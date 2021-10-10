//Sort the List of Elements stored in an array using the following algorithms
//(i) Insertion Sort	(ii) Selection Sort (iii) Merge Sort (iv) Quick Sort

#include <stdio.h>
#include <stdlib.h>

void insertion_sort ( int A[ ] , int n) 
{
     for( int i = 0 ;i < n ; i++ ) 
     {
        int temp = A[ i ];    
        int j = i;

        while( temp < A[ j -1] && j > 0 ) 
        {
                A[ j ] = A[ j-1];   
                j= j - 1;

        }
        
       A[ j ] = temp;       
     }  
}

void selection_sort (int A[ ], int n)
{
    int minimum;        
    for(int i = 0; i < n-1 ; i++)
    {
        minimum = i ;
        for(int j = i+1; j < n ; j++ )
        {
            if(A[ j ] < A[ minimum ])
            { 
                minimum = j ;
            }
        }
        swap ( A[ minimum ], A[ i ]) ; 
    }
}

void merge(int A[ ] , int start, int mid, int end)
{
    int p = start ,q = mid+1;

    int Arr[end-start+1] , k=0;

    for(int i = start ;i <= end ;i++) 
    {
        if(p > mid)      
           Arr[ k++ ] = A[ q++] ;

       else if ( q > end)  
           Arr[ k++ ] = A[ p++ ];

       else if( A[ p ] < A[ q ])    
          Arr[ k++ ] = A[ p++ ];

       else
          Arr[ k++ ] = A[ q++];
   }
   for (int p=0 ; p< k ;p ++) 
   {
       A[ start++ ] = Arr[ p ] ;                          
   }
}

int partition ( int A[],int start ,int end) 
{
    int i = start + 1;
    int piv = A[start] ;      
    for(int j =start + 1; j <= end ; j++ )
    {
        if ( A[ j ] < piv) 
        {
            swap (A[ i ],A [ j ]);
            i += 1;
        }
   }
   swap ( A[ start ] ,A[ i-1 ] ) ;  
   return i-1;                    
}

void quick_sort ( int A[ ] ,int start , int end ) 
{
   if( start < end ) 
   {
         int piv_pos = partition (A,start , end ) ;     
         quick_sort (A,start , piv_pos -1); 
         quick_sort ( A,piv_pos +1 , end) ; 
   }
}

int main() 
{
    int choice; int a[50]; int size ;int i ;
    printf("Input number of elementss in the linked list?:");
    scanf("%d", &size);
    printf("Input the elements in the linked list:");
    for (i=0; i<size; i++)
    {
        scanf("\n%d", &a[i]);
    }

    printf("Enter the method by which you want to do sorting\n1Insertion sorting\n(2)Selection Sorting\n(3)Merge Sorting\n(4)Quick Sorting\n");
    scanf("%c", &choice);

    switch(choice)
    {
        case '1':
            printf("Sorting by Insertion Sort");
            insertion_sort(a[i]);
            printf("Sorted List is:",a[i]);
            break;

        case '2':
            printf("Sorting by Selection Sort");
            selection_sort(a[i]);
            printf("Sorted List is:",a[i]);
            break;

        case '3':
            printf("Sorting by Merge Sort");
            merge(a[i]);
            printf("Sorted List is:",a[i]);
            break;

        case '4':
            printf("Sorting by Quick Sort");
            quick_sort(a[i]);
            printf("Sorted List is:",a[i]);
            break;

        default:
            printf("Error!");
    }

    return 0;
}



