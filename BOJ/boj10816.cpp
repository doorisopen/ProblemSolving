/** 10816 숫자 카드 2
 * find 참고 https://www.acmicpc.net/board/view/32921
 */
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,num;
    cin >> n;
    map<int,int> m;
    for (int i = 0; i < n; i++) {
        cin >> num;
        m[num]++;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {    
        cin >> num;
        if(m.find(num)!=m.end()) {
            cout << m[num] << " ";
        } else {
            cout << "0 ";
        }
    }
    return 0;
}