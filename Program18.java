/////////////////////////////////////////////////////////////////////
//
// Prasad R. Bhosale
// Monday   (18/10/2021)
// WAP to understand concept of string in JAVA.
// Program to reverse the string. (Using valueof()).
/////////////////////////////////////////////////////////////////////

import java.util.*;

class Marvellous extends StringX
{
    public boolean CheckPallindrome()
    {
        char Arr[] = str.toCharArray();
        int iCnt=0;
        int iStart =0, iEnd=Arr.length-1;
        char temp;
        while(iStart<iEnd)
        {
            if(iStart ==iEnd)
            {
                iStart++;
                iEnd--;
                iCnt++;
            }
            else
            {
                break;
            }
        }
        if(iCnt>=(Arr.length/2))
        {
            return true;
        }
        return false;
        }
        
    }


class StringX
{
    public String str;
    public void Accept()
    {
        Scanner sobj = new Scanner(System.in);
        System.out.println("Enter String : ");
        str = sobj.nextLine();

    }

    public void Display()
    {
        System.out.println("String is : "+str);
    }

}


class Program18
{
    public static void main(String arg[])
    {
       Marvellous mobj = new Marvellous();
       mobj.Accept();
       mobj.Display();
       boolean bRet =false;
       bRet = mobj.CheckPallindrome();

       if(bRet==true)
       {
           System.out.println("Number is Pallindrome");
       }
       else
       {
        System.out.println("Number is NOT Pallindrome");
       }

          
    }
}