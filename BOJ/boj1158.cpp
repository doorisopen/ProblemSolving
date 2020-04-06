#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    list<int> l;
    vector<int> ans;

    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        l.push_back(i);
    }

    list<int>::iterator kill = l.begin();

    int people = l.size();
    while (people)
    {
        // k번째로 이동
        for(int i = 0; i < k-1; i++) {
            ++kill;
            if(kill == l.end()) {
                kill = l.begin();
            }
        }
        
        ans.push_back(*kill);
        kill = l.erase(kill);
        --people;

        if(kill == l.end()) kill = l.begin();
    }
    
    cout << "<";
    for(int i = 0; i < ans.size(); i++) {
        if(i == ans.size() - 1) {
            cout << ans[i];
        } else {   
            cout << ans[i] << ", ";
        }
    }
    cout << ">";

    return 0;
}