#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<char> arr;
char tmp[16];
bool check[16];
int n, m;

bool isContain() {
    int vowelsCnt = 0, other = 0;
    for (int i = 0; i < n; i++)
    {
        if(tmp[i] == 'a' || tmp[i] == 'e' || tmp[i] == 'i' || tmp[i] == 'o' || tmp[i] == 'u') {
            vowelsCnt++;
        } else {
            other++;
        }
    }
    if(vowelsCnt >= 1 && other >= 2) {
        return true;
    } else {
        return false;
    }
}

void solve(int d, int a) {
    if(d == n) {
        if(isContain()) {
            for (int i = 0; i < n; i++)
            {
                cout << tmp[i];
            }
            cout << "\n";
        }
        return;
    }
    for (int i = a; i < m; i++)
    {
        if(!check[i]) {
            check[i] = true;
            tmp[d] = arr[i];
            solve(d+1, i);
            check[i] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    
    string str="";
    char c;
    for (int i = 0; str.length() != m; i++)
    {
        cin >> c;
        if(c != ' ') {
            str += c;
        }
    }
 
    for (int i = 0; i < str.length(); i++)
    {
        arr.push_back(str[i]);
    }

    sort(arr.begin(), arr.end());
    solve(0, 0);
    
    return 0;
}