//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Sunday (21/11/2021)
//  Wap to Understand Data Structure concepts.
//  Stack concept in C++
//
//////////////////////////////////////////////////////////////////////////


#include<iostream>

using namespace std;

template <typename T>      //Template Header
struct node
{
    T data;
    struct node *next;
};

template <class T>
class Stack         //Singly Linear Linked List
{
    private:
        node <T>* first;
        int size;
    
    public:
    Stack()
    {
        first = NULL;
        size =0;
    }
    void push(T);
    int pop();
    void Display();
    int Count();
};

template <class T>
void Stack<T>:: push(T no)       //InsertFirst
    {
        node <T>* newn = new node <T>;
        
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

    template <class T>
    int Stack<T>:: pop()           //DeleteFirst
    {
        int no=0;
        node <T>* temp = first;
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

    template <class T>
    void Stack<T>::Display()
    {
        node <T>* temp = first;
        while(temp!=NULL)
        {
            printf("|%d|->",temp->data);
            temp = temp->next;
        }
        printf("\t NULL");

    }

    template <class T>
    int Stack<T>:: Count()
    {
        int iCnt =0;
        while(first!=NULL)
        {
            iCnt++;
            first = first->next;
        }
        return iCnt;
    }



int main()
{
    Stack<char> obj;
    cout<<"Elements of stack :";
    obj.push('A');
    obj.push('B');
    obj.push('C');
    obj.push('Z');

    obj.Display();
    int iRet = obj.pop();   //101
    cout<<"\n Popped element is :"<<"\n"<<iRet;

    cout<<"\n Elements of stack :";
    obj.Display();
    iRet = obj.Count();

    cout<<"\n  size of stack : "<<iRet;
    return 0;
}