import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Result {

    /*
     * Complete the 'findDay' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts following parameters:
     *  1. INTEGER month
     *  2. INTEGER day
     *  3. INTEGER year
     */

    public static String findDay(int month, int day, int year) {
        Calendar c = Calendar.getInstance();
        c.set(Calendar.MONTH,month-1);
        c.set(Calendar.DAY_OF_MONTH,day);
        c.set(Calendar.YEAR,year);
        return c.getDisplayName(Calendar.DAY_OF_WEEK, Calendar.LONG, Locale.UK).toUpperCase();
    }

}

public class Solution {