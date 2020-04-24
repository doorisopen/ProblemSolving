#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string str;
    int i = 1;
    while(str[0] != '-') {
        int cnt = 0, fix = 0;
        cin >> str;
        if(str[0] == '-') {return 0;}

        for(int j = 0; j < str.length(); j++) {
            if(str[j] == '{') {
                cnt++;
            } else {
                cnt--;
                if(cnt == -1) {
                    cnt = 1;
                    fix++;
                }
            }
        }
        fix += cnt/2;
        cout << i++ << ". " << fix << "\n";
    }
    return 0;
}