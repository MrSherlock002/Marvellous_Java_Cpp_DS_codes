//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Monday (15/11/2021)
//  Wap to Understand Data Structure concepts.
//  Circular Singly linked List in C++
//
//////////////////////////////////////////////////////////////////////////


#include<iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE;

class SinglyCL
{
    private:
        PNODE first;
        PNODE last;
        int size;

    public :
    SinglyCL()
    {
        first = NULL;
        last = NULL;
        size = 0;
    }


    void Display()
    { 
        PNODE temp = first;

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
    int Count()
    { 
        return size;
    }
    void InsertFirst(int no)
    { 
        PNODE newn = new NODE;

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

    void InsertLast(int no)
    {
        PNODE newn = new NODE;

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
    void InsertAtPos(int no, int iPos)
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
            PNODE newn = new NODE;
            newn->data = no;
            newn->next = NULL;
            
            PNODE temp = first;

            for(int i=1; i<iPos-1; i++)
            {
                temp = temp ->next;
            }
            newn->next = temp->next;
            temp->next = newn;
            size++;
        }
    }
    void DeleteFirst()
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
    void DeleteLast()
    { 
        PNODE temp = first;
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

    void DeleteAtPos(int iPos)
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
            PNODE temp =first,targeted=NULL;
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
};

int main()
{
    int iRet=0;
    SinglyCL obj;
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of elements Are :"<<iRet<<"\n";

    obj.DeleteFirst();
    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of elements Are :"<<iRet<<"\n";

    obj.InsertAtPos(55,1);
    obj.Display();

    obj.DeleteAtPos(2);
    obj.Display();

    return 0;
}