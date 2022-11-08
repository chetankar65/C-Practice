#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

struct node {
    // int key;
    int data;
    struct node *next;
    struct node *prev;
};

bool isEmpty();
void insertFirst(int data);
void printList();
void insertLast(int data);
struct node* deleteLast();
void insert(int index, int data);
void delete(int index);

struct node *head = NULL;
struct node *last = NULL;

// insert first function

bool isEmpty(){
   return head == NULL;
}

void insertFirst(int data)
{
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->data = data;

    if(isEmpty()){
        //make it the last link
        last = link;
    } else {
        //update first prev link
        head->prev = link;
    }

    link->next = head;
    head = link;
}

int Length()
{
    int len = 0;
    struct node *current;
    current = head;

    while (current != NULL)
    {
        len++;
        current = current->next;
    }

    return len;
}

void displayForward()
{
    struct node *ptr = head;
    printf("Head=> ");
    
    while (ptr != NULL){
        printf("%d => ", ptr->data);
        ptr = ptr->next;
    }

    printf("Tail \n");
}

void displayBackward()
{
    struct node *ptr = last;
    printf("Tail=> ");
    
    while (ptr != NULL){
        printf("%d => ", ptr->data);
        ptr = ptr->prev;
    }

    printf("Head \n");
}

//insert link at the last location
void insertLast(int data){
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->data = data;
   if(isEmpty()){
      //make it the last link
      last = link;
   } else {
      //make link a new last link
      last->next = link;     
      
      //mark old last node as prev of new link
      link->prev = last;
   }
   //point last to new last node
   last = link;
}

//delete link at the last location
struct node* deleteLast() {
   //save reference to last link
   struct node *tempLink = last;
   
   //if only one link
   if(head->next == NULL){
      head = NULL;
   } else {
      last->prev->next = NULL;
   }
   last = last->prev;
   //return the deleted link
   return tempLink;
}

void insert(int index, int data)
{
    int i = 0;
    struct node *current;
    struct node *link = (struct node*) malloc(sizeof(struct node));
    struct node* prev;
    int size = Length();
    if (index < size)
    {
        current = head;
        while(i != index)
        {
            i++;
            current = current->next;
        }

        if (i != 0)
        {
            link->data = data;
            prev = current->prev;

            prev->next = link;
            link->next = current;
            link->prev = prev;
            current->prev = link;
        }
        else 
        {
            link->data = data;
            current->prev = link;
            link->next = current;
            head = link;
        }

    }

}

int main()
{
    insertFirst(10);
    insertFirst(20);
    insertFirst(67);

    printf("Display Forward: \n");
    displayForward();
    printf("\n");
    printf("Display Backward: \n");
    displayBackward();
    printf("\n");

    printf("Inserting an element last: \n");
    insertLast(11);
    insertLast(27);
    displayForward();
    displayBackward();
    printf("\n");

    printf("Deleting Last element: \n");
    deleteLast();
    displayForward();

    printf("Length of list: %d\n", Length());
    printf("Inserting at a particular position: \n");
    insert(3, 23);
    displayForward();
}