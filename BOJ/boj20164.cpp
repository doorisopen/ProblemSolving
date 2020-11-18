/* 
 * 1번 홀수 홀릭 호석
 */
#include <bits/stdc++.h>
using namespace std;

vector<string> out;
int mnCnt=99999, mxCnt=0;

void printAll() {
    cout << "[ ";
    for (auto str : out) {
        cout << str << " ";
    }
    cout << "]\n";
}
void cut(string str, string S, int oddCount, bool isCalc) {
	// cout << "cur(" << str << ", " << S << ", " << oddCount << ")\n";
	//odd count
	if(!isCalc) {
		for (int i = 0; i < str.length(); i++) {
			if((str[i]-'0')%2 == 1) oddCount++;
		}
		isCalc = true;
	}

	if(str.length() >= 3) {
		if(S.length() == 0 && out.size() == 3) {
			// printAll();
			int val = 0;
			for (auto str : out) {
				val += stoi(str);
			}
			str = to_string(val);
			// cout << str << "\n";
			vector<string> temp = out;
			out.clear();
			cut(str,str,oddCount,false);
			out = temp;
			return;
		}
		for (int i = 0; i < S.length(); i++) {
			out.push_back(S.substr(0,i+1));
			cut(str, S.substr(i+1), oddCount, isCalc);
			out.pop_back();
		}
	} else if(str.length() == 2) {
		str = to_string((str[0]-'0') + (str[1]-'0'));
		cut(str, str, oddCount, false);
	} else {
		mnCnt = min(mnCnt, oddCount);
		mxCnt = max(mxCnt, oddCount);
		return;
	}
}
int solution() {
	string str;
	cin >> str;
	cut(str, str, 0, false);
	cout << mnCnt << " " << mxCnt << "\n";
    return 0;
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solution();
	return 0;
}