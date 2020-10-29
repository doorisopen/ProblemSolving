/*
 * 1074 Z
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class boj1074 {
	static int n, r, c, val = 0;
	static void Z(int len, int x, int y) {
		if(x == r && y == c) {
			System.out.println(val);
			return;
		}
		if(r < x + len && r >= x && c < y + len && c >= y) {
			Z(len/2,x,y);
			Z(len/2,x,y+len/2);
			Z(len/2,x+len/2,y);
			Z(len/2,x+len/2,y+len/2);
		} else {
			val += len*len;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// StringBuffer sb = new StringBuffer();
		String[] str = br.readLine().split(" ");
		int[] input = new int[4];
		for (int i = 0; i < str.length; i++) {
			input[i] = Integer.parseInt(str[i]);
		}
		n = input[0];
		r = input[1];
		c = input[2];
		Z((int) Math.pow(2, n), 0, 0);
		br.close();
	}
}