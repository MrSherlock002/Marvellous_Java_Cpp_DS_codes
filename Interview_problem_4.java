//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Friday (15/12/2021)
//  Interview problems
//  
//////////////////////////////////////////////////////////////////////////

import java.util.*;

class Interview_problem_4
{
    public static void main( String str[])
    {
        int i =0,j=0;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter number of rows :");
        int rows = sobj.nextInt();

        System.out.println("Enter number of columns :");
        int columns = sobj.nextInt();

        int Arr[] [] = new int [rows][columns];

        System.out.println("please enter the elements :");

        for(i =0; i<Arr.length; i++)
        {
            for(j=0;j<Arr.length; j++)
            {
                System.out.print(Arr[j]);
            }
        }



    }

}