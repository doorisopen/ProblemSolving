/*
 * 연습문제
 * 이상한 문자 만들기
 */
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull; 
typedef pair<int,int> pi;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
const int INF = 0x7f7f7f7f;
const ll INF_LL = 0x7f7f7f7f7f7f7f7f;

vector<string> _split(string str, char del) {
    vector<string> internal;
    stringstream ss(str);
    string temp;
    while(getline(ss,temp,del)) {
        internal.push_back(temp);
    }
    return internal;
}
char smallToCapitalLetter(char c) {
    if('A' <= c && c <= 'Z') {
        return c;
    }
    return (char)(c-32);
}
char capitalToSmallLetter(char c) {
    if('a' <= c && c <= 'z') {
        return c;
    }
    return (char)(c+32);
}
string solution(string s) {
    string result = "";
    vector<string> words = _split(s,' ');
    for (int i = 0; i < words.size(); i++) {
        string answer = "";
        string word = words[i];
        for (int j = 0; j < word.length(); j++) {
            if(j%2 == 0) {
                answer += smallToCapitalLetter(word[j]);
            } else {
                answer += capitalToSmallLetter(word[j]);
            }
        }
        words[i] = answer;
    }
    
    int idx = 0;
    for (int i = 0; i < s.length(); i++) {
        if(s[i] == ' ') {
            cout << i << "\n";
            result+=' ';
        } else {
            for (int j = 0; j < words[idx].length(); i++, j++) {
                result+=words[idx][j];
            }
            i--;
            idx++;
        }
    }
    cout << result << "\n";
    return result;
}

int main() {
    fastio;
    solution("try hello world");
    return 0;
}