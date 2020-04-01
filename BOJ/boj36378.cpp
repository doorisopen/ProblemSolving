#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n=0, a[100] = { 0, }, b[100] = { 0, };
	string s, ss;
	cin >> s;
	cin >> ss;
	for (int i = 0; i < s.length(); i++) {
		a[s[i] - 'a']++;//s 알파벳 개수 저장
	}
    for (int i = 0; i < ss.length(); i++) {
		b[ss[i] - 'a']++;//ss 알파벳 개수 저장
	}


	for (int i = 0; i < 26; i++) {
		int m = max(a[i], b[i]);
		int s = min(a[i], b[i]);
		n += m - s;//알파벳 개수 차이 만큼 더함
	}
	cout << n;
	return 0;
}