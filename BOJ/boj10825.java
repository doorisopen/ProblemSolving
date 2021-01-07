import java.io.*;
import java.util.*;

/*
 * 10825 국영수
 */
class Info implements Comparable<Info> {
    String name;
    int korea;
    int english;
    int math;

    Info(String name, int korea, int english, int math) {
        this.name = name;
        this.korea = korea;
        this.english = english;
        this.math = math;
    }

    @Override
    public int compareTo(Info o) {
        if (o.korea > this.korea) {//내림차순
            return 1;
        } else if (o.korea == this.korea) {
            if (o.english < this.english) {//오름차순
                return 1;
            } else if (o.english == this.english) {
                if (o.math > this.math) {//내림차순
                    return 1;
                } else if (o.math == this.math) {//사전순
                    return this.name.compareTo(o.name);
                }
            }
        }
        return -1;
    }
}

public class boj10825 {

    static int N;
    static List<Info> students = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        Collections.sort(students);
        for (int i = 0; i < N; i++) {
            System.out.println(students.get(i).name);
        }
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        Scanner sc = new Scanner(System.in);
        //TO-DO
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" ");
            students.add(new Info(input[0], Integer.parseInt(input[1]), Integer.parseInt(input[2]), Integer.parseInt(input[3])));
        }
        //END
        sc.close();
		br.close();
    }
}
