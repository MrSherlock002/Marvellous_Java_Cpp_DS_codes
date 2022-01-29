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


//Specific Function
void Swap(char *p, char *q)
{
    char temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

//Generic Function
template <class T>
void SwapX(T *p, T *q)
{
    T temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

int main()
{
    char x='A',y='Z';
    SwapX(&x,&y);

    cout<<"\n Value of X becomes : "<<x<<"\n";
    cout<<"\n Value of Y becomes : "<<y<<"\n";

    int i=11,j=22;
    SwapX(&i,&j);

    cout<<"\n Value of X becomes : "<<i<<"\n";
    cout<<"\n Value of Y becomes : "<<j<<"\n";

    return 0;
}