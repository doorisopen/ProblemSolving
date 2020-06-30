// BOJ 14888 연산자 끼워넣기
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;

const int INF = 0x7f7f7f7f;
const ll INF_LL = 0x7f7f7f7f7f7f7f7f;

int n, sum;
int maxResult = -INF, minResult = INF;
bool isFirst = true;
bool check[101];
vector<int> arr;
vector<char> op;
vector<char> tmp;

void calc(char c, int idx) {
    if(isFirst) {
        isFirst = false;
        if(c == '+') {
            sum = arr[0] + arr[1];
        } else if(c == '-') {
            sum = arr[0] - arr[1];
        } else if(c == '*') {
            sum = arr[0] * arr[1];
        } else if(c == '/') {
            sum = arr[0] / arr[1];
        }
    } else {
        if(c == '+') {
            sum += arr[idx];
        } else if(c == '-') {
            sum -= arr[idx];
        } else if(c == '*') {
            sum *= arr[idx];
        } else if(c == '/') {
            if(sum < 0) {
                sum = -sum;
                sum /= arr[idx];
                sum = -sum;
            } else {
                sum /= arr[idx];
            }
        }
    }
}

void solve(int d) {
    if(d == op.size()) {
        for (int i = 0; i < tmp.size(); i++) {
            calc(tmp[i], i+1);
        }
        maxResult = max(maxResult, sum);
        minResult = min(minResult, sum);
        sum = 0;
        isFirst = true;
        return;
    }
    for (int i = 0; i < op.size(); i++) {
        if(!check[i]) {
            tmp.push_back(op[i]);
            check[i] = true;
            solve(d+1);
            tmp.pop_back();
            check[i] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    //input
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    for (int i = 0; i < a; i++) {op.push_back('+');}
    for (int i = 0; i < b; i++) {op.push_back('-');}
    for (int i = 0; i < c; i++) {op.push_back('*');}
    for (int i = 0; i < d; i++) {op.push_back('/');}
    
    solve(0);
    
    cout << maxResult << "\n" << minResult;
    return 0;
}