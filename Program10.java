/////////////////////////////////////////////////////////////////////
//
// Prasad R. Bhosale
// Monday   (18/10/2021)
// WAP to understand concept of inheritance in JAVA.
// Find average of numbers.
//
/////////////////////////////////////////////////////////////////////

//package MarvellousNumbers;
import java.util.*;


class ArrayX
{
    public int Arr[];

    public ArrayX (int iSize)
    {
        Arr = new int [iSize];
    }
    public void Accept()
    {
        Scanner sobj = new Scanner(System.in);
        int iCnt=0;
        System.out.println("Enter elements :");

        for(iCnt=0; iCnt<Arr.length; iCnt++)
        {
            Arr[iCnt] = sobj.nextInt();
        }
    }
    public void Display()
    {
        int iCnt=0;

        System.out.println("Elements are :");

        for(iCnt=0; iCnt<Arr.length; iCnt++)
        {
            System.out.println(Arr[iCnt]);
        }
    }

}

class Marvellous extends ArrayX
{
    public Marvellous(int iValue)
    {
        super(iValue);
    }
    public float Average()
    {
        int iSum =0,iCnt=0;

        for(iCnt=0; iCnt<Arr.length; iCnt++)
        {
            iSum = iSum + Arr[iCnt];
        }
        return (iSum/Arr.length);
    }
}


class Program10
{
  public static void main(String arg[])
    {
        Scanner sobj = new Scanner(System.in);

        int iLength =0;
        float fRet=0.0f;

        System.out.println("Enter the number of elements :");
        iLength = sobj.nextInt();

        Marvellous mobj = new Marvellous(iLength);
        mobj.Accept();
        mobj.Display();
        fRet = mobj.Average();
        System.out.println("Average is : "+fRet);

    }
}