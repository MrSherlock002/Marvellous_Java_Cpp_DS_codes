/////////////////////////////////////////////////////////////////////
//
// Prasad R. Bhosale
// Monday   (18/10/2021)
// WAP to  to perform addition of N numbers.
//
/////////////////////////////////////////////////////////////////////


import java.util.*;

class Marvellous
{
    public int Add(int Brr[])
    {
        int iSum=0,iCnt=0;
        for(iCnt=0; iCnt<Brr.length; iCnt++)
        {
            iSum = iSum + Brr[iCnt];
        }
        return iSum;
    }

}


class Program7
{
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner (System.in);
        int iSize = 0, iCnt = 0, iRet=0;


        System.out.println("Enter Number of elements ");
        iSize = sobj.nextInt();

        int Arr[] = new int[iSize];
        System.out.println("Enter Numbers :");

        for(iCnt=0; iCnt<Arr.length; iCnt++)
        {
           Arr[iCnt] = sobj.nextInt(); 
        }

            Marvellous mobj = new Marvellous ();
            iRet = mobj.Add(Arr);
            System.out.println("Addition is : " +iRet);


    }
}