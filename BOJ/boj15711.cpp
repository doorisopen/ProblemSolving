/** 15711 환상의 짝꿍
 * 합성수 M은 (임의의 소수) * (임의의 수)로 표현이 된다.
 * 따라서, root(4조) = 200만
 * 참고: 밀러-라빈 소수판별법
 */
#include <bits/stdc++.h>
#define MAX 2000001
using namespace std;
typedef long long ll;

int prime[MAX];
vector<int> arr;
//200만까지의 소수는 대략 15만개 정도 있고, 이 경우 7천만번 정도만 반복하면 된다.
bool isPrimeNumber(ll x) {
	for(int i = 0; i < arr.size() && (ll)(arr[i] * arr[i]) <= x; i++){
		if(x % arr[i] == 0) return false;
	}
	return true;
}
void init() {
    for (int i = 2; i < MAX; i++) {
        prime[i] = i;
    }
    for (int i = 2; i < MAX; i++) {
        if(prime[i] == 0) continue;
        for (int j = i+i; j < MAX; j+=i) {
            prime[j] = 0;
        }        
    }
    for (int i = 2; i < MAX; i++) {
        if(prime[i] != 0) arr.push_back(i);
    }
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //input
    init();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b, tmp = 0;
        cin >> a >> b;
        tmp = a+b;
        if(tmp>4&&tmp%2==0) {//골드 바흐
            cout << "YES\n";
        } else {
            if(tmp < 4) {
                cout << "NO\n";
                continue;
            }
            // 골드바흐가 아니면 이전 홀수값이 반드시 포함되어야하는데
            // 이전 홀수 값이 소수이면 YES
            if(isPrimeNumber(tmp-2)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}