import java.io.*;
import java.util.*;

/*
 * 1436 영화감독 숌
 */
public class boj1436 {
    static int N;
    
    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        solve();
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        Scanner sc = new Scanner(System.in);
        //TO-DO
        N = Integer.parseInt(br.readLine());
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        List<String> ends = new ArrayList<>();
        int end = 666;
        while (ends.size() < N) {
            String temp = Integer.toString(end);
            for (int i = 0; i+2 < temp.length(); i++) {
                if (temp.charAt(i) == '6') {
                    if ((temp.charAt(i) == temp.charAt(i+1)) && 
                    (temp.charAt(i) == temp.charAt(i+2))) {
                        ends.add(temp);
                        break;
                    }
                }
            }
            end++;
        }
        System.out.println(ends.get(N-1));
    }
}
