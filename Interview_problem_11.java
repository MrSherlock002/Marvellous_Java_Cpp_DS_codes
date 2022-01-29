//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Friday (15/12/2021)
//  Interview problems on string in java
//  Accept string from user and return word which occures the most.(Case Sensitive)
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
        Set <String > sobj = hobj.keySet();

        int iMax = 0;
        String output = null;

        for(String word : sobj)
        {
            if(hobj.get(word)>iMax)
            {
                output = word;
                iMax = hobj.get(word);
            }
        }

        System.out.println(output+" word occures maximum number of times ie :"+iMax);
    }
}

class Interview_problem_11
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