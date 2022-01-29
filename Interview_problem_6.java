//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Friday (15/12/2021)
//  Interview problems on string in java
//  
//////////////////////////////////////////////////////////////////////////

import java.util.*;

class Interview_problem_6
{
    public static void main( String str[])
    {

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter String : ");
        String s = sobj.nextLine();

        // System.out.println("Entered string is : "+s);
        // System.out.println("Length of string is = "+s.length());

        // String s1 = s.trim();

        // System.out.println(("New String is : "+s1));
        // System.out.println(("New length of string : "+s1.length()));

        // String s2 = s.replace(" ","");
        // System.out.println(("New String is : "+s2));
        // System.out.println(("New length of string : "+s2.length()));

        String s3 = (s.trim().replaceAll("[ ]{2,}"," "));
        String Arr[] = s3.split(" ");

        System.out.println("New String is = "+s3);
        System.out.println("New String length = "+s3.length());


        for(int i=0; i<Arr.length; i++)
        {
            System.out.println(Arr[i]);
        }
        System.out.println("New String length = "+s3.length());

        String s4[] = s3.split(" ");
        System.out.println("Number of words : "+ s4.length);

        // int iMax = Arr[0].length();
        
        // String str = s;
        // for(str: Arr)
        // {
        //     if(str.length()>iMax)
        //     {
        //         iMax = str.length();
        //         output = str;
        //     }
        // }
        // System.out.println("Largest value = "+str +"with word length"+iMax);
    }
}