//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Thursday (18/11/2021)
//  WAP to understand Recursion
//  problems on Factorial using Recursion
//  
//////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

int SumI(int Arr[],int size)
{
    int iSum=0;
    for(int i=0; i<size; i++)
    {
        iSum = iSum + Arr[i];
    }
    return iSum;
}


int SumR(int Arr[],int size)
{

    static int i=0,iSum =0;
    if(i<size)
    {
        iSum = iSum + Arr[i];
        i++;
        SumR(Arr,size);
    }
    return iSum;
}


int main()
{
    int iLength =0,i=0,iRet=0;
    int *p = NULL;

    cout<<"\n Enter number of elements : ";
    cin>>iLength;

    p = new int[iLength];       //this allocates the memory for p

    cout<<"Enter the elements : ";
    for(i=0;i<iLength;i++)
    {
    cin>>p[i];
    }

    iRet = SumR(p,iLength);

    cout<<"\n Addition is : "<<iRet;

    delete []p;
    
    return 0;
}