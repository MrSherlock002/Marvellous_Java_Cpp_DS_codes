//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Friday (15/12/2021)
//  Interview problems on string in java
//  Accept string from user and return frequency of each word.(Case Sensitive)
//  
//////////////////////////////////////////////////////////////////////////


import java.util.*;

class Marvellous
{
    public void WordFrequency(String s)
    {
        String s2= s.trim().replaceAll("[ ]{2,}"," ");

        String Arr [] = s2.split(" ");

        HashMap <String, Integer> hobj = new HashMap <String,Integer>();

        for(String str: Arr)
        {
            if(hobj.containsKey(str))
            {
                hobj.put(str,(hobj.get(str))+1);
            }
            else 
            {
                hobj.put(str,1);
            }
        }   
            System.out.println("Frequency of each word : ");
            System.out.println(hobj);
    }
}

class Interview_problem_9
{
    public static void main( String str[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter String : ");
        String s = sobj.nextLine();
        
        Marvellous mobj = new Marvellous();

        mobj.WordFrequency(s);
    }
}