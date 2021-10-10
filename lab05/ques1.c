//Check whether the string is palindrome or not using a queue implemented with a Linked List.

#include <stdio.h>
#include <stdlib.h>
 
// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};
 
// Helper function to create a new node with the given data and
// pushes it onto the list's front
void push(struct Node** head, int data)
{
    // create a new linked list node from the heap
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
 
// Recursive function to check if the linked list is a palindrome or not
int checkPalindrome(struct Node** left, struct Node* right)
{
    // base case
    if (right == NULL) {
        return 1;
    }
 
    int result = checkPalindrome(left, right->next) &&
            ((*left)->data == right->data);
    (*left) = (*left)->next;
 
    return result;
}
 
// Function to check if the linked list is a palindrome or not
int checkPalin(struct Node* head) {
    return checkPalindrome(&head, head);
}
 
int main(void)
{
    // input keys
    int keys[] = { 2,4,1,9,5};
    int n = sizeof(keys) / sizeof(keys[0]);
 
    struct Node* head = NULL;
    for (int i = n - 1; i >= 0; i--) {
        push(&head, keys[i]);
    }
 
    if (checkPalin(head)) {
        printf("The linked list is a palindrome");
    }
    else {
        printf("The linked list is not a palindrome");
    }
 
    return 0;
}
