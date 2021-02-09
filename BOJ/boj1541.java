import java.io.*;
import java.util.*;

/*
 * 1541 잃어버린 괄호
 */
public class boj1541 {
    static StringBuffer sb = new StringBuffer();
    static String str;
    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        solve();
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        str = br.readLine();
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        int answer = 0;
        String[] temp = str.split("-");
        for (int i = 0; i < temp.length; i++) {
            int num = 0;
            String[] temp2 = temp[i].split("\\+");
            for (int j = 0; j < temp2.length; j++) {
                num += Integer.parseInt(temp2[j]);
            }
            if (i == 0) {
                answer += num;
            } else {
                answer -= num;
            }
        }
        System.out.println(answer);
    }
}
