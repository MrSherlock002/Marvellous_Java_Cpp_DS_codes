//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Wednesday (01/12/2021) 
//  Concepts of Searching and sorting
//  Bubble sort 
//  
//////////////////////////////////////////////////////////////////////////

import java.util.*;

class Sorting
{
    public void BubbleSort(int Arr[])
    {
        int pass=0,j=0,temp=0;
        boolean flag =false;
        int size=Arr.length;
        for(pass=0;pass<size; pass++)
        {
            flag = false;
            for(j=0;j<size-pass-1;j++)
            {
                
                if(Arr[j]>Arr[j+1])
                {
                    flag = true;
                    temp = Arr[j];
                    Arr[j] = Arr[j+1];
                    Arr[j+1] = temp;
                }
            }
            if(flag==false)
                break;
            System.out.println("Data after pass : "+ pass);
            for(int i=0; i<Arr.length; i++)
            {
                System.out.print(Arr[i]+" ");
            }
            System.out.println();
        }
    }
}

class A_6
{
    public static void main(String arr[])
    {
        Scanner sobj = new Scanner(System.in);
        System.out.println("Enter the size of the array : ");
        int size = sobj.nextInt();

        int Arr[] = new int[size];

        System.out.println("Enter the elements : ");

        for(int i=0; i<Arr.length; i++)
        {
            Arr[i] = sobj.nextInt();
        }

        Sorting obj = new Sorting();

        obj.BubbleSort(Arr);

        System.out.println("Data after Sorting :");
        for(int i=0;i<arr.length;i++)
        {
            Arr[i] = sobj.nextInt();
        }
        obj.BubbleSort(Arr);

        //System.out.println("Data after sorting :");
        for(int i=0; i<Arr.length; i++)
        {
            System.out.print(Arr[i]+" ");
        }

        
    }
}