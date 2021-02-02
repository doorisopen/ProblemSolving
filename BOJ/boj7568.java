import java.io.*;
import java.util.*;

/*
 * 7568 덩치
 */
public class boj7568 {
    static int N;
    static String[][] people;
    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        search();
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        Scanner sc = new Scanner(System.in);
        //TO-DO
        N = Integer.parseInt(br.readLine());
        people = new String[N][2];
        for (int i = 0; i < N; i++) {
            people[i] = br.readLine().split(" ");
        }
        //END
        sc.close();
		br.close();
    }

    public static void search() {
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < people.length; i++) {
            int weight = Integer.parseInt(people[i][0]);
            int height = Integer.parseInt(people[i][1]);
            int k = 0;//더 큰 덩치 수
            for (int j = 0; j < people.length; j++) {
                int otherWeight = Integer.parseInt(people[j][0]);
                int otherHeight = Integer.parseInt(people[j][1]);
                if (i != j) {
                    if ((weight < otherWeight) && (height < otherHeight)) {
                        k++;
                    }
                }
            }
            result.add(k+1);//본인 등수
        }

        for (int i = 0; i < result.size(); i++) {
            System.out.print(result.get(i)+" ");
        }
    }
}
