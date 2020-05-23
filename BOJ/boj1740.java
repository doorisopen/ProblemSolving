import java.util.*;
public class Main {

	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long answer = 0;
        
        Queue qu = new LinkedList();
        while(n>0) {
            qu.offer(n%2);
            n /= 2;
        }
        
        long adding = 1;
        
        while(!qu.isEmpty()) {
            answer += Long.valueOf(String.valueOf(qu.poll())) * adding;
            adding *= 3;
        }
        System.out.println(answer);
	}

}