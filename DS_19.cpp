//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Thursday (18/11/2021)
//  WAP to understand Recursion
//  
//////////////////////////////////////////////////////////////////////////



#include <stdio.h>

void DisplayI()
{
int iCnt=1;
while(iCnt<=4)
    {
        printf("\n Marvellous ..\n");
        iCnt++;
    }
}

void DisplayR()
{
    static int iCnt= 1;

    if(iCnt <= 4)
    {
        printf("\n Marvellous\n ");
        iCnt++;
        DisplayR();
    }

}


int main()
{
    DisplayR();

    return 0;
}