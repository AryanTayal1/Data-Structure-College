//Give the breath-first transversal realize a complete binary tree with an array. Implement the following.
//a.	Given inde of a node, identify the node’s children and parent.
//b.	Identify and print th available parent-letchild-rightchild ode combination.
//c.	Identify and print the leaf nodes available in CBT.

#include<stdio.h>
#include<stdlib.h>
#define arrSize 100
int arr[arrSize]={0};

void index_data()
{
	int index;
	printf("\nIndex-Data: ");
	for(index=0; arr[index]!=-2; index++)
	{
		if(arr[2*index+1]<1 && arr[2*index+2]<1)
		{
			printf("%d-%d, ", index, arr[index]);
		}
	}
}

void Parentleftrightcombinations()
{
	int index;
	printf("\nParent-Left Child -Right Child: ");
	for(index=0; arr[index]!=-2; index++)
	{
		if(arr[2*index+1]>0 && arr[2*index+2]>0)
		{
			printf("%d-%d-%d, ", arr[index], arr[2*index+1], arr[2*index+2]);
		}
	}
}
void ChildParentidentification()
{
	int index;
	printf("Enter index: ");
	scanf("%d", &index);
	if(arr[index]<1)
	{
		printf("\nData not found at the index");
		return;
	}
	else
	{
		if(index==0)
		{
			printf("\nRoot node! Parent not available!");
			printf("\nLeft child: ");
			if(arr[2*index+1]<1)
			{
				printf("Null");
			}
			else
			printf("%d", arr[2*index+1]);
			printf("\nRight child: ");
			if(arr[2*index+2]<1)
			{
				printf("Null");
			}
			else
			printf("%d", arr[2*index+2]);
		}
		else
		{
			int parentIndex;
			if(index%2==0)
			{
				parentIndex=(index-2)/2;
			}
			else
			{
				parentIndex=(index-1)/2;
			}
			printf("\nParent: %d", arr[parentIndex]);
			printf("\nLeft child: ");
			if(arr[2*index+1]<1)
			{
				printf("Null");
			}
			else
			printf("%d", arr[2*index+1]);
			printf("\nRight child: ");
			if(arr[2*index+2]<1)
			{
				printf("Null");
			}
			else
			printf("%d", arr[2*index+2]);			
		}
	}
}

int main()
{
	int i=0, input;
	printf("\nEnter the breadth-first traversal of the binary tree");
	printf("\nValid Input is natural numbers only\n-2 to stop adding data\n-1 for empty space\n");
	while(1)
	{
		printf("Enter data: ");
		scanf("%d", &arr[i]);
		if(arr[i]==-2)
		{
			break;
		}
		i++;
	}
	while(1)
	{
		printf("\n\nMainMenu\n========");
		printf("\n1) Identification of child and parent of nth node.");
		printf("\n2) Print combinations of Parent-Left Child-Right Child .");
		printf("\n3) Print leaf nodes.");
		printf("\n0) Exit.");
		printf("\nInput: ");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				ChildParentidentification();
				break;
			
			case 2:
				Parentleftrightcombinations();
				break;
			
			case 3:
				index_data();
				break;
			
			case 0:
				exit(0);
			
			default:
				printf("Invalid input! Try again...");
		}
	}
}

