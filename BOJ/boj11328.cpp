// #include <bits/stdc++.h>
// using namespace std;


// int main() {
//     cin.tie(nullptr);
//     ios::sync_with_stdio(false);
    
//     int n;
//     cin >> n;

//     for(int i = 0; i < n; i++) {
//         string s1, s2;
//         cin >> s1 >> s2;
//         if(s1.length() != s2.length()) {
//             cout << "Impossible\n";
//             continue;
//         }
//         int arr[26] = {0,};
//         for(int j = 0; j < s1.length(); j++) {
//             arr[s1[j] - 'a']++;
//         }
//         bool possible = true;
//         for(int j = 0; j < s2.length(); j++) {
//             if(--arr[s2[j] - 'a'] < 0) {
//                 possible = false;
//                 cout << "Impossible\n";
//                 break;
//             }
//         }
//         if(possible) {
//             cout << "Possible\n";
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int asciiSum(string s) {
    int size = s.length();
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += (int)s[i]; 
    }
    return sum;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        if(s1.length() != s2.length()) {
            cout << "Impossible\n";
            continue;
        }
        if(asciiSum(s1) == asciiSum(s2)) {
            cout << "Possible\n";
        } else {
            cout << "Impossible\n";
        }
    }
    return 0;
}