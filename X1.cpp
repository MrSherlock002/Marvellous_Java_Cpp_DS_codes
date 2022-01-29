//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Wednesday (17/11/2021)
//  Wap to Understand Data Structure concepts.
//  Singly Linked List in C++
//  Generic code for SinglyLL
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
   

/////////////////////////////////////////////////////////////////////
int main()
{

int iChoice =1, value =0, iRet=0,pos=0;

SinglyLL <int> obj;

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
            obj.InsertFirst(value);
            break;
        
        case 2 :
            printf("\n Enter the data to insert ");
            scanf("%d",&value);
            obj.InsertLast(value);
            break;
        
        case 3 :
            printf("\n Enter the data to insert ");
            scanf("%d",&value);
            printf("\n Enter the position ");
            scanf("%d",&pos);
            obj.InsertAtPos(value,pos);
            break;
        
        case 4 :
            obj.DeleteFirst();
            break;
        
        case 5 :
            obj.DeleteLast();
            break;

        case 6 :
            printf("\n Enter the position : ");
            scanf("%d",&pos);
            obj.DeleteAtPos(pos);  
            break;

        case 7 :
            printf("\n Element of linked list are : ");
            obj.Display();
            break;

        case 8:
            iRet = obj.Count();
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




// int main()
// {
//     int iRet=0;
//     SinglyLL obj;

//     obj.InsertFirst(51);
//     obj.InsertFirst(21);
//     obj.InsertFirst(11);

//     obj.InsertLast(101);
//     obj.InsertLast(111);
//     obj.Display();

//     iRet = obj.Count();
//     cout<<"\n Number of elements are :"<<iRet;
//     return 0;
// }



/*
-------------------------------
Type 1: 

while(temp!=NULL)
{
    temp = temp->next;
}
-------------------------------

Type 2:
while(temp->next!=NULL)
{
    temp = temp->next;
}

--------------------------------

Type 3:

while(temp->next->next!=NULL)
{
    temp = temp->next;
}
--------------------------------

*/