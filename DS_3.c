//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Monday (08/11/2021)
//  Wap to Understand Data Structure concepts.
//
//////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>


struct node
{
int data;
struct node *next;
};


typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int main()
{

PNODE p = NULL;
PPNODE q = NULL;

p =(PNODE)malloc(sizeof(NODE));

q = &p;

return 0;
}


/*
p = 100
q = 200
&p = 200
&q = 300

p->data = 11
p->next = NULL
*q = 100
(*q)->data = 11
(*q)->next = NULL

*/