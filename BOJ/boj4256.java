/*
 * 4256 트리
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class boj4256 {
	static int preIdx;
	static int postIdx;
	static int[] post;
	public static int searchRootIdx(int[] in, int start, int end, int value) {
		int i = 0;
		for (i = start; i <= end; i++) {
			if(in[i] == value) return i;
		}
		return i;
	}
	public static void buildTreeByInPre(int[] pre, int[] in) {
		preIdx = 0;
		postIdx = 0;
		buildTreeByInPre(pre, in, 0, pre.length-1);
	}
	public static void buildTreeByInPre(int[] pre, int[] in, int start, int end) {
		if(start > end) return;
		int root = pre[preIdx++];
		int mid = searchRootIdx(in, start, end, root);
		buildTreeByInPre(pre, in, start, mid-1);
		buildTreeByInPre(pre, in, mid+1, end);
		post[postIdx++] = root;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuffer sb = new StringBuffer();
		//input
		int t = Integer.parseInt(br.readLine());
		for (int i = 0; i < t; i++) {
			int n = Integer.parseInt(br.readLine());
			String[] preStr = br.readLine().split(" ");
			String[] inStr = br.readLine().split(" ");
			int[] pre = new int[n];
			int[] in = new int[n];
			post = new int[n];
			for (int j = 0; j < n; j++) {
				pre[j] = Integer.parseInt(preStr[j]);
				in[j] = Integer.parseInt(inStr[j]);
			}
			buildTreeByInPre(pre, in);
			for (int j = 0; j < n; j++) {
				sb.append(post[j]+" ");
			}
			sb.append("\n");
		}
		System.out.println(sb);
		br.close();
	}
}