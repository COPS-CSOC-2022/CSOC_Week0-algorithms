import java.util.*;
public class linear_search {
    public static void main(String args []) {
        System.out.println("ENTER THE LENGTH OF ARRAY");
        int n;
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        System.out.println("ENTER ELEMENTS OF ARRAY");
        int [] ar=new int[n];
        for (int i = 0; i < n; i++) {
            ar[i]=sc.nextInt();
        }
        System.out.println("ENTER THE NUMBER TO SEARCH");
        int num=sc.nextInt();
        //LINEARLY TRAVERSING THE ARRAY TILL THE NUMBER IS FOUND
        for (int i = 0; i < n; i++) {
            if(num==ar[i])
            {
                System.out.println("NUMBER IS FOUND");
                break;
            }
            else if(i==n-1)
            {
                System.out.println("NUMBER IS NOT FOUND");
            }
        }
    }
    
}
