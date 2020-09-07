/**
 * 2020 KAKAO BLIND RECRUITMENT
 * 외벽점검
 * 
 * //==접근방법==//
 * weak데이터를 원형이 아닌 직선에 놓인 수열이라고 생각한다.
 * n=12 그리고 수열이 1,5,6,10 일때 취약지점 커버 가능여부를 확인
 * 다음 수열은 5,6,10,n+weak[0]->5,6,10,13 
 * 위 처럼 수열을 만드는데 weak배열 크기 만큼 반복한다.
 * 
 * dist배열을 내림차순으로 정렬하고 
 * dist 배열 크기를 n이라고 할때
 * 1개 선택 2개 선택... 순으로 nPr순열을 만들어서
 * 해당 순열이 취약지점을 점검할 수 있는지 확인한다.
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> selected;//순열 값
bool visit[8];//순열 방문처리
bool check[2001];//커버지점 체크
bool ans;//결과
void select(int d, int limit, vector<int> &dist, deque<int> &dq) {
    if(d == limit) {
        fill(check,check+2001,false);
        int safeP = dq[0];//현재 커버 위치
        int pos = 0;//커버 순열 idx
        
        while (pos < limit) {
            //커버가능한 지점 체크
            for (int j = safeP; j <= safeP+selected[pos]; j++) {
                check[j] = true;
            }
            safeP += selected[pos++];
            //안전 지점이 더 크면 다음 취약점 찾기
            for (int j = 0; j < dq.size(); j++) {
                if(safeP < dq[j]) {
                    safeP = dq[j];
                    break;
                }
            }           
        }
        if(check[dq[dq.size()-1]]) ans = true;
    }
    for (int i = 0; i < dist.size(); i++) {
        if(!visit[i]) {
            visit[i] = 1;
            selected.push_back(dist[i]);
            select(d+1,limit,dist,dq);
            visit[i] = 0;
            selected.pop_back();
        }
    }
    
}
int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 999999;
    int sz = dist.size();
    deque<int> dq;
    
    //init
    sort(weak.begin(), weak.end());
    for (int i = 0; i < weak.size(); i++) {
        dq.push_back(weak[i]);
    }
    sort(dist.begin(), dist.end(), greater<int>());

    //search
    for (int i = 0; i < weak.size(); i++) {
        ans = false;

        //select -> 최대 dist 크기까지 탐색한다.
        for (int limit = 1; limit <= dist.size(); limit++) {
            // limit 만큼 선택
            select(0,limit,dist,dq);

            if(ans) {//해당 조합이 전부 커버했으면
                answer = min(answer,limit);
                break;
            }
        }
        dq.push_back(n+weak[i]);
        dq.pop_front();
    }
    if(answer == 999999) answer = -1;
    return answer;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    // cout << solution(12, {1,5,6,10},{1,2,3,4}); // result: 2 pass (1)
    // cout << solution(12, {1,3,4,9,10},{3,5,7}); // result: 1 pass (2)
    // cout << solution(200, {0,10,50,80,120,160},{1,10,5,40,30}); // result: 3 pass (3)
    // cout << solution(30, {0,3,11,21},{10,4}); // result: 2 pass (4)
    // cout << solution(50, {1},{6}); // result: 1 pass (5)
    // cout << solution(12, {10,0},{1,2}); // result: 1 pass (6)
    // cout << solution(200, {0,100},{1,1}); // result: 2 pass (7)

    return 0;
}