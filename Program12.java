/////////////////////////////////////////////////////////////////////
//
// Prasad R. Bhosale
// Monday   (18/10/2021)
// WAP to understand concept of string in JAVA.
//
/////////////////////////////////////////////////////////////////////

import java.util.*;

class Marvellous
{
    public void Display (String Data)
    {
        System.out.println("Welcome :"+Data);
    }
}


class Program12
{
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner (System.in);
        String str;

        System.out.println("Enter your name :");
        str = sobj.nextLine();

        Marvellous mobj = new Marvellous();
        mobj.Display(str);
        sobj.close();
    }
}