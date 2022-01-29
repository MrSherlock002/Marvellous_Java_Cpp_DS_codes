//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Wednesday (01/12/2021) 
//  Concepts of Searching and sorting
//  Selection sort 
//  
//////////////////////////////////////////////////////////////////////////

import java.util.*;

class Sorting
{
    public void SelectionSort(int Arr[])
    {
        int i=0,j=0,minindex=0,temp=0;
        int size=Arr.length;

        for(i=0;i<size;i++)
        {
            minindex=i;
            for(j=i;j<size; j++)
            {
                if(Arr[minindex]>Arr[j])
                {
                    minindex=j;
                }
            }
            temp = Arr[i];
            Arr[i] = Arr[minindex];
            Arr[minindex] = temp;
            
        }
        System.out.println("Data after pass : "+i);
            for(int k=0;k<size;k++)
            {
                System.out.print(Arr[k]+" ");
            }
            System.out.println();

    }
}

class A_7
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

        obj.SelectionSort(Arr);

        System.out.println("Data after Sorting :");
        for(int i=0;i<arr.length;i++)
        {
            Arr[i] = sobj.nextInt();
        }
        obj.SelectionSort(Arr);

        //System.out.println("Data after sorting :");
        for(int i=0; i<Arr.length; i++)
        {
            System.out.print(Arr[i]+" ");
        }

        
    }
}