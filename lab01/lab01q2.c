//-  Create a menu driven program that works with an integer array ‘a1’ with number ‘n’. A count of total number of elements in ‘a1’ should always be maintained.
#include<stdio.h>
#include<conio.h>
#define MAX_SIZE 100
int main()
{
    int c=0, num, res, n, flag=0, i;
    while(c!=4)
    {
        //display menu
        printf("\n1. Input the arrya\n2. Delete the array\n3. Merging of two array\n4. Display f the array\n5. Exit\n");

        //display choice option to the user
        printf("\nEnter your choice:");
        scanf("%d", &c);

        //write case statement for Four options

        switch(c)
        {
            //For factorial block
            case 1:

				{
					int arr[MAX_SIZE];
					int i, size, num, pos;

					/* Input size of the array */
						printf("Enter size of the array : ");
						scanf("%d", &size);

					/* Input elements in array */
					printf("Enter elements in array : \n");
					for(i=0; i<size; i++)
						{
							scanf("%d", &arr[i]);
						}

						/* Input new element and position to insert */
						printf("Enter element to insert : ");
						scanf("%d", &num);
						printf("Enter the element position : ");
						scanf("%d", &pos);

						/* If position of element is not valid */
						if(pos > size+1 || pos <= 0)
						{
							printf("Invalid position! Please enter position between 1 to %d", size);
						}
						else
						{
						/* Make room for new array element by shifting to right */
							for(i=size; i>=pos; i--)
							{
								arr[i] = arr[i-1];
							}
			
							/* Insert new element at given position and increment size */
							arr[pos-1] = num;
							size++; 

							/* Print array after insert operation */
							printf("Array elements after insertion : ");
							for(i=0; i<size; i++)
							{
								printf("%d\t", arr[i]);
							}
						}
				}
				break;

            //To delet from the array
            case 2:

                {
					int array[100], position, c, n;


					printf("Enter the location where you wish to delete element\n");
					scanf("%d", &position);

					if (position >= n+1)
						printf("Deletion not possible.\n");
					else
					{
						for (c = position - 1; c < n - 1; c++)
							array[c] = array[c+1];

						printf("Resultant array:\n");

						for (c = 0; c < n - 1; c++)
							printf("%d\n", array[c]);
					}
				}
                break;

            //to merge an array
            case 3:

               int arr1[50], arr2[50], size1, size2, i, k, merge[100];
				printf("Enter Array 1 Size: ");
				scanf("%d", &size1);
				printf("Enter Array 1 Elements: ");
				for(i=0; i<size1; i++)
				{
					scanf("%d", &arr1[i]);
					merge[i] = arr1[i];
				}
				k = i;
				printf("\nEnter Array 2 Size: ");
				scanf("%d", &size2);
				printf("Enter Array 2 Elements: ");
				for(i=0; i<size2; i++)
				{
					scanf("%d", &arr2[i]);
					merge[k] = arr2[i];
					k++;
				}
				printf("\nThe new array after merging is:\n");
				for(i=0; i<k; i++)
					printf("%d ", merge[i]);
				getch();;
                break;

			//to display of array
			case 4:
				printf("The array is", arr1[i])
				break;

            //For Exit block
            case 5:
                printf("\nExit");
                return 0;
        }
    }

}
