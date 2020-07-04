import java.util.*;

class Info implements Comparable<Info> {
    int cost;
    int x, y;
    int cov;
    public Info(int c, int x, int y, int cov) {
        this.cost = c;
        this.x = x;
        this.y = y;
        this.cov = cov;
    }
    @Override
    public int compareTo(Info info) {
        return info.cost >= this.cost ? 1 : -1;
    }
}
public class 경주로건설 {
    
    public static int solution(int[][] board) {
        int answer = 0;
        int[] dx = {1,0,-1,0};
        int[] dy = {0,1,0,-1};
        int[][][] map = new int[26][26][10];
        int cost=0,x,y,cov,nx,ny,n=board.length;
        PriorityQueue<Info> pq = new PriorityQueue<Info>();
        pq.add(new Info(0, 0, 0, 4));

        while (!pq.isEmpty()) {
            Info cur = pq.poll();
            cost = -cur.cost;
            x = cur.x; y = cur.y;
            cov = cur.cov;
            if (map[x][y][cov] == 1) continue;
            map[x][y][cov] = 1;
            if (x == n - 1 && y == n - 1) return cost-500;
            for (int i = 0; i < 4; i++) {
                nx = x + dx[i]; ny = y + dy[i];
                if (nx >= n || nx < 0 || ny >= n || ny < 0 || board[nx][ny] == 1) continue;
                pq.add(new Info(-cost-100-500*(cov != i ? 1 : 0), nx, ny, i));
            }
        }
        return answer;
    }

    public static void main(String[] args) {
        int[][] testmap = { { 0, 0, 0, 0, 0, 0 }, { 0, 1, 1, 1, 1, 0 }, { 0, 0, 1, 0, 0, 0 }, { 1, 0, 0, 1, 0, 1 },
                { 0, 1, 0, 0, 0, 1 }, { 0, 0, 0, 0, 0, 0 } };

        System.out.println(solution(testmap));
    }
}