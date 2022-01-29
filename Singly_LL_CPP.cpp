////////////////////////////////////////////////////////////////////
//
// Prasad R. Bhosale
// Monday (15/11/2021)
// Singly Linear Linked-List using CPP.
//
////////////////////////////////////////////////////////////////////



#include<iostream>

using namespace std;

#define TRUE 1
#define FALSE 0

typedef int BOOL;
 
typedef struct node
{
    int Data;
    struct node *Next;
}NODE,*PNODE;

class Singly_LinkedList
{
    private:
    PNODE Head;
    
    public:
    Singly_LinkedList();
    ~Singly_LinkedList();
    BOOL InsertFirst(int);
    BOOL InsertLast(int);
    BOOL InsertAtPosition(int,int);
    inline void Display();
    inline int Count();
    BOOL DeleteFirst();
    BOOL DeleteLast();
    BOOL DeleteAtPosition(int);
};

Singly_LinkedList::Singly_LinkedList()
{
    Head= NULL;
}
Singly_LinkedList::~Singly_LinkedList()
{
    PNODE Temp,Navigate;
    if(Head!=NULL)
    {
        Navigate = Head;    
        while(Navigate!=NULL)
        {
            Temp=Navigate->Next;
            delete Navigate;
            Navigate = Temp;
        }
    }
}

BOOL Singly_LinkedList ::InsertFirst(int no)
{
    PNODE newn = NULL;
    newn = new NODE;
    if(newn == NULL)
    {
        return FALSE;
    }
    newn->Next = NULL;
    newn->Data=no;

    if(Head==NULL)
    {
        Head =newn;
    }
    else
    {
        newn->Next=Head;
        Head=newn;
    }
    return TRUE;
}

BOOL Singly_LinkedList::InsertLast(int no)
{
    PNODE newn = NULL,temp=Head;
    newn = new NODE;
    
    if(newn==NULL)
    {
        return FALSE;
    }
    newn->Next = NULL;
    newn->Data = no;

    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        while(temp->Next!=NULL)
        {
            temp = temp->Next;
        }
        temp->Next = newn;
    }
    return TRUE;
}


BOOL Singly_LinkedList::InsertAtPosition(int pos, int no)
{
    if((Head==NULL)||(pos>Count()+1)||(pos<=0))
    {
        return FALSE;
    }
    if(pos==1)
    {
        return(InsertFirst(no));
    }
    else
    {
        PNODE newn = NULL,temp = Head;
        newn= new NODE;
        if(newn==NULL)
        {
            return FALSE;
        }
        newn->Next=NULL;
        newn->Data = no;

        for(int i=0; i<(pos-2); i++)
        {
            temp = temp ->Next;
        }
        newn->Next = temp->Next;
        temp->Next=newn;
    }
    return TRUE;
}

BOOL Singly_LinkedList :: DeleteFirst()
{
    PNODE temp = Head;

    if(Head==NULL)
    {
        return FALSE;
    }
    else
    {
        Head = Head->Next;
        free(temp);
    }
    return TRUE;
}


BOOL Singly_LinkedList::DeleteLast()
{
    if(Head==NULL)
    {
        return FALSE;
    }
    else if(Head->Next==NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        PNODE temp1 = Head,temp2=NULL;
        while(temp1->Next->Next!=NULL)
        {
            temp1 = temp1->Next;
        }
        temp2=temp1->Next;
        temp1->Next = NULL;
        free(temp2);
    }
    return TRUE;
}


BOOL Singly_LinkedList :: DeleteAtPosition(int pos)
{
    if((Head==NULL)|| (pos>Count())||(pos<=0))
    {
        return FALSE;
    }
    else if(pos==1)
    {
        DeleteFirst();
    }
    else if (pos==(Count()))
    {
        DeleteLast();
    }
    else
    {
        PNODE temp1 = Head,temp2=NULL;

        for(int i=0; i<(pos-2); i++)
        {
            temp1=temp1->Next;
            ++i;
        }
        temp2= temp1->Next;
        temp1->Next=temp2->Next;
        delete temp2;
    }
    return TRUE;
}


void Singly_LinkedList::Display()
{
    PNODE temp = Head;

    while(temp!=NULL)
    {
        cout<<temp->Data<<"->";
        temp = temp->Next;
    }
    cout<<"  NULL \n";
}

int Singly_LinkedList::Count()
{
    PNODE temp = Head;
    int iCnt =0;
    while(temp!=NULL)
    {
        iCnt ++;
        temp= temp->Next;
    }
    return iCnt;
}

int main()
{
    int iChoice =1, value =0, iRet=0,pos=0;
    Singly_LinkedList obj1;
    //Singly_LinkedList *obj2 = new Singly_LinkedList();

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
            obj1.InsertFirst(value);
            break;
        
        case 2 :
            printf("\n Enter the data to insert ");
            scanf("%d",&value);
            obj1.InsertLast(value);
            break;
        
        case 3 :
            printf("\n Enter the data to insert ");
            scanf("%d",&value);
            printf("\n Enter the position ");
            scanf("%d",&pos);
            obj1.InsertAtPosition(value,pos);
            break;
        
        case 4 :
            obj1.DeleteFirst();
            break;
        
        case 5 :
            obj1.DeleteLast();
            break;

        case 6 :
            printf("\n Enter the position : ");
            scanf("%d",&pos);
            obj1.DeleteAtPosition(pos);  
            break;

        case 7 :
            printf("\n Element of linked list are : ");
            obj1.Display();
            break;

        case 8:
            iRet = obj1.Count();
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