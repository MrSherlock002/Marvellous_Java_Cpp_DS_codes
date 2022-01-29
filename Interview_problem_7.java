//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Friday (15/12/2021)
//  Interview problems on string in java
//  
//////////////////////////////////////////////////////////////////////////

import java.util.*;

class Marvellous
{
    public void CharFrequency(String s)
    {
        String s2 = s.trim().replaceAll(" ","");
        System.out.println("String after removing the whitespace is : "+s2);

        char Arr[] = s2.toCharArray();

        System.out.println("Character Array : ");
        for(char ch:Arr)
        {
            System.out.print(ch);
        }
    }
}

class Interview_problem_7
{
    public static void main( String str[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter String : ");
        String s = sobj.nextLine();
        
        Marvellous mobj = new Marvellous();

        mobj.CharFrequency(s);

        
    }
}