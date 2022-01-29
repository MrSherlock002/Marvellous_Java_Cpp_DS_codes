//////////////////////////////////////////////////////////////////////////
//
//  Prasad R. Bhosale
//  Wednesday (01/12/2021) 
//  Making our own Linked List in JAVA.
//  (Singly circular Linked List)
//  
//////////////////////////////////////////////////////////////////////////


import java.util.*;

class Node
{
    public int data;
    public Node next;
}

class SinglyCL
{
    private Node first;
    private int size;

    public SinglyCL()
    {
    this.first = null;
    this.size=0;
    }

    public void InsertFirst(int no)
    {
        Node newn = null;
        newn = new Node();

        newn.data = no;
        newn.next = null;

        if(first==null)
        {
            first = newn;
        }
        else 
        {
            newn.next = first;
            first = newn;
        }
        this.size++;
    }

    public void InsertLast(int no)
    {
        Node newn = null;
        newn = new Node();

        newn.data = no;
        newn.next = null;

        if(first ==null)
        {
            first = newn;
        }
        else 
        {
            Node temp = first;
            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
        this.size++;
    }


    public void DeleteFirst()
    {
        if(size ==0)
        {
            return;
        }
        else if(size ==1)
        {
            first = null;
            this.size--;
        }
        else
        {
            first = first.next;
        }
        this.size--;
    }   


    public void DeleteLast()
    {
        if(size==0)
        {
            return;
        }
        else if(size==1)
        {
            first=null;
        }
        else
        {
            Node temp = first;
            while(temp.next.next!=null)
            {
                temp = temp.next;
            }
            temp.next = null;
        }
        this.size--;
    }

    public void InsertAtPos(int no,int iPos)
    {
        if((iPos<0)||(iPos>size+1))
        {
            return;
        }
        else if(iPos==1)
        {
            InsertFirst(no);
        }
        else if(iPos==size+1)
        {
            InsertLast(no);
        }
        else
        {
            Node newn = new Node();
            newn.data = no;
            newn.next = null;

            Node temp = first;

            for(int i=1; i<iPos-1; i++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next = newn;
        }
        this.size++;
    }

    public void DeleteAtPos(int iPos)
    {

        if((iPos<0)||(iPos>size+1))
        {
            return;
        }
        else if(iPos==1)
        {
            DeleteFirst();
        }
        else if(iPos==size+1)
        {
            DeleteLast();
        }
        else
        {
            Node temp = first;

            for(int i=1;i<iPos-1; i++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next;
            this.size--;
        }
    }

    public void Display()
    {
        Node temp = first;

        System.out.println("Elements from linked list : ");
        while(temp!=null)
        {
            System.out.println("|"+temp.data+"|->");
            temp = temp.next;
        }
        System.out.println("null\n");
    }

    public int Count()
    {
        return this.size;
    }
}



class A_10
{
    public static void main(String str[])
    {
        SinglyCL obj = new SinglyCL();

    int iChoice =1, value =0, iRet=0,pos=0;

        while (iChoice!=0)
        {
            System.out.println("_______________________________________________\n");
            System.out.println("Enter the desired operation that you want to perform on linked list : ");
            System.out.println("1.Insert the node at first position");
            System.out.println("2.Insert the node at last position");
            System.out.println("3.Insert the node at desired position");
            System.out.println("4.Delete the first node");
            System.out.println("5.Delete the last node");
            System.out.println("6.Delete the node at desired position");
            System.out.println("7.Display contents of Linked List : ");
            System.out.println("8.Count the number of nodes from Linked List : ");
            System.out.println("0.Terminate the Application ");
            System.out.println("_______________________________________________\n");
            
            Scanner sobj = new Scanner(System.in);

            iChoice = sobj.nextInt();

            switch(iChoice)
            {
                case 1 :
                    System.out.println("Enter the data to insert : ");
                    value = sobj.nextInt();
                    obj.InsertFirst(value);
                    break;
                
                case 2 :
                    System.out.println("Enter the data to insert : ");
                    value = sobj.nextInt();
                    obj.InsertLast(value);
                    break;
                
                case 3 :
                    System.out.println("Enter the data to insert : ");
                    value = sobj.nextInt();
                    System.out.println("Enter the position : ");
                    pos = sobj.nextInt();
                    obj.InsertAtPos(value,pos);
                    break;
                
                case 4 :
                    obj.DeleteFirst();
                    break;
                
                case 5 :
                    obj.DeleteLast();
                    break;

                case 6 :
                    System.out.println("Enter the data to insert : ");
                    pos = sobj.nextInt();
                    obj.DeleteAtPos(pos);  
                    break;

                case 7 :
                    System.out.println("Element of linked list are : ");
                    obj.Display();
                    break;

                case 8:
                    iRet = obj.Count();
                    System.out.println("Element of linked list are : "+iRet);
                    break;

                case 0:
                        System.out.println("Thank for using Marvellous Linked List");
                        break;
                        
                default:
                        System.out.println("Please enter proper choice ");
                        break;
            }   
        }
    }
}
