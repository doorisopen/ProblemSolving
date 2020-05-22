#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int num, sum = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> num;
        if(num < 40) {
            num = 40;
        }
        sum += num;
    }
    cout << sum/5;    
    return 0;
}