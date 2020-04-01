#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, K, cnt[2][6] = {0};
    
	cin >> N >> K;
	for(int i=0; i<N; i++){
		int S, Y;
		cin >> S >> Y;
		cnt[S][Y-1]++;
	}
	int result = 0;
	for(int i=0; i<2; i++)
		for(int j=0; j<6; j++)
			result += (cnt[i][j]+K-1)/K;

    // for(int i=0; i<2; i++) {
	// 	for(int j=0; j<6; j++) {
	// 		cout << cnt[i][j] << " ";
    //     }
    // cout << "\n";
    // }

	cout << result;

    return 0;
}