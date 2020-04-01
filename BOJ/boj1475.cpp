#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/1475
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n, cnt = 1;
    int arr[10];

    // 1로 초기화
    fill(arr, arr+10, 1);
    cin >> n;
    // n 이 0이면 1 리턴
    if(n == 0) {
        cout << "1\n"; 
        return 0;
    }

    while(n > 0) {
        int mod = n%10;
        // cout << "n=" << n << ": " << mod << "\n";
        
        // 1~5, 7~8 일때
        if(mod != 6 && mod != 9) {
            // 만약 팜플렛이 부족하면 1세트 추가
            if(arr[mod] == 0) {
                for(int i=0; i<10; i++) {
                    arr[i] += 1;
                }
                cnt++;
                arr[mod]--;
            } else {
                arr[mod]--;
            }
        } else if(mod == 6 || mod == 9) {
            if(arr[6] == 0 && arr[9] == 0) {
                for(int i=0; i<10; i++) {
                    arr[i] += 1;
                }
                cnt++;
                arr[mod]--;
            } else if(arr[6] != 0 && arr[9] == 0) {
                arr[6]--;
            } else if(arr[6] == 0 && arr[9] != 0) {
                arr[9]--;
            } else {
                arr[mod]--;
            }
        }
        n /= 10;
    }
    // for(int i=0;i<10;i++) cout << arr[i] << " ";
    cout << cnt;
    return 0;
}