import java.io.*;
import java.util.*;

/*
 * 2910 빈도 정렬
 */
class Info implements Comparable<Info> {
    int number;
    int count;

    Info(int number, int count) {
        this.number = number;
        this.count = count;
    }

    @Override
    public int compareTo(Info o) {
        if (this.count < o.count) {
            return 1;
        } else if (this.count == o.count) {
            return 0;
        }
        return -1;
    }
}

public class boj2910 {

    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        Scanner sc = new Scanner(System.in);
        //TO-DO
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int c = Integer.parseInt(input[1]);
        String[] numbers = br.readLine().split(" ");
        Map<Integer, Integer> check = new LinkedHashMap<>();
        for (int i = 0; i < n; i++) {
            int key = Integer.parseInt(numbers[i]);
            if (check.containsKey(key)) {
                check.put(key, check.get(key)+1);
            } else {
                check.put(key, 1);
            }
        }
        List<Info> list = new ArrayList<>();
        for (Integer key : check.keySet()) {
            list.add(new Info(key, check.get(key)));
        }
        Collections.sort(list);
        for (int i = 0; i < list.size(); i++) {
            for (int j = 0; j < list.get(i).count; j++) {
                System.out.print(list.get(i).number+" ");
            }
        }
        //END
        sc.close();
		br.close();
    }
}
