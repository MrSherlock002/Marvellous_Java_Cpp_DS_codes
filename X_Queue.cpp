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

template <typename T>      //Template Header
struct node
{
    T data;
    struct node *next;
};

template <class T>
class Queue         //Singly Linear Linked List
{
    private:
        node <T>* first;
        int size;
    
    public:
    Queue()
    {
        first = NULL;
        size =0;
    }
    void Enqueue(T);
    int Dequeue();
    void Display();
    int Count();
};

template <class T>
void Queue<T>::Enqueue(T no)       //InsertLast
    {
        node <T>* newn = new node <T>;
        newn->data = no;
        newn->next = NULL;

        if(size==0)
        {
            first = newn ;
        }
        else
        {
            node <T>* temp = first;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        size++;  
    }
    

    template <class T>
    int Queue<T>::Dequeue()           //DeleteFirst
    {
        int no=0;
        node <T>* temp = first;
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

    template <class T>
    void Queue<T>::Display()
    {
        node <T>* temp = first;
        for(int i=1; i<=size; i++,temp=temp->next)
        {
            cout<<"|"<<temp->data<<"|->";
        }
        cout<<"\n";

    }

    template <class T>
    int Queue<T>::Count()
    {
        return size;
    }




int main()
{
    Queue<int> obj;

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