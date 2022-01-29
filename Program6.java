/////////////////////////////////////////////////////////////////////
//
// Prasad R. Bhosale
// Monday   (18/10/2021)
// WAP to to understand concepts of Array in JAVA.
//
/////////////////////////////////////////////////////////////////////


import java.util.*;

class Program6 
{
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner (System.in);
        int iSize = 0,iCnt = 0;


        System.out.println("Enter Number of elements ");
        iSize = sobj.nextInt();

        int Arr[] = new int[iSize];
        System.out.println("Enter Numbers :");

        for(iCnt=0; iCnt<Arr.length; iCnt++)
        {
           Arr[iCnt] = sobj.nextInt(); 
        }
        System.out.println("Entered elements are :");
        for(iCnt=0; iCnt<Arr.length; iCnt++)
        {
           System.out.println(Arr[iCnt]);
        }


    }
}