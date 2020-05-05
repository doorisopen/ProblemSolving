/**
 * 문자열 배열(string array)이 주어지면, 
 * 제일 긴 공통된 접두사(prefix)의 길이를 찾으시오. 
예제)
Input: [“apple”, “apps”, “ape”]
Output: 2 // “ap”

Input: [“hawaii”, “happy”]
Output: 2 // “ha”

Input: [“dog”, “dogs”, “doge”]
Output: 3 // “dog”
*/

#include <bits/stdc++.h>
using namespace std;

int longestPrefix(string s[3]) {
    string prefix = s[0];
    for (int i = 0; i < prefix.length(); i++) {
        char c = prefix[i];
        for (int j = 1; j < 3; j++) {
            if(i == s[j].length() || s[j][i] != c) {
                return i;
            }         
        }
    }
    return prefix.length();
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s[3] = {"apple","apps","ape"};

    cout << longestPrefix(s);

    return 0;
}