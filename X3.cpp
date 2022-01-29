//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Wednesday (18/11/2021)
//  Wap to Understand Data Structure concepts.
//  Circular Singly linked List in C++
//  Generic code for CircularLL
//
//////////////////////////////////////////////////////////////////////////


#include<iostream>

using namespace std;

template <typename T>       //Template Header 

struct node
{
    T data;
    struct node *next;
};

template <class T>

class SinglyCL
{
    private:
        node <T> * first;
        node <T> * last;
        int size;

    public :
    SinglyCL();
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
SinglyCL<T>::SinglyCL()
    {
        first = NULL;
        last = NULL;
        size = 0;
    }

    template <class T>
    void SinglyCL<T>::Display()
    { 
        node <T> *  temp = first;

        if((first == NULL)&&(last==NULL))
        {
            return ;
        }
        do{
            cout<<"|"<<temp->data<<"|->";
            temp = temp->next;
          }
          while(temp!=last->next);
          cout<<"\n";
    }

    template <class T>
    int SinglyCL <T>::Count()
    { 
        return size;
    }

    template <class T>
    void SinglyCL<T>::InsertFirst(T no)
    { 
        node <T> *  newn = new node <T>;

        newn->data = no;
        newn->next = NULL;

        if((first ==NULL) && (last==NULL))
        {
            first = newn;
            last=newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        last->next = first;
        size++;
    }

    template <class T>
    void SinglyCL<T>::InsertLast(T no)
    {
        node <T> *  newn = new node <T>;

        newn->data = no;
        newn->next = NULL;

        if((first ==NULL) && (last==NULL))
        {
            first = newn;
            last=newn;
        }
        else
        {
            last->next = newn;
            last = newn;
        }
        last->next = first;
        size++;
    }

    template <class T>
    void SinglyCL<T>::InsertAtPos(T no, int iPos)
    { 
        if((iPos>Count()+1)||iPos<1)
        {
            printf("\n Please enter correct option..!!");
            return ;
        }
        else if(iPos==1)
        {
            InsertFirst(no);
        }
        else if(iPos==Count()+1)
        {
            InsertLast(no);
        }
        else
        {
            node <T> *  newn = new node <T>;
            newn->data = no;
            newn->next = NULL;
            
            node <T> *  temp = first;

            for(int i=1; i<iPos-1; i++)
            {
                temp = temp ->next;
            }
            newn->next = temp->next;
            temp->next = newn;
            size++;
        }
    }

    template <class T>
    void SinglyCL<T>::DeleteFirst()
    { 
        if((first==NULL) && (last==NULL))
        {
            return ;
        }
        else if(first == last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            first = first->next;
            delete last->next;
        }
        last->next = first;
        size--;
    }

    template <class T>
    void SinglyCL<T>::DeleteLast()
    { 
        node <T> *  temp = first;
        if((first==NULL) && (last==NULL))
        {
            return ;
        }
        else if(first == last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            while(temp->next!=last)
            {
                temp = temp->next;
            }
            delete last;
            last = temp;
            last->next = first;
        }
        size--;
    }

    template <class T>
    void SinglyCL<T>::DeleteAtPos(int iPos)
    { 
        if((iPos>Count()+1)||iPos<1)
        {
            printf("\n Please enter correct option..!!");
            return ;
        }
        else if(iPos==1)
        {
            DeleteFirst();
        }
        else if(iPos==Count())
        {
            DeleteLast();
        }
        else
        {
            node <T> * temp =first;
            node <T> * targeted=NULL;
            for(int i=0; i<(iPos-2);i++)
            {
                temp= temp->next;
            }
            targeted = temp->next;
            temp->next = targeted->next;
            delete targeted;
            size--;
        }
    }

/////////////////////////////////////////////////////////////////
int main()
{
    int iRet=0;
    SinglyCL<char> obj;
    obj.InsertFirst('A');
    obj.InsertFirst('B');
    obj.InsertFirst('C');

    obj.InsertLast('Z');

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of elements Are :"<<iRet<<"\n";

    obj.DeleteFirst();
    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of elements Are :"<<iRet<<"\n";

    obj.InsertAtPos('P',1);
    obj.Display();

    obj.DeleteAtPos(2);
    obj.Display();

    return 0;
}