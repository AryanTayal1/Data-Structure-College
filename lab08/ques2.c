//Store n numbers in a linked list> Perform Linear search for the given number and report success or failure in form of suitable message.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;          
    struct node *next; 
} * head;

void createList(int n);
void displayList();
int  searchRecursive(int key, struct node *curNode, int index);


int main()
{
    int n, keyToSearch, index;

    printf("Enter number of node to create: ");
    scanf("%d", &n);

    createList(n);

    printf("\nData in list: \n");
    displayList();

    printf("\nEnter element to search: ");
    scanf("%d", &keyToSearch);

    index = searchRecursive(keyToSearch, head, 0);

    if (index >= 0)
        printf("%d found in the list at position %d\n", keyToSearch, index + 1);
    else
        printf("%d not found in the list.\n", keyToSearch);
    

    return 0;
}

void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = malloc(sizeof(struct node));

    if (head == NULL)
    {
        printf("Unable to allocate memory. Exiting from app.");
        exit(0);
    }
    

    printf("Enter data of node 1: ");
    scanf("%d", &data);

    head->data = data; 
    head->next = NULL; 

    temp = head;

    for (i = 2; i <= n; i++)
    {
        newNode = malloc(sizeof(struct node));

        if (newNode == NULL)
        {
            printf("Unable to allocate memory. Exiting from app.");
            exit(0);
        }

        printf("Enter data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data; 
        newNode->next = NULL; 

        temp->next = newNode; 
        temp = temp->next;
    }
    
}


void displayList()
{
    struct node *temp;

 
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    
    temp = head;
    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->next;    
    }
    printf("\n");
}

int searchRecursive(int key, struct node *curNode, int index)
{
    if (curNode == NULL)               
        return -1;
    else if (curNode->data == key)  
        return index;
    else                               
        return searchRecursive(key, curNode->next, index + 1);
}
