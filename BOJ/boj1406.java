/*
 * 1406 에디터
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.ListIterator;

public class boj1406 {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuffer sb = new StringBuffer();
		LinkedList<Character> list = new LinkedList<>();
		ListIterator<Character> iter = list.listIterator(list.size());
		//input
		String word = br.readLine();
		for (int i = 0; i < word.length(); i++) {
			iter.add(word.charAt(i));
		}
		int n = Integer.parseInt(br.readLine());
		//search
		while(n-- > 0) {
			String[] command = br.readLine().split(" ");
			try {
				if(command[0].equals("P")) {
					iter.add(command[1].charAt(0));
				} else if(command[0].equals("L")) {
					iter.previous();
				} else if(command[0].equals("D")) {
					iter.next();
				} else if(command[0].equals("B")) {
					iter.previous();
					iter.remove();
				}
			} catch (Exception e) {}
		}
		for(char c : list) {
			sb.append(c);
		}
		System.out.println(sb);
		br.close();
	}
}