#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    map<string, tuple<string, int> > m;

    m["memberA"] = make_tuple("01012344567", 20);

    cout << get<0>(m["memberA"]) << " " << get<1>(m["memberA"]) << "\n";

    return 0;
}