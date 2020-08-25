/** 2485 가로수
 */
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(),arr.end());
    //가로수 사이의 최대공약수를 구한다
    int mn = arr[1] - arr[0];
    for (int i = 2; i < arr.size(); i++) {
        mn = gcd(mn, arr[i]-arr[i-1]);
    }
    //전체 공간에서 최소 거리를 나눈다.
    cout << (arr[n-1] - arr[0]) / mn - (n-1);
    return 0;
}