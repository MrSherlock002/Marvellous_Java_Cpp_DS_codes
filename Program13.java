/////////////////////////////////////////////////////////////////////
//
// Prasad R. Bhosale
// Monday   (18/10/2021)
// WAP to understand concept of string in JAVA.
//
/////////////////////////////////////////////////////////////////////

import java.util.*;

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


class Program13
{
    public static void main(String arg[])
    {
       StringX sobj = new StringX();
       sobj.Accept();
       sobj.Display();
    }
}