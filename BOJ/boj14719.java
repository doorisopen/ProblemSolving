/*
 * boj 14719 빗물
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class boj14719 {
    public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//input
		String[] info = br.readLine().split(" ");
		String[] boardInfo = br.readLine().split(" ");
		int w = Integer.parseInt(info[1]);
		int[] board = new int[w+1];
		for (int i = 0; i < w; i++) {
			board[i] = Integer.parseInt(boardInfo[i]);
		}

		//search
		int res = 0;
		for (int i = 1; i < w; i++) {
			int left = i, right = i;
			int lmx = board[i], rmx = board[i];
			while(left >= 0) {
				lmx = Math.max(lmx, board[left--]);
			}
			while(right < w) {
				rmx = Math.max(rmx, board[right++]);
			}
			res += (Math.min(lmx,rmx) - board[i]);
		}
		System.out.println(res);
		br.close();
	}
}
