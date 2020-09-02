/** 14002 가장 긴 증가하는 부분 수열4
 *  dp
 * 가장 긴 증가 수열을 구하고 해당 원소들을 출력해야한다.
 * 증가 수열을 출력하기위해서 trace배열을 따로 두고
 * 해당 원소가 이전에 어디서 왔는지 저장하고 
 * idx 역추적하여 찾아간다.
 */
#include <bits/stdc++.h>
using namespace std;

int n,ans;
int arr[1001];
int dp[1001];
int trace[1001];
vector<int> res;

void reverseSearch(int idx) {
    if(idx == -1) return;
    res.push_back(arr[idx]);
    reverseSearch(trace[idx]);
}
void solve() {
	//input
	cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    //search
    for (int i = 0; i < n; i++) {
        if(dp[i] == 0) dp[i] = 1;
        trace[i] = -1;
        for (int j = 0; j < i; j++) {
            if(arr[i] > arr[j]) {
                if(dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    trace[i] = j;
                }
            }
        }
        ans = max(ans,dp[i]);
    }

    //result
    cout << ans << "\n";
    
    for (int i = 0; i < n; i++) {
        if(dp[i] == ans) {
            res.push_back(arr[i]);
            reverseSearch(trace[i]);
            break;
        }
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
	solve();
    return 0;
}