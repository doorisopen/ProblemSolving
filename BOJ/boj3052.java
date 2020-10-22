/*
 * 3052 나머지
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;

public class boj3052 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// StringBuffer sb = new StringBuffer();
		//input
		String input;
		HashSet<Integer> s = new HashSet<Integer>();
		while((input = br.readLine()) != null) {
			s.add(Integer.parseInt(input)%42);
		}
		System.out.println(s.size());
		br.close();
	}
}
