import java.util.*;
class 구명보트 {
    public int solution(int[] people, int limit) {
        Arrays.sort(people);
        int boat = 0;
        int s = 0, e = people.length-1;
        while (s <= e) {
            if (people[s] + people[e] <= limit) {
                s++;
            }
            e--;
            boat++;
        }
        return boat;
    }
}