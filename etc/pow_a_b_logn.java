/* a^b 구하기
 * 시간복잡도: logn
 * 1. 반복문 활용(pow_iteration)
 * 2. 재귀 활용(pow_recursive)
 */
public class pow_a_b_logn {

    public static void main(String[] args) throws Exception {
        int ans1 = pow_iteration(2,10);
        int ans2 = pow_recursive(2,10);
        System.out.println(ans1); // 1024
        System.out.println(ans2); // 1024
    }

    public static int pow_iteration(int a, int b) {
        int ans = 1;
        while (b > 0) {
            if (b%2 > 0) { // b가 홀수면
                ans *= a;
            }
            a *= a;
            b /= 2;
        }
        return ans;
    }

    public static int pow_recursive(int a, int b) { // a^b 반환
        if (b == 0) return 1; // a^0 = 1
        if (b%2 == 1) { // b가 홀수면
            return a*pow_recursive(a, b-1);
        } else {
            int half = pow_recursive(a, b/2);
            return half*half;// a^(b/2) 반환
        }
    }
}
