import java.util.*;
import java.io.*;
import java.lang.Math;

class Solution{

    public static void main(String []argh){
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        for(int i=0;i<t;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();
            int answer = a;
            for (int j = 0; j < n; j++){
                answer += b * Math.pow(2, j);
                System.out.printf("%d ", answer); 
            }
            System.out.printf("%n");
        }
        in.close();
    }
}