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
    char x='\0',y='\0';
    cout<<"\n Enter First number :";
    cin>>x;
    cout<<"\n Enter Second number :";
    cin>>y;

    Swap(&x,&y);

    cout<<"\n Value of X becomes : "<<x<<"\n";
    cout<<"\n Value of Y becomes : "<<y<<"\n";

    return 0;
}