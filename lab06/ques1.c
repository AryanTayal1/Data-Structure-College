//Implement a hash function on a student SAP-ID and categorize them in to their 10 familiar based on last three digits.

#include<stdio.h>
#include<stdlib.h>
int family[10][10]={0};
int main()
{
	int input, sapid=0, temp=0, index=0, i, j;
	MainMenu:
	printf("\n\n\t\t\t\tMainMenu\t\t\t\t\n");
	printf("\n1) Insert");
	printf("\n2) Display");
	printf("\n3) Exit");
	printf("\nInput: ");
	scanf("%d", &input);
	switch (input)
	{
		case 1: 
			printf("\nSAP ID: ");
			scanf("%d", &sapid);
			temp=sapid;
			for(i=1; i<=3; i++)
			{
				index=temp%10+index;
				temp=temp/10;
				
			}
			index=index%9;
			for(j=0; j<10; j++)
			{
				printf("jere");
				if(family[index][j]==0)
				{
					printf("Here");
					family[index][j]=sapid;
					printf("\n%d %d.%d", family[index][j], index, j);
					break;
				}
			}
			goto MainMenu;
			break;
		
		case 2:
			for(i=0; i<10; i++)
			{
				printf("\nFamily %d: ", i);
				for(j=0; j<10; j++);
				{
					if(family[i][j]!=0)
					{
						printf("  %d", family[i][j]);
					}
					
				}
			}
			goto MainMenu;
			break;
		
		case 3:
			exit(0);
			break;
			
		default:
			printf("\nInvalid input! ");
			goto MainMenu;
	}
}
