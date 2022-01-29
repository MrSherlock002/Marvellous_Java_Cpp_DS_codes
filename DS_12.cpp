//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Tuesday (16/11/2021)
//  Wap to Understand Data Structure concepts.
//  Stack concept in C++
//
//////////////////////////////////////////////////////////////////////////


#include<iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE;

class Stack         //Singly Linear Linked List
{
    private:
        PNODE first;
        int size;
    
    public:
    Stack()
    {
        first = NULL;
        size =0;
    }

    void push(int no)       //InsertFirst
    {
        PNODE newn = new NODE;
        
        newn->data = no;
        newn->next = NULL;

        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        
    }

    int pop()           //DeleteFirst
    {
        int no=0;
        PNODE temp = first;
        if(first == NULL)
        {
            cout<<"\n Stack is Empty";
            return -1;
        }
        else if(first->next==NULL)
        {
            no = first->data;
            delete first;
            first = NULL;
        }
        else
        {
            no = first->data;
            first = first->next;
            delete temp;
        }
        size--;
        return no;
    }

    void Display()
    {
        PNODE temp = first;
        while(temp!=NULL)
        {
            printf("|%d|->",temp->data);
            temp = temp->next;
        }
        printf("\t NULL");

    }

    int Count()
    {
        int iCnt =0;
        while(first!=NULL)
        {
            iCnt++;
            first = first->next;
        }
        return iCnt;
    }

};


int main()
{
    Stack obj;
    cout<<"Elements of stack :";
    obj.push(11);
    obj.push(21);
    obj.push(51);
    obj.push(101);

    obj.Display();
    int iRet = obj.pop();   //101
    cout<<"\n Popped element is :"<<"\n"<<iRet;

    cout<<"\n Elements of stack :";
    obj.Display();
    iRet = obj.Count();

    cout<<"\n  size of stack : "<<iRet;
    return 0;
}