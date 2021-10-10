#include<stdio.h>
#include<stdlib.h>
#define size 10

struct node
{
    int element;
    struct node *next;
}*array[size],*new=NULL,*temp=NULL, *ptr=NULL;



int hash_family(int s)
{  
    int temp=0, fam=0;
    temp=s;
    fam = temp % 10;
    
    return fam;

}

void Search()
{
    int ele,temp;
    printf("Input Element to be searched: ");
    scanf("%d",&ele);
    
    int pos=hash_family(ele);

   if (array[pos]!= NULL)
        {
            temp=array[pos];
            printf("Element found at family %d\n", pos);
        }
    else
    {
        printf("Element not found\n");
    }
    return;
    

}

void display()
{
    int i;

    for(i = 0; i < size; i++)
    {
        ptr = array[i];
        printf("family[%d]",i);
        while(ptr)
        {
            printf("-->%d ",ptr->element);
            ptr=ptr->next;
        }
        printf("\n");
        
    }
}


void insert()
{
    int ele,family;
    printf("Input the element: ");
    scanf("%d",&ele);
    new= (struct node*) malloc(sizeof(struct node));
    new->element = ele;
    new->next =NULL;

    family= hash_family(ele);
    if(array[family]==NULL)
    {
        array[family]=new;
    }
    else
    {
        temp=array[family];
        while(temp->next !=0)
        {
            temp=temp->next;
        }
        temp->next=new;
    }
    printf("Node inserted successfully in family %d.\n",family);
    
}
int main()
{ 
    int choice;
    char ch='y';
    while(ch=='y' || ch=='Y')
    { 
    printf("=========== MAIN MENU ===========\n");
    printf("1.Insert into Hash Table\n2.Display\n3.Search\nEnter your choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        insert();
        break;
    case 2:
        display();
        break;
    case 3:
        Search();
        break;
    default:
        printf("\nInvalid Choice!\n");
        break;
    }
    printf("If want to continue press y to exit n?..y/n: ");
    scanf("%s",&ch);
    }
    return 0;
}
