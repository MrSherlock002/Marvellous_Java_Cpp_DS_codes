/////////////////////////////////////////////////////////////////////
//
// Prasad R. Bhosale
// Wednesday   (13/10/2021)
// WAP to perform addition of numbers. 
//
/////////////////////////////////////////////////////////////////////


import java.util.*;

class Program2
{
    public static int Addition(int i, int j)
    {
        int iResult =0;
        iResult = i+j;
        return iResult;
    }

    public static void main(String str[])
    {
        Scanner sobj  = new Scanner(System.in);
        int iNo1 =0, iNo2=0, iAns=0;
        
        System.out.println("\nEnter First Number : ");
        iNo1 = sobj.nextInt();

        System.out.println("\nEnter Second Number : ");
        iNo2 = sobj.nextInt();

        iAns = Addition(iNo1,iNo2);

        System.out.println("\n Addition is = "+iAns);
    }
}