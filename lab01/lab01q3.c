//Changing the string in lower string
#include<stdio.h>
#include<string.h>


void main()
{
//	Declaring the size of string
	int n; 
	printf("Enter the number of characters which you want to be converted into lower string:\n"); 
	scanf("%d", &n); 
//	Declaring string
	char str[n];
	printf("Now enter your string in upper case:\n"); 
	while (getchar() != '\n');
	gets(str);
	int i; 
	for(i = 0; i <= n; i++)
	{
	  		if (str[i] >= 'A' && str[i] <= 'Z')
	   {
		str[i] = str[i] + 32; 
	    }
	}
	printf( "The lower case of the given string is: \n%s", str);
		 
}
