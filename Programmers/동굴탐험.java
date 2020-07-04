import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class 동굴탐험 {
    static int[] check; // 0: start, 1: nothing, 2: end
    static int[] visit; // 0: not visit, 1: visited
    static int[] firstVisit;
    static int[] afterVisit;
    static ArrayList<Integer>[] board;
    static Queue<Integer> q = new LinkedList<>();

    public static void dfs(int num) {
        if(check[num] == 2) {
            afterVisit[num] = 1;
            return;
        }
        
        if(visit[num] == 1) return;
        visit[num] = 1;
        
        for (int i = 0; i < afterVisit.length; i++) {
            System.out.print(visit[i]+" ");
        }
        System.out.println();

        if(check[num] == 0) {
            q.add(firstVisit[num]);
            check[num] = 1;
        }
        for (int i : board[num]) {
            if(visit[i] == 1) continue;
            dfs(i);
        }
    }

    public static boolean solution(int n, int[][] path, int[][] order) {
        //init
        check = new int[n];
        visit = new int[n];
        firstVisit = new int[n];
        afterVisit = new int[n];
        Arrays.fill(check, 1);
        board = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            board[i] = new ArrayList<Integer>();
        }

        //input
        for (int i = 0; i < path.length; i++) {
            board[path[i][0]].add(path[i][1]);
            board[path[i][1]].add(path[i][0]);
        }
        for (int i = 0; i < order.length; i++) {
            firstVisit[order[i][0]] = order[i][1];
            check[order[i][0]] = 0;//from
            check[order[i][1]] = 2;//to
        }
        //search
        dfs(0);
        System.out.print("===\n");

        while(!q.isEmpty()) {
            int x = q.poll();
            check[x] = 1;
            if(afterVisit[x] == 1) dfs(x);
        }
        for (int i = 0; i < n; i++) {
            if(visit[i] != 1) return false;
        }
        return true;
    }
    
    public static void main(String[] args) {
        int n = 9;
        int[][] test1path = {{0,1},{0,3},{0,7},{8,1},{3,6},{1,2},{4,7},{7,5}};
        int[][] test1order = {{8,5},{6,7},{4,1}};
        System.out.println(solution(n, test1path, test1order));
    }
}