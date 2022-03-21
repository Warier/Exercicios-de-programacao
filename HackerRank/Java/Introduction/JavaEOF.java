import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        String line;
        Scanner sc = new Scanner(System.in);
        int i = 1;
        while(sc.hasNext()){
            line = sc.nextLine();
            System.out.printf("%d %s%n", i++, line);
        }
    }
}