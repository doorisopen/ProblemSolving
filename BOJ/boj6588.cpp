/** 6588 골드바흐의 추측
 */
#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int prime[MAX];
vector<int> oddPrime;
void init() {
    for (int i = 2; i <= MAX; i++) {
        prime[i] = i;
    }
    for (int i = 2; i <= MAX; i++) {
        if(prime[i] == 0) continue;
        for (int j = i+i; j <= MAX; j+=i) {
            prime[j] = 0;
        }        
    }
    for(int i = 2; i <= MAX; i++) {
        if(prime[i] != 0 && i%2!=0) {
            oddPrime.push_back(i);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //init prime
    init();
    int num;
    while (1) {
        //input
        cin >> num;
        if(!num) break;
        //search
        bool isFind = false;
        for (int i = 0; i < oddPrime.size(); i++) {
            int other = num-oddPrime[i];
            if(prime[other] != 0) {
                cout << num << " = " << oddPrime[i] << " + " << other << "\n";
                break;
            }
        }
    }
    return 0;
}