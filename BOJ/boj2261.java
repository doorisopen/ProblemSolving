import java.io.*;
import java.util.*;

/*
 * 2261 가장 가까운 두 점
 */
public class boj2261 {
    static StringBuffer sb = new StringBuffer();
    static int N;
    static List<Point> points = new ArrayList<>();

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

        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" ");
            int x = Integer.parseInt(input[0]);
            int y = Integer.parseInt(input[1]);
            points.add(new Point(x, y));
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        Collections.sort(points);
        sb.append(proximate(points, 0, N-1));
    }

    public static int proximate(List<Point> p1, int x, int y) {
        int n = y - x + 1;
        if (n <= 3) {
            return brute(p1, x, y);
        }
        int mid = (x+y)/2;
        int ret = Math.min(proximate(p1, x, mid), proximate(p1, mid+1, y));
        List<Point> p2 = new ArrayList<>();
        for (int i = x; i <= y; i++) {
            int cur = p1.get(i).x - p1.get(mid).x;
            if (cur*cur < ret){
                p2.add(p1.get(i));
            }
        }
        Collections.sort(p2, new Comparator<Point>(){ // y좌표순 정렬
			@Override
			public int compare(Point o1, Point o2) {
				return o1.y-o2.y;
			}
        });

        int m = p2.size();
        for (int i = 0; i < m-1; i++) {
            for (int j = i+1; j < m; j++) {
                int cur = p2.get(j).y - p2.get(i).y;
                if (cur*cur < ret) {
                    int dist = calcDist(p2.get(i), p2.get(j));
                    if (dist < ret) {
                        ret = dist;
                    }
                } else { // y좌표순 정렬해서 ret보다 크면 break
                    break;
                }
            }
        }
        return ret;
    }

    public static int brute(List<Point> p, int x, int y) {
        int ret = -1;
        for (int i = x; i <= y-1; i++) {
            for (int j = i+1; j <= y; j++) {
                int dist = calcDist(p.get(i), p.get(j));
                if (ret == -1 || ret > dist) {
                    ret = dist;
                }
            }
        }
        return ret;
    }

    public static int calcDist(Point p1, Point p2) {
        return (p1.x-p2.x) * (p1.x-p2.x) + (p1.y-p2.y) * (p1.y-p2.y);
    }

    static class Point implements Comparable<Point> {
        int x;
        int y;
        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    
        @Override
        public int compareTo(Point p) {
            if (this.x == p.x) {
                return this.y - p.y;
            }
            return this.x - p.x;
        }
    }
}
