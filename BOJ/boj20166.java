import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
/*
 * 20166 문자열 지옥에 빠진 호석
 */
public class boj20166 {
    static int[] dx = {0,0,-1,-1,-1,1,1,1};
    static int[] dy = {1,-1,-1,0,1,-1,0,1};
    static Map<String, Integer> matchStr = new LinkedHashMap<>();
    static int N, M, K;
    static String[] hsStr;

    static void dfs(int x, int y, String current, int len) {
        if (matchStr.containsKey(current)) {
            matchStr.put(current, matchStr.get(current) + 1);
        } else {
            matchStr.put(current, 1);
        }
        if (len == 5) return;
        for (int i = 0; i < 8; i++) {
            int nx = (x + dx[i] + N) % N;
            int ny = (y + dy[i] + M) % M;
            dfs(nx, ny, current + hsStr[nx].charAt(ny), len+1);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        //input
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        K = Integer.parseInt(input[2]);
        hsStr = new String[N];
        for (int i = 0; i < N; i++) {
            hsStr[i] = br.readLine();
        }
        //search
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                dfs(i, j, Character.toString(hsStr[i].charAt(j)), 1);
            }
        }
        //result
        for (int i = 0; i < K; i++) {
            String godStr = br.readLine();
            if (matchStr.containsKey(godStr)) {
                sb.append(matchStr.get(godStr)+"\n");
            } else {
                sb.append("0\n");
            }
        }
        System.out.println(sb);
        br.close();
    }
}