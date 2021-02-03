import java.io.*;
import java.util.*;

/*
 * 10814 나이순 정렬
 */
public class boj10814 {
    static int N;
    static List<Member> words = new ArrayList<>();

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
            words.add(new Member(i, Integer.parseInt(input[0]), input[1]));
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        StringBuffer sb = new StringBuffer();
        Collections.sort(words);
        for (int i = 0; i < words.size(); i++) {
            sb.append(words.get(i).age+" "+words.get(i).name+"\n");
        }
        System.out.println(sb);
    }

    public static class Member implements Comparable<Member> {
        int id;
        int age;
        String name;

        Member(int id, int age, String name) {
            this.id = id;
            this.age = age;
            this.name = name;
        }

        @Override
        public int compareTo(boj10814.Member o) {
            if (this.age == o.age) {
                return this.id - o.id;
            } else {
                return this.age - o.age;
            }
        }
    }
}
