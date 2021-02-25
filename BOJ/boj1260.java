import java.io.*;
import java.util.*;

/*
 * 1260 DFS와 BFS
 */
public class boj1260 {
    static StringBuffer sb = new StringBuffer();
    static int N, M, V;
    static List<Integer>[] board;
    static boolean[] visit;
    static Queue<Integer> q = new LinkedList<>();

    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
        solve();
        System.out.println(sb);
    }

    public static void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        V = Integer.parseInt(input[2]);
        visit = new boolean[N+1];
        board = new ArrayList[N+1];
        for (int i = 1; i <= N; i++) {
            board[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < M; i++) {
            input = br.readLine().split(" ");
            int from = Integer.parseInt(input[0]);
            int to = Integer.parseInt(input[1]);
            board[from].add(to);
            board[to].add(from);
        }
        for (int i = 1; i <= N; i++) {
            Collections.sort(board[i]);
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        Arrays.fill(visit, false);
        dfs(V);
        Arrays.fill(visit, false);
        sb.append("\n");
        bfs();
    }

    public static void dfs(int cur) {
        if (visit[cur]) return;
        visit[cur] = true;
        sb.append(cur+" ");
        for (int i = 0; i < board[cur].size(); i++) {
            int nxt = board[cur].get(i);
            dfs(nxt);
        }
    }

    public static void bfs() {
        visit[V] = true;
        q.add(V);
        while (!q.isEmpty()) {
            int cur = q.poll();
            sb.append(cur+" ");
            for (int i = 0; i < board[cur].size(); i++) {
                int nxt = board[cur].get(i);
                if (!visit[nxt]) {
                    visit[nxt] = true;
                    q.add(nxt);
                }
            }
        }
    }
}
