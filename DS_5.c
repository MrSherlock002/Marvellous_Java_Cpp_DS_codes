//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Wednesday (10/11/2021)
//  Wap to Understand Data Structure concepts.
//  Singly Linked List in C
//
//////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE,**PPNODE;


void Display(PNODE Head)
{
while(Head !=NULL)
{
    printf(" |%d|->",Head->data);
    Head = Head->next;
}
printf("\t NUll \n");
}

int Count(PNODE Head)
{
    int iCnt=0;
    while(Head !=NULL)
{
    iCnt++;
    Head = Head->next;
}
    return iCnt;

}



void InsertFirst(PPNODE Head, int no)
{
PNODE newn = NULL;
newn = (PNODE)malloc(sizeof(NODE));

newn ->data = no;
newn->next = NULL;

if(*Head == NULL)
{
    *Head = newn;
}
else
{
    newn ->next = *Head;
    *Head = newn;
}
}

void InsertLast(PPNODE Head, int no)
{
PNODE newn = NULL;
PNODE temp = *Head;
newn = (PNODE)malloc(sizeof(NODE));

newn ->data = no;
newn->next = NULL;

if(*Head == NULL)
{
    *Head = newn;
}
else
{
    while(temp->next!=NULL)
    {
        temp = temp ->next;
    }
    temp->next = newn;
}  
}



void DeleteFirst(PPNODE Head)
{
    PNODE temp = *Head;
if(*Head !=NULL)
{
    *Head = (*Head)->next;
    free(temp);
}  
}


void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;
    if(*Head == NULL)
    {
        return ;
    }
    else if ((*Head)->next==NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}


void InsertAtPos(PPNODE Head, int no, int iPos)
{
int size = 0;
PNODE newn = NULL;
PNODE temp = *Head;
int i=0;
size = Count(*Head);

if ((iPos < 1) || (iPos >size+1))       //Filter for invalid position.
{
    return ;
}
if (iPos == 1)          //First position
{
    InsertFirst(Head,no);
}
else if (iPos == (size + 1))        //Last Postion
{
    InsertLast(Head,no);
}
else        //Inbetween position.
{
    newn = (PNODE)malloc(sizeof(NODE));
    newn ->data = no;
    newn ->next = NULL;

    for(i=1;i<(iPos-1);i++)
    {
        temp = temp->next;
    }
    newn->next=temp->next;
    temp->next = newn;
}
}


void DeleteAtPos(PPNODE Head,int iPos)
{
int size = 0;
PNODE newn = NULL;
PNODE temp = *Head;
int i=0;
size = Count(*Head);
PNODE targeted = NULL;

if ((iPos < 1) || (iPos >size))       //Filter for invalid position.
{
    return ;
}
if (iPos == 1)          //First position
{
    DeleteFirst(Head);
}
else if (iPos == (size ))        //Last Postion
{
    DeleteLast(Head);
}
else        //Inbetween position.
{
    for (i=0; i<iPos-1; i++)
    {
        temp = temp ->next;
    }
    targeted = temp->next;
    temp->next = targeted ->next;
    free(targeted);
}
}



// Main Function
int main()
{
PNODE first = NULL;

int iChoice =1, value =0, iRet=0,pos=0;

while (iChoice!=0)
{
    printf("\n___________________________________________\n");
    printf("Enter the desired operation that you want to perform on LinkedList \n");
    printf("\n 1.Insert the node at first position ");
    printf("\n 2.Insert the node at last position ");
    printf("\n 3.Insert the node at desired position ");
    printf("\n 4.Delete the first node ");
    printf("\n 5.Delete the last node ");
    printf("\n 6.Delete the node at desired position ");
    printf("\n 7.Display the contents of Linked List ");
    printf("\n 8.Count the number of nodes from Linked List ");
    printf("\n 0.Terminate the Application ");
    printf("\n___________________________________________\n");
    scanf("%d",&iChoice);

    switch(iChoice)
    {
        case 1 :
            printf("\n Enter the data to insert ");
            scanf("%d",&value);
            InsertFirst(&first,value);
            break;
        
        case 2 :
            printf("\n Enter the data to insert ");
            scanf("%d",&value);
            InsertLast(&first,value);
            break;
        
        case 3 :
            printf("\n Enter the data to insert ");
            scanf("%d",&value);
            printf("\n Enter the position ");
            scanf("%d",&pos);
            InsertAtPos(&first,value,pos);
            break;
        
        case 4 :
            DeleteFirst(&first);
            break;
        
        case 5 :
            DeleteLast(&first);
            break;

        case 6 :
            printf("\n Enter the position : ");
            scanf("%d",&pos);
            DeleteAtPos(&first,pos);  
            break;

        case 7 :
            printf("\n Element of linked list are : ");
            Display(first);
            break;

        case 8:
            iRet = Count(first);
            printf("\n Number of elements are : %d",iRet);
            break;

        case 0:
                printf("Thanks for using Marvellous Linked List\n");
                break;
                
        default:
                printf("\n Please enter proper choice\n");
                break;
    }   

}
    return 0;
}