/////////////////////////////////////////////////////////////////////
//
// Prasad R. Bhosale
// Wednesday   (13/10/2021)
// WAP to perform number is prime or not. 
//
/////////////////////////////////////////////////////////////////////


import java.util.*;



class Program4
{
    public static void main (String arg[])
    {
        Scanner sobj = new Scanner(System.in);
        int iValue = 0;
        boolean bRet = false;
        System.out.println("Enter Number : ");
        iValue = sobj.nextInt();

        Marvellous mobj = new Marvellous();

        bRet = mobj.CheckPrime(iValue);

        if(bRet==true)
        {
            System.out.println("It is Prime number ");
        }
        else
        {
            System.out.println("It is NOT prime nummber ");
        }

    }
}




class Marvellous 
{
    

    public boolean CheckPrime(int iNo)
    {
        int iCnt =0;
        boolean bFlag = true;
        for(iCnt=2; iCnt <=iNo/2; iCnt++ )
        {
            if((iNo%iCnt)==0)
            {   
                bFlag = false;
                break;
            }
        }
        return bFlag;
    } 
}
