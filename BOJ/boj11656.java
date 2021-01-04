/*
 * 11656 접미사 배열
 */
import java.io.*;
import java.util.*;

public class boj11656 {
    static String str;
    static String[] suffixs;
    
    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        Scanner sc = new Scanner(System.in);
        //TO-DO
        str = br.readLine();
        sc.close();
		br.close();
    }

    public static void main(String[] args) throws Exception {
        init();
        int len = str.length();
        suffixs = new String[len];
        for (int i = 0; i < len; i++) {
            suffixs[i] = str.substring(i);
        }
        Arrays.sort(suffixs);
        for (int i = 0; i < len; i++) {
            System.out.println(suffixs[i]);
        }
    }
}