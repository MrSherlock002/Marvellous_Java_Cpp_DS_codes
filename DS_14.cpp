//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Wednesday (17/11/2021)
//  WAP to understand generic programming 
//  
//
//////////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

void Swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

int main()
{
    int x=0,y=0;
    cout<<"\n Enter First number :";
    cin>>x;
    cout<<"\n Enter Second number :";
    cin>>y;

    Swap(&x,&y);

    cout<<"\n Value of X becomes : "<<x<<"\n";
    cout<<"\n Value of Y becomes : "<<y<<"\n";

    return 0;
}