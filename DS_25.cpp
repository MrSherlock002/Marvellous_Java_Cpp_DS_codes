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

int CountCapR(char *str)
{
    static int iCnt=0;

    if(*str !='\0')
    {
        if((*str>='A')&&(*str<='Z'))
        {
            iCnt++;
        }
        str++;
        CountCapR(str);
    }
    return iCnt;
}



int main()
{
    char Arr[20];
    int iRet =0;

    cout<<"\n Enter String :";
    scanf("%[^'\n']s",Arr);

    iRet = CountCapR(Arr);
    
    cout<<"\n Capital letters : "<<iRet;
    
    return 0;
}