import java.util.*;
public class binarysearch{
    public static void main(String args[]) {
        System.out.println("ENTER THE LENGTH OF ARRAY");
        int n;
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        System.out.println("ENTER ELEMENTS OF ARRAY");
        int [] ar=new int[n];
        for (int i = 0; i < n; i++) {
            ar[i]=sc.nextInt();
        }
        //BINARY SEARCH HAPPENS ON SORTED ARRAYS
        Arrays.sort(ar);
        int left=0;
        int right=n-1;
        int flag=0;//FOR DETERMINING THAT NUMBER IS FOUND OR NOT
        System.out.println("ENTER THE NUMBER TO SEARCH");


        int num=sc.nextInt();
        while(left <= right)
        {
            int middle=(left+right)/2;
            // If num is smaller than middle, then
            if(num < ar[middle])
            {
                right=middle-1;
            }
            // If num is greater than mid, then
            else if(num > ar[middle])
            {
                left=middle+1;
            }
            // If num is equal to mid, then
            else
            {
                //POINTING THAT NUM IS FOUND IN THE ARRAY
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            System.out.println("NUMBER IS FOUND");
        }
        else
        System.out.println("NUMBER NOT FOUND");

    }
}