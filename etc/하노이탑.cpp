/* 
 * 하노이 탑
 */
#include <bits/stdc++.h>
using namespace std;

void move(int n, char start, char end) {
    cout << n << " " << start << "->" << end << "\n";
}
void hanoi(int n, char start, char mid, char end) {
    if(n==1) {
        move(n, start, end);
    } else {
        hanoi(n-1,start, end, mid);
        move(n, start, end);
        hanoi(n-1, mid, start, end);
    }
}
int solution() {
    int n = 3;
    hanoi(n,'A','B','C');
    return 0;
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solution();
	return 0;
}