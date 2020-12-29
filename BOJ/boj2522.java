import java.io.*;
import java.util.*;

public class boj2522 {
    static int n;
    static void input() {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        scanner.close();
    }

    static void solve() {
        int j = n - 1;
        for (int i = 0; i < n*2; i++) {
            int k = 0, s = j;
            while (k < j) {
                System.out.print(" ");
                k++;
            }
            while (s < n) {
                System.out.print("*");
                s++;
            }
            if (i < n-1) {
                j--;
            } else {
                j++;
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        input();
        solve();
    }
}