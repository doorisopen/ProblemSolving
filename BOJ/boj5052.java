/*
 * 5052 전화번호 목록
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class boj5052 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuffer sb = new StringBuffer();
		//input
		int t = Integer.parseInt(br.readLine());
		for (int i = 0; i < t; i++) {
			Trie trie = new Trie();
			boolean check = false;
			int n = Integer.parseInt(br.readLine());
			for (int j = 0; j < n; j++) {
				String num = br.readLine();
				if(!check) {
					if(!trie.insert(num, 0)) {//연관성 검사
						check = true;//연관성 발견
					}
				}
			}
			//result
			if(check) {
				sb.append("NO\n");
			} else {
				sb.append("YES\n");
			}
		}
		System.out.println(sb);
		br.close();
	}
	public static class Trie {
		Trie[] number;
		boolean terminal, notFound;
		Trie() {
			this.number = new Trie[10];
			this.terminal = false;
			this.notFound = false;
		}
		public int toNum(char c) {
			return c - '0';
		}
		public boolean insert(String s, int idx) {
			if(terminal) return false;
			if(idx == s.length()) {
				if(notFound) {
					return false;
				}
				terminal = true;
				return true;
			}
			else {
				int next = toNum(s.charAt(idx));
				if(number[next] == null) {
					number[next] = new Trie();
					notFound = true;
				}
				return number[next].insert(s,idx+1);
			}
		}
	}	
}