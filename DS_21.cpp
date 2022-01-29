//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Thursday (18/11/2021)
//  WAP to understand Recursion
//  Pattern printing problems -------- Return the sum of all digits.
//  
//////////////////////////////////////////////////////////////////////////


#include <iostream>

using namespace std;

int SumI(int iNo)
{
    int iSum = 0;
    while(iNo!=0)
    {
        iSum = iSum +(iNo%10);
        iNo = iNo/10;
    }
    return iSum;
}


int SumR(int iNo)
{
    static int iSum =0;

    if(iNo!=0)
    {    
    iSum = iSum +(iNo%10);
    iNo = iNo/10;
    SumR(iNo);
    }
    return iSum;
}

int main()
{
    int x=0, iRet=0;

    cout<<"\n Enter the Number :";
    cin>>x;

    iRet = SumR(x);
    
    cout<<"\n Summation of Digits = "<<iRet;

    return 0;
}