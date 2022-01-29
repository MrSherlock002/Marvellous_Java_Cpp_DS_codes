//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Friday (15/12/2021)
//  Interview problems
//  
//////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>

typedef struct node

{
int data;
struct node *next;

}NODE,*PNODE,**PPNODE;

void InsertFirst(PPNODE Head,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
}

void Display(PNODE first)
{
while(first !=NULL)
{
    printf("| %d |->",first->data);
    first = first->next;
}
printf("\n");
}

void Reverse(PPNODE first)
{
    PNODE Front,Back,Current;

    Front = NULL;
    Back = NULL;
    Current = *first;

    while(Current != NULL)
    {
        Front = Current->next;
        Current->next = Back;
        Back = Current;
        Current = Front;    
    }
    *first = Back;
}


int main()
{
    PNODE Head = NULL;

    // InsertFirst(&Head,110);
    // InsertFirst(&Head,100);
    // InsertFirst(&Head,90);
    // InsertFirst(&Head,80);
    // InsertFirst(&Head,70);
    InsertFirst(&Head,60);
    InsertFirst(&Head,50);
    InsertFirst(&Head,40);
    InsertFirst(&Head,30);
    InsertFirst(&Head,20);
    InsertFirst(&Head,10);

    Display(Head);

    Reverse(&Head);

    printf("\n Linked list after reverse");

    Display(Head);

    return 0;
}



