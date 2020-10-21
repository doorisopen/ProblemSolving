/*
 * 월간 코드 챌린지 시즌1
 * 삼각 달팽이
 */
#include <string>
#include <vector>

using namespace std;
int dr[3] = {1,0,-1};
int dc[3] = {0,1,-1};
int board[1001][1001];
vector<int> solution(int n) {
    //input
	int end = 0;//4: 10, 5: 15, 6: 21...
	for (int i = 1; i <= n; i++) {
		end += i;
	}

	//fill
	int r = 0, c = 0;
	int val = 1;
	while(val <= end-1) {
		while(r < n-1 && board[r+1][c] == 0) {
			board[r][c] = val++;
			r += dr[0];
			c += dc[0];
		}
		while(c < n-1 && board[r][c+1] == 0) {
			board[r][c] = val++;
			r += dr[1];
			c += dc[1];
		}
		while(board[r+dr[2]][c+dc[2]] == 0) {
			board[r][c] = val++;
			r += dr[2];
			c += dc[2];
		}
	}
	board[r][c] = val;

	//result
	vector<int> answer;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			answer.push_back(board[i][j]);
		}		
	}
	return answer;
}