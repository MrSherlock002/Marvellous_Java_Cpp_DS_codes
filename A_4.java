//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Monday (29/11/2021) 
//  Concepts of Searching and sorting
//  Binary Search   (Please enter array data in sorted order.)
//  
//////////////////////////////////////////////////////////////////////////

import java.util.*;

class Searching
{
    public boolean BinarySearch (int Arr[],int no)
    {
        int start,end,mid;
        start = 0;
        end = Arr.length-1;
        mid = ((start+ end)/2);
        while(start<=end)
        {
        if(Arr[mid] == no)
            {
                break;
            }

        else if(Arr[mid]<no)
            {
                start = mid+1;
            }
        else if(Arr[mid]>no)
            {
                end = mid-1;
            }
            mid  =(start+end)/2;
        }
        if(Arr[mid]==no)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
}

class A_4
{
    public static void main(String arr[])
    {
        Scanner sobj = new Scanner(System.in);
        System.out.println("Enter the size of the array : ");
        int size = sobj.nextInt();

        int Arr[] = new int[size];

        System.out.println("Enter the elements in sorted order: ");

        for(int i=0; i<Arr.length; i++)
        {
            Arr[i] = sobj.nextInt();
        }

        System.out.println("Enter the element to search : ");
        int value = sobj.nextInt();

        Searching obj = new Searching();

        boolean bret = obj.BinarySearch(Arr,value);

        if(bret == true)
        {
            System.out.println("Element is present");
        }
        else
        {
            System.out.println("Element is NOT present");
        }
    }
}