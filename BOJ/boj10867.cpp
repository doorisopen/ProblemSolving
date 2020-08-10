/** 10867 중복 빼고 정렬하기
 */
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> s;
    while (n--) {
        int num;
        cin >> num;
        s.insert(num);
    }
    for(auto item : s) {
        cout << item << " ";
    }
    return 0;
}