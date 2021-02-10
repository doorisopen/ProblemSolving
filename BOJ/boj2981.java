import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

/*
 * 2981 검문
 */
public class boj2981 {
    static StringBuffer sb = new StringBuffer();
    static int N;
    static int[] numbers;

    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
        solve();
    }

    public static void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(br.readLine());
        numbers = new int[N];
        for (int i = 0; i < N; i++) {
            String input = br.readLine();
            numbers[i] = Integer.parseInt(input);
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        List<Integer> answer = new ArrayList<>();
        Arrays.sort(numbers);
        /*
            입력값을 M으로 나눈 나머지가 전부 같아야한다.
            number[0]%M == number[1]%M == number[2]%M ...== number[n]%M
            M: 나눈수, R(0~n): 나머지
            number[0] = number[0]*M + R0
            number[1] = number[1]*M + R1
            number[2] = number[2]*M + R2
            number[n] = number[n]*M + Rn
            R0 == R1 == R2 ... == Rn 즉 R1-R0 == 0 이다.
            number[1] - number[0] == (number[1] - number[0])*M 이다.
            따라서, number[i] - number[i-1]..number[n]의 
            최대공약수의 약수를 구하면된다.
        */
        int res = numbers[1] - numbers[0];
        for (int i = 2; i < N; i++) {
            res = gcd(res, numbers[i] - numbers[i-1]);
        }
        for (int i = 2; i <= res; i++) {
            if (res%i == 0) {
                answer.add(i);
            }
        }
        answer = answer.stream().distinct().collect(Collectors.toList());
        Collections.sort(answer);
        for (int i = 0; i < answer.size(); i++) {
            System.out.print(answer.get(i)+" ");
        }
    }

    public static int gcd(int a, int b) {
        if (b==0) return a;
        return gcd(b, a%b);
    }
}
