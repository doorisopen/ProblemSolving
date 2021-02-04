import java.io.*;
import java.util.*;

/*
 * 연산자 끼워넣기
 */
public class boj14888 {
    static StringBuffer sb = new StringBuffer();
    static int N, mxNum = Integer.MIN_VALUE, mnNum = Integer.MAX_VALUE;
    static int[] arr;
    static int[] selectedOp;
    static List<Integer> ops = new ArrayList<>();
    static boolean[] checkOp;

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
        arr = new int[N];
        checkOp = new boolean[N-1];
        selectedOp = new int[N-1];
        String[] input = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(input[i]);
        }
        input = br.readLine().split(" ");
        for (int i = 0; i < input.length; i++) {
            int count = Integer.parseInt(input[i]);
            while ((count--) > 0) {
                ops.add(i);
            }
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        selectOp(0);
        System.out.println(mxNum+"\n"+mnNum);
    }

    public static void selectOp(int count) {
        if (count == N-1) {
            int result = arr[0];
            for (int i = 0; i < N-1; i++) {
                result = calc(result, selectedOp[i], arr[i+1]);
            }
            mxNum = Math.max(mxNum, result);
            mnNum = Math.min(mnNum, result);
        }
        for (int i = 0; i < ops.size(); i++) {
            int op = ops.get(i);
            if (!checkOp[i]) {
                checkOp[i] = true;
                selectedOp[count] = op;
                selectOp(count+1);
                checkOp[i] = false;
            }
        }
    }

    public static int calc(int num1, int op, int num2) {
        int result = 0;
        if (op == 0) {
            result = num1 + num2;
        }
        if (op == 1) {
            result = num1 - num2;
        }
        if (op == 2) {
            result = num1 * num2;
        }
        if (op == 3) {
            if (num1 < 0) {
                num1 *= -1;
                result = (num1/num2)*(-1);
            } else {
                result = num1/num2;
            }
        }
        return result;
    }
}
