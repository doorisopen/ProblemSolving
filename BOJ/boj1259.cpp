/** 1259 팰린드롬수
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    while (1) {
      cin >> s;
      if(s=="0") break;
      int len = s.length();
      bool isPalindrome = true;
      for (int i = 0; i <= len/2; i++) {
        if(s[i] != s[len-1-i]) {
          isPalindrome = false;
          break;
        }
      }
      if(isPalindrome) {
        cout << "yes\n";
      } else {
        cout << "no\n";
      }
    }
    return 0;
}