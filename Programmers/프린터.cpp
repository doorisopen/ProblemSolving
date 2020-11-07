/* 
 * 스택/큐
 * 프린터
 */
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int n = priorities.size();
    deque<pair<int,int>> dq;
    for (int i = 0; i < n; i++) {
        dq.push_back({priorities[i],i});
    }
    while(1) {
        bool isGt = false;
        for (int j = 0; j < dq.size(); j++) {
            if(dq[0].first < dq[j].first) {
                isGt = true;
            }
        }        
        if(isGt) {
            dq.push_back(dq[0]);
            dq.pop_front();
        } else {
            if(dq[0].second == location) {
                break;
            }
            dq.pop_front();
            answer++;
        }
    }
    return answer+1;
}