//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Tuesday (16/11/2021)
//  Wap to Understand Data Structure concepts.
//  Circular Doubly linked List in C++
//
//////////////////////////////////////////////////////////////////////////


#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *Next;
    struct node *prev;
}NODE,*PNODE;

class DoublyCL
{
    private:
        PNODE first;
        PNODE last;
        int size;

    public:
        DoublyCL()
        {
            first = NULL;
            last = NULL;
            size = 0;
        }

        void Display();
        int Count();
        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

//Return_value Class_Name :: Function_Name(parameters)
void DoublyCL::InsertFirst(int no)
{
    PNODE newn = new NODE;
    newn->data = no;
    newn->Next = NULL;
    newn->prev = NULL;

    if((first==NULL)&&(last==NULL))
    {
        first= newn;
        last = newn;
    }
    else
    {
        newn->Next = first;
        first ->prev = newn;
        first=newn;
    }
    last->Next = first;
    first->prev = last;
    size++;
}


void DoublyCL::InsertLast(int no)
{
    PNODE newn = new NODE;
    newn->data = no;
    newn->Next = NULL;
    newn->prev = NULL;

    if((first==NULL)&&(last==NULL))
    {
        first= newn;
        last = newn;
    }
    else
    {
        last->Next= newn;
        newn->prev = last;
        last = newn;
    }
    last->Next = first;
    first->prev = last;
    size++;
}


void DoublyCL :: Display()
{
    PNODE temp = first;
    for(int i=1; i<=size; i++)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->Next;
    }
    cout<<"\n";
}

int DoublyCL ::Count()
{
    return size;
}

void DoublyCL :: DeleteFirst()
{
    if((first==NULL)||(last==NULL))
    {
        return ;
    }
    else if(first == last)
    {
        delete first;
        first =NULL;
        last =  NULL;
    }
    else
    {
        first = first->Next;
        delete last->Next;
    }
    first->prev = last;
    last->Next = first;
    size--;
}



void DoublyCL :: DeleteLast()
{
    if((first==NULL)||(last==NULL))
    {
        return ;
    }
    else if(first == last)
    {
        delete first;
        first =NULL;
        last =  NULL;
    }
    else
    {
        last = last->prev;
        delete last->Next;   
    }
    first->prev = last;
    last->Next = first;
    size--;
}



void DoublyCL :: InsertAtPos(int no,int pos)
{
    if((pos>Count()+1)||pos<1)
    {
        printf("\n Please enter correct option ..!!");
        return ;
    }
    else if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos==(Count()+1))
    {
        InsertLast(no);
    }
    else
    {
        PNODE newn = new NODE;
        newn ->data = no;
        newn->Next = NULL;
        newn->prev = NULL;

        PNODE temp = first;
        for(int i=1; i<(pos-1);i++)
        {
            temp = temp->Next;
        }
        newn ->Next = temp->Next;
        newn->Next->prev = newn;
        temp->Next = newn;
        newn->prev = temp;
        size++;
    }
}



void DoublyCL :: DeleteAtPos(int pos)
{
    if((pos>Count()+1)||pos<1)
    {
        printf("\n Please enter correct option ..!!");
        return ;
    }
    else if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos==(Count()+1))
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = first;
        for(int i=1; i<(pos-1);i++)
        {
            temp = temp->Next;
        }
        temp->Next = temp->Next->Next;
        delete (temp->Next->prev);
        temp->Next->prev = temp;
        size--;
    }
}

int main()
{
    DoublyCL obj;
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.InsertLast(101);
    obj.InsertAtPos(91,4);
    obj.Display();

    int iRet = obj.Count();
    cout<<"\n Number of elements are :"<<iRet<<"\n";

    obj.DeleteAtPos(4);
    obj.DeleteFirst();
    obj.DeleteLast();
    obj.Display();

    iRet = obj.Count();
    cout<<"\n Number of elements are :"<<iRet<<"\n";
    return 0;
}

