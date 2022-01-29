//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Thursday (18/11/2021)
//  WAP to understand Recursion
//  
//////////////////////////////////////////////////////////////////////////



#include<iostream>
#include<stdio.h>
#include <stdlib.h>

void DisplayI(int iNo)
{
int iCnt=1;
while(iCnt<=iNo)
    {
        printf("\n Marvellous ..\n");
        iCnt++;
    }
}

void DisplayR( int iNo)
{
    static int iCnt= 1;

    if(iCnt <= iNo)
    {
        printf("\n Marvellous\n ");
        iCnt++;
        DisplayR(iNo);
    }

}


int main()
{
    int iValue=0;
    printf("\n Enter Value : ");
    scanf("%d",&iValue);
    DisplayR(iValue);

    return 0;
}