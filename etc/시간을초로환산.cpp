/*
 * 문자열 HH:MM:SS 가 주어질때 초로 환산하기
 */
#include <bits/stdc++.h>
using namespace std;

vector<string> _split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string temp;
    while (getline(ss, temp, delimiter)) {
        internal.push_back(temp);
    }
    return internal;
}
string changeSec(string t) {
    vector<string> tmp = _split(t,':');
    int sec = stoi(tmp[2]);
    sec += stoi(tmp[1])*60;
    sec += stoi(tmp[0])*3600;
    return to_string(sec);
}
void solution() {
    cout << changeSec("01:00:50");//HH:MM:SS
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solution();
    return 0;
}