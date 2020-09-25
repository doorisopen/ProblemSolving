/* 
 * 4256 트리
 */
#include <bits/stdc++.h>
using namespace std;

int t, n;
int preOrder[1001];
int inOrder[1001];
int postOrder[1001];
int preIdx = 0, postIdx = 0;

int searchRootIdx(int start, int end, int value) {
	int i = 0;
	for (i = start; i <= end; i++) {
		if(inOrder[i] == value) return i;
	}
	return i;
}
void post(int start, int end) {
	if(start > end) return;
	int root = preOrder[preIdx++];
	int mid = searchRootIdx(start, end, root);
	post(start, mid-1);
	post(mid+1, end);
	postOrder[postIdx++] = root;
}

void solve() {
	//input
	cin >> t;
	while (t--) {
		memset(preOrder,0,sizeof(preOrder));
		memset(inOrder,0,sizeof(inOrder));
		memset(postOrder,0,sizeof(postOrder));
		preIdx = 0;
		postIdx = 0;
		cin >> n;
		//전위
		for (int j = 0; j < n; j++) {
			cin >> preOrder[j];
		}
		//중위
		for (int j = 0; j < n; j++) {
			cin >> inOrder[j];
		}
		post(0,n-1);
		//후위 결과 출력
		for (int j = 0; j < n; j++) {
			cout << postOrder[j] << " ";
		}
		cout << "\n";
	}

}
int main(void){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	return 0;
}