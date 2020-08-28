/** 18110 solved.ac
 * 단순 구현
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int difficulty[1000000];
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll num;
    //input
    cin >> num;
    if(num == 0) {
        cout << "0\n";
        return 0;
    }    
    for (ll i = 0; i < num; i++) {
        cin >> difficulty[i];
    }
    sort(difficulty, difficulty+num);

    //calc
    double sum = 0;
    ll calc = (ll)round(num*0.15f);
    for (ll i = calc; i < num-calc; i++) {
        sum += difficulty[i];
    }
    //result
    double res = sum / (num-calc*2);
    cout << (ll)round(res);
    return 0;
}