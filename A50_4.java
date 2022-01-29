import java.io.FileOutputStream;
import java.util.Scanner;
public class A50_4 {
  public static void main(String args[]) {
    try {
      Scanner sc = new Scanner(System. in ); //object of Scanner class  
      System.out.print("Enter the file name with specific location: ");
      String name = sc.nextLine(); //variable name to store the file name  
      FileOutputStream fos = new FileOutputStream(name, true);
      // true for append mode  
      System.out.print("Enter file content: ");
      String str = sc.nextLine() + "\n";
      //str stores the string which we have entered  
      byte[] b = str.getBytes(); //converts string into bytes  
      fos.write(b); //writes bytes into file  
      fos.close(); //close the file  
      System.out.println("The file has been saved on the given path.");
    }
    catch(Exception e) {
      System.out.println("Exception Occurred:");
      e.printStackTrace();
    }
  }
}