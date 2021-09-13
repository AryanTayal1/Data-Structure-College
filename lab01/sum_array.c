//sum of elements of array by recursion

#include<stdio.h>

int sum_of_array(int arr[], int start, int len); 

int main()
{
	int a,i,sum; 
	printf("Please input the length of the array:"); 
	scanf("%d", &a); 
	int arr[a]; 
	printf("Now input the elements of the array:\n"); 
	for(i = 0; i < a ; ++i)
	{
		scanf("%d", &arr[i]);
	}
	sum = sum_of_array(arr, 0, a);
	printf("Therefor the total number of the elements of array is : %d", sum); 
	return 0; 
}

int sum_of_array(int arr[], int start, int len)
{
	if(start >= len)
	{
		return 0; 
	}
	return(arr[start] + sum_of_array(arr, start+1, len)); 
}
