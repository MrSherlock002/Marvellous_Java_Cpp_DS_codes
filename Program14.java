/////////////////////////////////////////////////////////////////////
//
// Prasad R. Bhosale
// Monday   (18/10/2021)
// WAP to understand concept of string in JAVA.
// program to count vowels.
/////////////////////////////////////////////////////////////////////

import java.util.*;

class Marvellous extends StringX
{
    public int CountVowels()
    {
        int iCnt=0, i=0;
        char Arr[] = str.toCharArray();

        for(i=0; i<Arr.length; i++)
        {
            if((Arr[i]=='a') || (Arr[i]=='A') || (Arr[i]=='e')|| (Arr[i]=='E') || (Arr[i]=='i') || (Arr[i]=='I') || (Arr[i]=='o') || (Arr[i]=='O') || (Arr[i]=='u') ||(Arr[i]=='U'))
            {
                iCnt++;
            }
            
        }
        return iCnt;
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


class Program14
{
    public static void main(String arg[])
    {
       Marvellous mobj = new Marvellous();
       int iRet =0;
       mobj.Accept();
       mobj.Display();
        
       iRet = mobj.CountVowels();
       System.out.println("Number of vowels are :"+iRet);
    }
}