#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
    //int key;
    int data;
    struct node *next;
};

void insertFirst(int data);
void printList();
struct node* deleteFirst();
int Length();
void Sort();
void reverse();

struct node *head = NULL;
struct node *lastElement = NULL;

int main()
{
    insertFirst(11);
    insertFirst(93);
    insertFirst(76);
    insertFirst(90);
    insertFirst(8);

    printList();
    printf("Length of List: %d\n", Length());

    printf("Sorted list: \n");
    Sort();
    printList();

    printf("Reversed list: \n");
    reverse();
    printList();
}

void insertFirst(int data)
{
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->data = data; // data inserted

    link->next = head;

    head = link;
}

struct node* deleteFirst()
{
    struct node *tempLink = head;

    head = head->next;

    return tempLink;
}

int Length()
{
    int len = 0;
    struct node *current = head;

    while (current != NULL)
    {
        current = current->next;
        len++;
    }

    return len;
}

//bubble sort
void Sort()
{
    int i, j , k, temp;
    struct node *current;
    struct node *next;

    int size = Length();

    k = size;
    for (i = 0; i < size - 1; i++, k--)
    {
        current = head;
        next = head->next;
        for (j = 1; j < k; j++)
        {
            if (current->data > next->data)
            {
                // swap them
                temp = current->data;
                current->data = next->data;
                next->data = temp;
            }

            current = current->next;
            next = next->next; 
        }
    }
}

void reverse() 
{
   struct node *prev   = NULL;
   struct node *current = head;
   struct node *next;
   while (current != NULL) {
      next  = current->next;  
      current->next = prev;   
      prev = current;
      current = next;
   }
   head = prev;
}

//display the list
void printList() {

   struct node *ptr = head;

   printf("\n[head] =>");
   //start from the beginning
   while(ptr != NULL) {        
      printf(" %d =>",ptr->data);
      ptr = ptr->next;
   }

   printf(" [null]\n");
}