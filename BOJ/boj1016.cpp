/** 1016 제곱 ㄴㄴ 수
 */
#include <bits/stdc++.h>
#define MAX 2000001
using namespace std;
typedef long long ll;

int square[MAX];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll mn,mx,tmp,cnt=0;
    cin >> mn >> mx;
    cnt = mx-mn+1; // 탐색할 수 개수
    
    for (ll i = 2; (i*i) <= mx; i++) {
        ll num = mn / (i*i);//mn과 가장 가까운 i의 제곱수를 찾는다.
        if(mn % (i*i) != 0) num++;//mn범위 이하 이기때문에 +1

        for (ll j = num; j*(i*i) <= mx; j++) {//mn과 가장 가까운 i의 제곱수를 mx 범위까지 탐색
            if(square[j*(i*i)-mn] == 0) {
                square[j*(i*i)-mn] = 1;//제곱수에 의해 나누어 떨어지는 수 표시
                cnt--;//제곱수ㄴㄴ개수 -1
            }
        }
    }
    cout << cnt;
    return 0;
}