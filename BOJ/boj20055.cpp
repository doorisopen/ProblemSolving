/* 
 * 20055 컨베이어 벨트 위의 로봇
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

deque<int> convey;//{내구도}
deque<int> robot;//{물건 번호}
int n, k, lv, robotId = 1, cnt = 0;

void solution() {
	//input
	cin >> n >> k;
	for (int i = 0; i < n*2; i++) {
		int val;
		cin >> val; 
		convey.push_back(val);
		robot.push_back(0);
	}

	while(cnt < k) {
		lv++;

		//1.벨트 이동
		convey.push_front(convey.back()); convey.pop_back();
		robot.push_front(robot.back()); robot.pop_back();
		robot[n-1] = 0;

		//2.로봇 한칸 전진
		priority_queue<pi> tmp;
		for (int i = 0; i < robot.size(); i++) {
			if(robot[i] > 0) tmp.push({-robot[i],i});
		}
		//오름차순으로 확인
		while(!tmp.empty()) {
			auto item = tmp.top(); tmp.pop();
			int curId = -item.first, curIdx = item.second;
			int next;
			if(curIdx != robot.size()-1) {
				next = curIdx+1;
			} else {
				next = 0;
			}
			if(convey[next] > 0 && robot[next] == 0) {
				robot[next] = robot[curIdx];
				robot[curIdx] = 0;
				convey[next] -= 1;
				if(convey[next] == 0) cnt++;
			}
		}
		robot[n-1] = 0;
		
		//3.로봇 투입
		if(convey[0] > 0) {
			robot[0] = robotId++;
			convey[0] -= 1;
			if(convey[0] == 0) cnt++;
		}
	}
	cout << lv << "\n";
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
	solution();
	return 0;
}