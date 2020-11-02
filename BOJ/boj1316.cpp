/* 
 * 1316 그룹 단어 체커
 */
#include <bits/stdc++.h>
using namespace std;
void solution() {
	int n,ans=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		bool isGroup = true;
		bool check[27] = {false,};
		char cur = str[0]-'a'; check[cur] = true;

		for (int j = 1; j < str.length(); j++) {
			char nxt = str[j]-'a';
			if(cur != nxt) {
				if(check[nxt]) {
					isGroup = false;
					break;
				}
				check[nxt] = true;
				cur = nxt;
			}
		}
		if(isGroup) ans++;
	}
	cout << ans << "\n";
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
	solution();
	return 0;
}