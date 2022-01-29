//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Friday (19/11/2021)
//  Binary Search Tree
//  
//////////////////////////////////////////////////////////////////////////



#include<iostream>

using namespace std;

template <typename T>      //Template Header
struct node 
{
    T data;
    struct node * LChild;
    struct node * RChild;
};


template <class T>      
class BST               //Binary Search Tree
{
    private:
    node <T> * first;
    int size;

    public:   
    
    BST();
    void Insert(T);
    bool Search(T);

    void Inorder(node <T> * first);
    void Postorder(node <T> * first);
    void Preorder(node <T> * first);

    int Count(node <T> * first);
    int CountLeaf(node <T> * first);
    int CountParent(node <T> * first);
};
    template<class T> 
    BST<T>::BST()
    {
        first == NULL;
        size=0;
    }

    template<class T> 
    void BST<T>::Insert(T no)
{
    node <T> * newn = new node <T>;

    newn->data = no;
    newn->LChild = NULL;
    newn->RChild = NULL;

    if(first==NULL)
    {
        first = newn;
    }
    else
    {
        node <T> * temp = first;
        while(1)        //Unconditional LOOP       // for(;;)->Unconditional Loop
        {
            if(temp->data == no)
            {
                cout<<"\n Duplicate Node";
                delete newn;
                break;
            }
            else if(no<(temp->data))      //Small data;
            {
                if(temp->LChild == NULL)
                {
                temp->LChild=newn;
                break;
                }
                temp = temp->LChild;
            }

            else if(no>(temp->data))      // Large data
            {   
                if(temp->RChild == NULL)
                {
                    temp ->RChild = newn;
                    break;
                }
                temp = temp->RChild;
            }
        }
    }
}


template <class T>  
bool BST<T>::Search(T no)
{
    bool flag = false;
    if(first == NULL)        //Tree is empty
    {
        return false;
    }
    else        //Tree contains atleast one node.
    {
        while(first!=NULL)
        {
            if(first->data == no)        //if Node Found
            {
                flag = true;
                break;
            }
            else if(no>(first->data))
            {
                first = first ->RChild;
            }
            else if(no<(first ->data))
            {
                first = first->LChild;
            }
        }
        return flag;
    }
    return flag;
}


template <class T>  
int BST<T>::Count(node <T> * first)
{
    static int iCnt =0;

    if(first!=NULL)
    {
        iCnt++;
        Count(first->LChild);
        Count(first->Rchild);
    }
    return iCnt;
}



template <class T>  
int BST<T>::CountLeaf(node <T> * first)
{
    static int iCnt =0;

    if(first!=NULL)
    {
        if((first->LChild==NULL) && (first->RChild==NULL))
        {
            iCnt++;
        }
        CountLeaf();
        CountLeaf();
    }
    return iCnt;
}


template <class T>  
int BST<T>::CountParent(node <T> * first)
{
    static int iCnt =0;

    if(first!=NULL)
    {
        if((first->LChild!=NULL) || (first->RChild!=NULL))
        {
            iCnt++;
        }
        CountParent();
        CountParent();
    }
    return iCnt;
}


template <class T>  
void BST<T>::Inorder(node <T> * first)       //LDR
{
    if(first != NULL)
    {
        Inorder ();    //L
        cout<<(first->data)<<"\t";   //D
        Inorder();      //R
    }
}


template <class T>  
void BST<T>::Postorder(node <T> * first)       //LRD
{
    if(first != NULL)
    {
        Inorder ();    //L
        Inorder();      //R
        cout<<"\t";   //D
    }
}


template <class T>  
void BST<T>::Preorder(node <T> * first)           //DLR
{
    if(first != NULL)
    {
        cout<<(first->data)<<"\t";   //D
        Inorder (first->LChild);    //L
        Inorder(first->RChild);      //R
        
    }
}


////////////////////////////////////////////////////////
int main()
{
    
    BST<int> obj;
    int iValue=0;
    bool bRet=false;
    //struct node<T> * first= NULL;
    node <T> * first= NULL;
    obj.Insert(51);
    obj.Insert(21);
    obj.Insert(101);

    cout<<"\n Enter number to search : ";
    cin>>iValue;

    bRet = obj.Search(iValue);

    if(bRet == true)
    {
        cout<<"\n Data is there :";
    }
    else
    {
        cout<<"\n Data is not present : ";
    }

    int iRet = obj.Count(node <T> * first);
    cout<<"\n Number of nodes : \t "<<iRet<<"\n";

    int iRet1 = obj.CountLeaf(first);
    cout<<"\n Number of Leaf nodes : \t "<<iRet1<<"\n";

    int iRet2 = obj.CountParent(first);
    cout<<"\n Number of Parent nodes :\t "<<iRet2<<"\n";

    cout<<"\nInorder :\n ";
    obj.Inorder(first);
    cout<<"\nPostorder :\n ";
    obj.Postorder(first);
    cout<<"\nPreorder :\n ";
    obj.Preorder(first);

    return 0;
}

