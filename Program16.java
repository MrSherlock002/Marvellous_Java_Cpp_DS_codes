/////////////////////////////////////////////////////////////////////
//
// Prasad R. Bhosale
// Monday   (18/10/2021)
// WAP to understand concept of string in JAVA.
// Program to reverse the string.
/////////////////////////////////////////////////////////////////////

import java.util.*;

class Marvellous extends StringX
{
    public String reverseX()
    {
        char Arr[] = str.toCharArray();
        int iStart =0, iEnd=Arr.length-1;
        char temp;
        while(iStart<iEnd)
        {
            temp =Arr[iStart];
            Arr[iStart] = Arr[iEnd];
            Arr[iEnd] = temp;
            iStart++;
            iEnd--;
        }
        return new String(Arr); 
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


class Program16
{
    public static void main(String arg[])
    {
       Marvellous mobj = new Marvellous();
       mobj.Accept();
       mobj.Display();

       String s = mobj.reverseX();
       System.out.println("Reverse String is : "+s);
        
    }
}