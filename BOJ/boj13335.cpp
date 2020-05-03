#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, w, l, moveTime = 0;
int car[1001];
queue<int> q;

void solve() {
    int weight = 0;
    for (int i = 0; i < n; i++)
    {
        while (1)
        {
            //다리가 완전 비었을때
            if(q.empty()) {
                q.push(car[i]);
                moveTime++;
                weight += car[i];
                break;
            //다리가 가득찼을때
            } else if(q.size() == w) {
                weight -= q.front();
                q.pop();
            //다리에 자리가 남아있을때
            } else {
                //현재 다리 무게 + 자동차 무게 > 다리 무게
                if(weight + car[i] > l) {
                    q.push(0);
                    moveTime++;
                } else {
                    q.push(car[i]);
                    moveTime++;
                    weight += car[i];
                    break;
                }
            }
        }
    }
    cout << moveTime + w;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    cin >> n >> w >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> car[i];
    }
    
    solve();
    return 0;
}