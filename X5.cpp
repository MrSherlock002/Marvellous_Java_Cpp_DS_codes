//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Thursday (18/11/2021)
//  Wap to Understand Data Structure concepts.
//  Circular Doubly linked List in C++
//  Generic code for SinglyLL, DoublyLL, SinglyCL, DoublyCL. 
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

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


template <class T>
class SinglyLL
{
private:
    node <T>* first;
    int size;

public:
SinglyLL();
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

SinglyLL<T> ::SinglyLL()
    {
        first = NULL;
        size = 0;
    }

    template <class T>
    void SinglyLL<T>::InsertFirst(T no)
    {
        node <T> * newn = new node <T>;      //newn = (PNODE)malloc(sizeof(NODE))
        newn->data = no;
        newn->next = NULL;

        if(first==NULL)
        {
            first =newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        size++;
    }

    template <class T>
    void SinglyLL<T>::InsertLast(T no)
    {
        node <T> * newn = new node <T>;      //newn = (PNODE)malloc(sizeof(NODE))
        newn->data = no;
        newn->next = NULL;

        if(first==NULL)
        {
            first =newn;
        }
        else
        {
           node <T> * temp = first;
           while (temp->next!=NULL)
           {
               temp = temp->next;
           }
           temp->next = newn;
           
        }
        size++;
    }

    template <class T>
    void SinglyLL<T>::InsertAtPos(T no,int ipos)
    {
        if ((first == NULL) || (ipos>Count()) || (ipos<=0))
        {
            return ;
        }    
        else if(ipos == 1)
        {
            InsertFirst(no);
        }
        else if (ipos == (Count()+1))
        {
            InsertLast(no);
        }
        else
        {
            node <T> * newn = new node<T>;      //newn = (PNODE)malloc(sizeof(NODE))
            newn->data = no;
            newn->next = NULL;   

            node <T> * temp = first;

            for(int i=1; i<=(ipos-2); i++)
            {
                temp = temp ->next;
            }
            newn ->next = temp ->next;
            temp ->next = newn;
            size ++;
        }
    }

    template <class T>
    void SinglyLL<T>::DeleteFirst()
    {
        node <T> * temp = first;
        if(first != NULL)
        {
            first = first->next;
            delete temp;
        }
        size--;
    }

    template <class T>
    void SinglyLL<T>::DeleteLast()
    {
        node <T> * temp = first;

        if(first == NULL)
        {
            return ;
        }
        else if(first->next == NULL)
        {
            delete first;
            first = NULL;
            size--;
        }
        else
        {
            while(temp->next->next!=NULL)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next =NULL;
            size--;
        }
    }

    template <class T>
    void SinglyLL<T>::DeleteAtPos(int ipos)
    {
        int i=0;
        if ((first == NULL) || (ipos>Count()) || (ipos<=0))
        {
            return ;
        }    
        else if(ipos == 1)
        {
            DeleteFirst();
        }
        else if (ipos == (Count()))
        {
            DeleteLast();
        }
        else   
        {
            node <T> * temp = first;
            node <T> * targeted =NULL;
            for(i=1; i<=(ipos-2); i++)
            {
                temp = temp->next;
            } 
            targeted = temp->next;
            temp->next = targeted->next;
            delete(targeted);
            size--;
        }
    }

    template <class T>
    void SinglyLL<T>::Display()
    {
        node <T> * temp = first;
        while(temp!=NULL)
        {
            cout<<"|"<<temp->data<<"|"<<"->"<<"\t";
            temp = temp->next;
        }
        cout<<"\t NULL \n";

    }

    template <class T>
    int SinglyLL<T>::Count()
    {
        return size;
    }


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


template <class T>

class DoublyLL
{
private:
    node <T> * first;
    int size;

public:
DoublyLL();
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

DoublyLL<T>::DoublyLL()
    {
        first = NULL;
        size = 0;
    }

    template <class T>
    void DoublyLL<T>::InsertFirst(T no)
    {
        node <T> * newn = new node <T>;      //newn = (PNODE)malloc(sizeof(NODE))
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if(first==NULL)
        {
            first=newn;
        }
        else
        {
            newn->next = first;
            first->prev = newn;
            first = newn;
        }
        size++;
    }

    template <class T>
    void DoublyLL<T>::InsertLast(T no)
    {
        node <T> * newn = new node <T>;      //newn = (PNODE)malloc(sizeof(NODE))
        newn->data = no;
        newn->next = NULL;
        newn ->prev = NULL;

        if(first==NULL)
        {
            first =newn;
        }
        else
        {
           node <T> * temp = first;
           while (temp->next!=NULL)
           {
               temp = temp->next;
           }
           temp->next = newn;
           newn->prev = temp;
           
        }
        size++;
    }

    template <class T>
    void DoublyLL<T>::InsertAtPos(T no,int ipos)
    {
        if ((ipos>(Count()+2)) || (ipos<=0))
        {
            printf("\n Please enter correct data !");
            return ;
        }    
        else if(Count()==0)
        {
            InsertFirst(no);
        }
        else if (ipos ==Count()+1)
        {
            InsertLast(no);
        }
        else
        {
            node <T> * newn = new node <T>;      //newn = (PNODE)malloc(sizeof(NODE))
            newn->data = no;
            newn->next = NULL;  
            newn ->prev = NULL; 

            node <T> * temp = first;

            for(int i=1; i<(ipos-1); i++)
            {
                temp = temp ->next;
            }
            newn ->next = temp ->next;
            newn->next->prev = newn;
            temp ->next = newn;
            newn->prev = temp;
            size ++;
        }
    }

    template <class T>
    void DoublyLL<T>::DeleteFirst()
    {
        node <T> * temp = first;
        
        if(first==NULL)
        {
            return ;
        }

        else if(first->next == NULL)
        {
            delete first;
            first = NULL;
            
        }
        else
        {
            first = first->next;
            delete (first->prev);
            first->prev=NULL;
        }
        size--;
    }

    template <class T>
    void DoublyLL<T>::DeleteLast()
    {
        node <T> * temp = first;

        if(first == NULL)
        {
            return ;
        }
        else if(first->next == NULL)
        {
            delete first;
            first = NULL;
        }
        else
        {
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->prev->next = NULL;
            delete temp;
        }
        size--;
    }

    template <class T>
    void DoublyLL<T>::DeleteAtPos(int ipos)
    {
        int i=0;
        if ((first == NULL) || (ipos>Count()) || (ipos<=0))
        {
            printf("\n Please enter correct data !");
            return ;
        }    
        else if(ipos == 1)
        {
            DeleteFirst();
        }
        else if (ipos == (Count()))
        {
            DeleteLast();
        }
        else   
        {
            node <T> * temp = first;
            for(i=0; i<(ipos-2); i++)
            {
                temp = temp->next;
            } 
            temp->next=temp->next->next;
            delete temp->next->prev;
            temp->next->prev=temp;
            size--;
        }
    }

    template <class T>
    void DoublyLL<T>::Display()
    {
        node <T> * temp = first;
        while(temp!=NULL)
        {
            cout<<"|"<<temp->data<<"|"<<"->"<<"\t";
            temp = temp->next;
        }
        cout<<"\t NULL \n";

    }

    template <class T>
    int DoublyLL<T>::Count()
    {
        return size;
    }


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


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


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


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

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

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

