//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Wednesday (18/11/2021)
//  Wap to Understand Data Structure concepts.
//  Circular Doubly linked List in C++
//  Generic code for Doubly CL
//
//////////////////////////////////////////////////////////////////////////


#include<iostream>
using namespace std;

template <typename T>      //Template Header
struct node
{
    T data;
    struct node *Next;
    struct node *prev;
};

template <class T>
class DoublyCL
{
    private:
        node <T> * first;
        node <T> * last;
        int size;

    public:
    DoublyCL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();    
};

    template <class T>
    DoublyCL<T>::DoublyCL()
        {
            first = NULL;
            last = NULL;
            size = 0;
        }

//Return_value Class_Name :: Function_Name(parameters)

template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
    node <T> * newn = new node <T>;
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

template <class T>
void DoublyCL<T>::InsertLast(T no)
{
    node <T> * newn = new node <T>;
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

template <class T>
void DoublyCL<T> :: Display()
{
    node <T> * temp = first;
    for(int i=1; i<=size; i++)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->Next;
    }
    cout<<"\n";
}

template <class T>
int DoublyCL<T> ::Count()
{
    return size;
}
template <class T>
void DoublyCL<T> :: DeleteFirst()
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


template <class T>
void DoublyCL<T> :: DeleteLast()
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


template <class T>
void DoublyCL<T> :: InsertAtPos(T no,int pos)
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
        node <T> * newn = new node <T>;
        newn ->data = no;
        newn->Next = NULL;
        newn->prev = NULL;

        node <T> * temp = first;
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


template <class T>
void DoublyCL<T> :: DeleteAtPos(int pos)
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
        node <T> * temp = first;
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
///////////////////////////////////////////////////////////////
int main()
{
    DoublyCL <char> obj;
    obj.InsertFirst('A');
    obj.InsertFirst('B');
    obj.InsertFirst('C');
    obj.InsertLast('1');
    obj.InsertAtPos('Z',4);
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

