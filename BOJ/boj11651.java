import java.io.*;
import java.util.*;

/*
 * 11651 좌표 정렬하기2
 */
public class boj11651 {
    static int N;
    static List<Pos> poss = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        solve();
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" ");
            poss.add(new Pos(Integer.parseInt(input[0]), Integer.parseInt(input[1])));
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        StringBuffer sb = new StringBuffer();
        Collections.sort(poss);
        for (int i = 0; i < poss.size(); i++) {
            Pos pos = poss.get(i);
            sb.append(pos.x+" "+pos.y+"\n");
        }
        System.out.println(sb);
    }

    public static class Pos implements Comparable<Pos> {
        int x;
        int y;

        Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Pos o) {
            if (this.y == o.y) {
                return this.x - o.x;
            } else {
                return this.y - o.y;
            }
        }
    }
}
