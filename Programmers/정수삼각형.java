/*
 * 동적 계획법
 */
class Solution {
    static int[][] dp;
    public int solution(int[][] triangle) {
        int answer = 0;
        int size = triangle.length;
        dp = new int[size+1][size+1];
        dp[0][0] = triangle[0][0];
        for (int i = 0; i < size-1; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i+1][j] = Math.max(dp[i+1][j], dp[i][j]+triangle[i+1][j]);
                dp[i+1][j+1] = Math.max(dp[i+1][j+1], dp[i][j]+triangle[i+1][j+1]);
                answer = Math.max(answer, Math.max(dp[i+1][j], dp[i+1][j+1]));
            }
        }
        return answer;
    }
}