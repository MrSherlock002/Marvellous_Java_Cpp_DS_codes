//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Tuesday (16/11/2021)
//  Wap to Understand Data Structure concepts.
//  Queue concept in C++
//
//////////////////////////////////////////////////////////////////////////


#include<iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE;

class Queue         //Singly Linear Linked List
{
    private:
        PNODE first;
        int size;
    
    public:
    Queue()
    {
        first = NULL;
        size =0;
    }

    void Enqueue(int no)       //InsertLast
    {
        PNODE newn = new NODE;
        newn->data = no;
        newn->next = NULL;

        if(size==0)
        {
            first = newn ;
        }
        else
        {
            PNODE temp = first;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        size++;  
    }
    

    int Dequeue()           //DeleteFirst
    {
        int no=0;
        PNODE temp = first;
        if(first == NULL)
        {
            cout<<"\n Stack is Empty";
            return -1;
        }
        if(first->next==NULL)
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
        for(int i=1; i<=size; i++,temp=temp->next)
        {
            cout<<"|"<<temp->data<<"|->";
        }
        cout<<"\n";

    }

    int Count()
    {
        return size;
    }

};


int main()
{
    Queue obj;

    obj.Enqueue(11);
    obj.Enqueue(21);
    obj.Enqueue(51);
    obj.Enqueue(101);

    cout<<"\n Elements of Queue : \n ";
    obj.Display();

    int iRet = obj.Dequeue();
    cout<<"\n Removed element : "<<iRet;

    cout<<"\n Elements of Queue : \n ";
    obj.Display();
    iRet = obj.Count();

    cout<<"\n "<<iRet;
    return 0;
}