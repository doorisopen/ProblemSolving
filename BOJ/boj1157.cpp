/* 
 * 1157 단어 공부
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> res[1000001];
int word[26];

string _toLowerCase(string str) {
    for (int i = 0; i < str.length(); i++) {
        if(str[i] >= 65 && str[i] <= 90) {
            str[i] += 32;
        }
    }
    return str;
}
void solve() {
	//input
	string str;
	cin >> str;
	str = _toLowerCase(str);
	for (int i = 0; i < str.length(); i++) {
		word[str[i]-'a']++;
	}

	int mx = 0;
	for (int i = 0; i < 26; i++) {
		if(word[i] > 0) {
			res[word[i]].push_back(i+'a');
		}
		mx = max(mx, word[i]);
	}

	if(res[mx].size() > 1) {
		cout << "?";
	} else {
		char c = res[mx][0]-32;
		cout << c;
	}
}
int main(void){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	return 0;
}