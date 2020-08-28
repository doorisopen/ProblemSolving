/** 1049 기타줄
 * 단순 구현
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    vector<int> av;
    vector<int> bv;
    int n,m,answer=0;
    cin >> n >> m;//끊어진 기타줄, 브랜드 수
    for (int i = 0; i < m; i++) {
        int a, b;//선택 가격, 패키지, 낱개
        cin >> a >> b;
        av.push_back(a);
        bv.push_back(b);
    }
    sort(av.begin(), av.end());
    sort(bv.begin(), bv.end());
    if(av[0] > bv[0]*6) {
        av[0] = bv[0]*6;
    }
    if(av[0] < bv[0]*(n%6)) {//
        answer = av[0]*(n/6+1);
    } else {
        answer = av[0]*(n/6) + bv[0]*(n%6);
    }
    cout << answer;
    return 0;
}