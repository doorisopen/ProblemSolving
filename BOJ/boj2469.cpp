/** 2469 사다리 타기
 * 단순 구현
 */
#include <bits/stdc++.h>
using namespace std;

char result[27];
char people[27];
char board[1001][26];
int k, n, check;
bool isFail = false;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    //input
    cin >> k;
    cin >> n;
    for (int i = 0; i < k; i++) {
        people[i] = 'A'+i;
        cin >> result[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k-1; j++) {
            cin >> board[i][j];
            if(board[i][j] == '?') check = i;
        }        
    }

    //search top down
    for (int i = 0; i < check; i++) {
        for (int j = 0; j < k-1; j++) {
            if(board[i][j]=='-') {
                people[j]^=people[j+1]^=people[j]^=people[j+1];
            }
        }        
    }
    // search bottom up
    for (int i = n-1; i > check; i--) {
        for (int j = 0; j < k-1; j++) {
            if(board[i][j] == '-') {
                result[j]^=result[j+1]^=result[j]^=result[j+1];
            }
        }        
    }

    //compare
    for (int i = 0; i < k-1; i++) {
        if(people[i] == result[i]) {
            board[check][i] = '*';
        } else if(people[i] == result[i+1] && people[i+1] == result[i]){
            board[check][i] = '-';
            people[i]^=people[i+1]^=people[i]^=people[i+1];
        } else {
            isFail = true;
            break;
        }
    }

    //result
    if(!isFail) {
        for (int i = 0; i < k-1; i++) {
            cout << board[check][i];
        }
        cout << "\n";
    } else {
        for (int i = 0; i < k-1; i++) {
            cout << 'x';
        }
        cout << "\n";
    }
    return 0;
}
