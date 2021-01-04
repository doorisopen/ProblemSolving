/*
 * 1254 팰린드롬 만들기
 */
import java.io.*;
import java.util.*;

public class boj1254 {
    static String str;

    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        int len = str.length();
        int answer = 0;
        for (int i = 0; i < len; i++) {
            if (isPalin(i, len-1)) {
                answer = len + i;
                break;
            }
        }
        System.out.println(answer);
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        Scanner sc = new Scanner(System.in);
        //TO-DO
        str = sc.nextLine();
        sc.close();
		br.close();
    }

    public static boolean isPalin(int i, int len) {
        while (i <= len) {
            if (str.charAt(i) != str.charAt(len)) return false;
            i++; len--;
        }
        return true;
    }
}
