import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

/*
 * 1181 단어 정렬
 */
public class boj1181 {
    static int N;
    static List<String> words = new ArrayList<>();

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
            words.add(br.readLine());
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        StringBuffer sb = new StringBuffer();
        Collections.sort(words, new Comparator<String>(){
			@Override
			public int compare(String s1, String s2) {
				if (s1.length() == s2.length()) {
                    return s1.compareTo(s2);
                } else {
                    return s1.length() - s2.length();
                }
			}
        });
        //중복 제거
        words = words.stream().distinct().collect(Collectors.toList());
        for (int i = 0; i < words.size(); i++) {
            sb.append(words.get(i)+"\n");
        }
        System.out.println(sb);
    }
}
