/////////////////////////////////////////////////////////////////////
//
// Prasad R. Bhosale
// Wednesday   (13/10/2021)
// WAP to perform number is Amstrong number. 
//
/////////////////////////////////////////////////////////////////////


import java.util.*;



class Program5
{
    public static void main (String arg[])
    {
        Scanner sobj = new Scanner(System.in);
        int iValue = 0;
        boolean bRet = false;
        System.out.println("Enter Number : ");
        iValue = sobj.nextInt();

        Marvellous mobj = new Marvellous();

        bRet = mobj.CheckArmstrong(iValue);

        if(bRet==true)
        {
            System.out.println("It is Armstrong number ");
        }
        else
        {
            System.out.println("It is NOT Armstrong nummber ");
        }

    }
}




class Marvellous 
{
    
    public boolean CheckArmstrong(int iNo)
    {
        int iCnt =0,i=0, iDigCnt =0, iDigit=0,iPower=1,iSum=0;
        int ilen=0;
        boolean bFlag = false;
        int iTemp=iNo;

        while(iNo<0)
        {
            iNo = -iNo;
        }

        while(iTemp!=0)
        {
            iDigCnt++;
            iTemp = iTemp/10;
        }

        iTemp = iNo;
        while(iTemp!=0)
        {
            iDigit = iTemp %10;
            for(iCnt=1; iCnt<=iDigCnt; iCnt++)
            {
                iPower = iPower * iDigit;
            }
            iSum = iSum + iPower;
            iPower =1;
            iTemp = iTemp /10;
        }
        if(iNo==iSum)
        {
            bFlag=true;
        }
        return bFlag;
    } 
}
