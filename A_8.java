//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Wednesday (01/12/2021) 
//  Concepts of Searching and sorting
//  Insertion sort 
//  
//////////////////////////////////////////////////////////////////////////

import java.util.*;

class Sorting
{
    public void InsertionSort(int Arr[])
    {
        int i=0, j=0,key=0;
        int size = Arr.length;

        for(i=0;i<size; i++)
        {
            key = Arr[i];
            for(j=i-1;(j>=0 && (Arr[j]>key));j--)
            {
                Arr[j+1] = Arr[j];
            }
            Arr[j+1] = key;
        }

    }
}

class A_8
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

        obj.InsertionSort(Arr);

        System.out.println("Data after Sorting :");
        for(int i=0;i<arr.length;i++)
        {
            Arr[i] = sobj.nextInt();
        }
        obj.InsertionSort(Arr);

        //System.out.println("Data after sorting :");
        for(int i=0; i<Arr.length; i++)
        {
            System.out.print(Arr[i]+" ");
        }

        
    }
}