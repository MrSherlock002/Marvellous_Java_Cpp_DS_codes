//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Friday (19/11/2021)
//  Binary Search Tree
//  
//////////////////////////////////////////////////////////////////////////



#include<iostream>

using namespace std;

typedef struct node 
{
    int data;
    struct node * LChild;
    struct node * RChild;
}NODE,*PNODE,**PPNODE;

void Insert(PPNODE Head, int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->LChild = NULL;
    newn->RChild = NULL;

    if(*Head==NULL)
    {
        *Head = newn;
    }
    else
    {
        PNODE temp = *Head;
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


bool Search(PNODE Head,int no)
{
    bool flag = false;
    if(Head == NULL)        //Tree is empty
    {
        return false;
    }
    else        //Tree contains atleast one node.
    {
        while(Head!=NULL)
        {
            if(Head->data == no)        //if Node Found
            {
                flag = true;
                break;
            }
            else if(no>(Head->data))
            {
                Head = Head ->RChild;
            }
            else if(no<(Head ->data))
            {
                Head = Head->LChild;
            }
        }
        return flag;
    }
}


int Count(PNODE Head)
{
    static int iCnt =0;

    if(Head!=NULL)
    {
        iCnt++;
        Count(Head->LChild);
        Count(Head->RChild);
    }
    return iCnt;
}



int CountLeaf(PNODE Head)
{
    static int iCnt =0;

    if(Head!=NULL)
    {
        if((Head->LChild==NULL) && (Head->RChild==NULL))
        {
            iCnt++;
        }
        CountLeaf(Head->LChild);
        CountLeaf(Head->RChild);
    }
    return iCnt;
}


int CountParent(PNODE Head)
{
    static int iCnt =0;

    if(Head!=NULL)
    {
        if((Head->LChild!=NULL) || (Head->RChild!=NULL))
        {
            iCnt++;
        }
        CountParent(Head->LChild);
        CountParent(Head->RChild);
    }
    return iCnt;
}


void Inorder (PNODE Head)       //LDR
{
    if(Head != NULL)
    {
        Inorder (Head ->LChild);    //L
        cout<<(Head->data)<<"\t";   //D
        Inorder(Head->RChild);      //R
    }
}


void Postorder (PNODE Head)       //LRD
{
    if(Head != NULL)
    {
        Inorder (Head ->LChild);    //L
        Inorder(Head->RChild);      //R
        cout<<(Head->data)<<"\t";   //D
    }
}


void Preorder(PNODE Head)           //DLR
{
    if(Head != NULL)
    {
        cout<<(Head->data)<<"\t";   //D
        Inorder (Head ->LChild);    //L
        Inorder(Head->RChild);      //R
        
    }
}



int main()
{
    int iValue=0;
    bool bRet=false;
    PNODE first= NULL;
    Insert(&first, 51);
    Insert(&first, 21);
    Insert(&first, 101);

    cout<<"\n Enter number to search : ";
    cin>>iValue;

    bRet = Search(first,iValue);

    if(bRet == true)
    {
        cout<<"\n Data is there :";
    }
    else
    {
        cout<<"\n Data is not present : ";
    }

    int iRet = Count(first);
    cout<<"\n Number of nodes : \t "<<iRet<<"\n";

    int iRet1 = CountLeaf(first);
    cout<<"\n Number of Leaf nodes : \t "<<iRet1<<"\n";

    int iRet2 = CountParent(first);
    cout<<"\n Number of Parent nodes :\t "<<iRet2<<"\n";

    cout<<"\nInorder :\n ";
    Inorder(first);
    cout<<"\nPostorder :\n ";
    Postorder(first);
    cout<<"\nPreorder :\n ";
    Preorder(first);

    return 0;
}

