/** 1929 소수 구하기
 */
#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int arr[MAX];
void prime() {
    //init
    for (int i = 2; i < MAX; i++) {
        arr[i] = i;
    }
    //Eratos
    for (int i = 2; i < MAX; i++) {
        if(arr[i] == 0) continue;
        for (int j = i+i; j < MAX; j += i) {
            arr[j] = 0;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int m,n;
    cin >> m >> n;
    prime();
    //result
    for (int i = m; i <= n; i++) {
        if(arr[i]!=0) {
            cout << arr[i] << "\n";
        }
    }   
    return 0;
}