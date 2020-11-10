/*
 * 월간 코드 챌린지 시즌1
 * 쿼드압축 후 개수 세기
 */
#include <string>
#include <vector>

using namespace std;
int board[1024][1024];
int a,b;
bool isOne(int n, int x, int y) {
    for(int i = x; i < n+x; i++) {
        for(int j = y; j < n+y; j++) {
            if(board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}
bool isZero(int n, int x, int y) {
    for(int i = x; i < n+x; i++) {
        for(int j = y; j < n+y; j++) {
            if(board[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}
void quad(int n, int x, int y) {
    if(isOne(n,x,y)) {a++; return;}
    if(isZero(n,x,y)) {b++; return;}
    quad(n/2,x,y);
    quad(n/2,x,y+n/2);
    quad(n/2,x+n/2,y);
    quad(n/2,x+n/2,y+n/2);
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board[i][j] = arr[i][j];
        }
    }
    quad(n,0,0);
    answer.push_back(b);
    answer.push_back(a);
    return answer;
}