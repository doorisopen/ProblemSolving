import java.util.*;
public class stringReverseRecurrsive {

    public static void solve(String str, int len) {
        if (len == 0)
            return;

        System.out.print(str.charAt(len-1));
        solve(str, len-1);
    }

    public static void main(String args[]) {
        String str = "hello world";

        solve(str, str.length());
    }
}