//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Thursday (18/11/2021)
//  WAP to understand Recursion
//  problems on strings using Recursion
//  
//////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;


int strlenR(char *str)
{
   static int iLen=0;
    if(*str !='\0')
    {
        iLen++;
        str++;
        strlenR(str);
    }

return iLen;
}


int main()
{
    char Arr[20];
    int iRet =0;

    cout<<"\n Enter String :";
    scanf("%[^'\n']s",Arr);

    iRet = strlenR(Arr);
    
    cout<<"\n Capital letters : "<<iRet;
    
    return 0;
}