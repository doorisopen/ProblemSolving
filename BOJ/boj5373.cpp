/* 
 * 5373 큐빙
 * 방향 -> 색상
 * U 윗쪽 -> 흰색 w
 * D 아래쪽 -> 노랑 y
 * F 앞쪽 -> 빨강 r
 * B 뒷쪽 -> 주황 o
 * L 왼쪽 -> 초록 g
 * R 오른쪽 -> 파랑 b
 */
#include <bits/stdc++.h>
using namespace std;

char cube[7][4][4];
string colors = "wyrogb";

void init() {
	for (int i = 0; i < 6; i++) {
		char color = colors[i];
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				cube[i][j][k] = color;
			}
		}
	}
}
void p() {
	for (int j = 0; j < 3; j++) {
		for (int k = 0; k < 3; k++) {
			cout << cube[0][j][k];
		}
		cout << "\n";
	}
}
void p2() {
	for (int i = 0; i < 6; i++) {
		cout << "=======> " << i << "\n";		
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				cout << cube[i][j][k];
			}
			cout << "\n";
		}
	}
}
void runCube(char dir, bool isClockwise) {
	vector<char> tmpCube;
	char tmp[7][4][4];
	//cube copy
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				tmp[i][j][k] = cube[i][j][k];
			}
		}
	}
	if(isClockwise) {//순 방향
		if(dir == 'U') {//0 -> 3 5 2 4
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cube[0][i][j] = tmp[0][3-1-j][i];
				}
			}
			tmpCube.push_back(cube[4][0][0]);
			tmpCube.push_back(cube[4][0][1]);
			tmpCube.push_back(cube[4][0][2]);

			cube[4][0][0] = cube[2][0][0];
			cube[4][0][1] = cube[2][0][1];
			cube[4][0][2] = cube[2][0][2];

			cube[2][0][0] = cube[5][0][0];
			cube[2][0][1] = cube[5][0][1];
			cube[2][0][2] = cube[5][0][2];

			cube[5][0][0] = cube[3][2][2];
			cube[5][0][1] = cube[3][2][1];
			cube[5][0][2] = cube[3][2][0];

			cube[3][2][2] = tmpCube[0];
			cube[3][2][1] = tmpCube[1];
			cube[3][2][0] = tmpCube[2];
		} else if(dir == 'D') {//1 -> 2 5 3 4
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cube[1][i][j] = tmp[1][3-1-j][i];
				}
			}
			tmpCube.push_back(cube[5][2][0]);
			tmpCube.push_back(cube[5][2][1]);
			tmpCube.push_back(cube[5][2][2]);

			cube[5][2][0] = cube[2][2][0];
			cube[5][2][1] = cube[2][2][1];
			cube[5][2][2] = cube[2][2][2];

			cube[2][2][0] = cube[4][2][0];
			cube[2][2][1] = cube[4][2][1];
			cube[2][2][2] = cube[4][2][2];

			cube[4][2][0] = cube[3][0][2];
			cube[4][2][1] = cube[3][0][1];
			cube[4][2][2] = cube[3][0][0];

			cube[3][0][2] = tmpCube[0];
			cube[3][0][1] = tmpCube[1];
			cube[3][0][0] = tmpCube[2];
		} else if(dir == 'F') {//2 -> 0 5 1 4
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cube[2][i][j] = tmp[2][3-1-j][i];
				}
			}
			tmpCube.push_back(cube[5][0][0]);
			tmpCube.push_back(cube[5][1][0]);
			tmpCube.push_back(cube[5][2][0]);

			cube[5][0][0] = cube[0][2][0];
			cube[5][1][0] = cube[0][2][1];
			cube[5][2][0] = cube[0][2][2];

			cube[0][2][0] = cube[4][2][2];
			cube[0][2][1] = cube[4][1][2];
			cube[0][2][2] = cube[4][0][2];

			cube[4][2][2] = cube[1][0][2];
			cube[4][1][2] = cube[1][0][1];
			cube[4][0][2] = cube[1][0][0];

			cube[1][0][2] = tmpCube[0];
			cube[1][0][1] = tmpCube[1];
			cube[1][0][0] = tmpCube[2];
		} else if(dir == 'B') {//3 -> 0 4 1 5
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cube[3][i][j] = tmp[3][3-1-j][i];
				}
			}
			tmpCube.push_back(cube[5][0][2]);
			tmpCube.push_back(cube[5][1][2]);
			tmpCube.push_back(cube[5][2][2]);

			cube[5][0][2] = cube[1][2][2];
			cube[5][1][2] = cube[1][2][1];
			cube[5][2][2] = cube[1][2][0];

			cube[1][2][2] = cube[4][2][0];
			cube[1][2][1] = cube[4][1][0];
			cube[1][2][0] = cube[4][0][0];

			cube[4][2][0] = cube[0][0][0];
			cube[4][1][0] = cube[0][0][1];
			cube[4][0][0] = cube[0][0][2];

			cube[0][0][0] = tmpCube[0];
			cube[0][0][1] = tmpCube[1];
			cube[0][0][2] = tmpCube[2];
		} else if(dir == 'L') {//4 -> 0 2 1 3
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cube[4][i][j] = tmp[4][3-1-j][i];
				}
			}
			tmpCube.push_back(cube[3][0][0]);
			tmpCube.push_back(cube[3][1][0]);
			tmpCube.push_back(cube[3][2][0]);

			cube[3][0][0] = cube[1][0][0];
			cube[3][1][0] = cube[1][1][0];
			cube[3][2][0] = cube[1][2][0];

			cube[1][0][0] = cube[2][0][0];
			cube[1][1][0] = cube[2][1][0];
			cube[1][2][0] = cube[2][2][0];

			cube[2][0][0] = cube[0][0][0];
			cube[2][1][0] = cube[0][1][0];
			cube[2][2][0] = cube[0][2][0];

			cube[0][0][0] = tmpCube[0];
			cube[0][1][0] = tmpCube[1];
			cube[0][2][0] = tmpCube[2];
		} else if(dir == 'R') {//5 -> 0 3 1 2
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cube[5][i][j] = tmp[5][3-1-j][i];
				}
			}
			tmpCube.push_back(cube[2][0][2]);
			tmpCube.push_back(cube[2][1][2]);
			tmpCube.push_back(cube[2][2][2]);

			cube[2][0][2] = cube[1][0][2];
			cube[2][1][2] = cube[1][1][2];
			cube[2][2][2] = cube[1][2][2];

			cube[1][0][2] = cube[3][0][2];
			cube[1][1][2] = cube[3][1][2];
			cube[1][2][2] = cube[3][2][2];

			cube[3][0][2] = cube[0][0][2];
			cube[3][1][2] = cube[0][1][2];
			cube[3][2][2] = cube[0][2][2];

			cube[0][0][2] = tmpCube[0];
			cube[0][1][2] = tmpCube[1];
			cube[0][2][2] = tmpCube[2];
		}
	} else {//==============역 방향
		if(dir == 'U') {//0 -> 3 4 2 5
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cube[0][i][j] = tmp[0][j][3-1-i];
				}
			}
			tmpCube.push_back(cube[5][0][0]);
			tmpCube.push_back(cube[5][0][1]);
			tmpCube.push_back(cube[5][0][2]);

			cube[5][0][0] = cube[2][0][0];
			cube[5][0][1] = cube[2][0][1];
			cube[5][0][2] = cube[2][0][2];

			cube[2][0][0] = cube[4][0][0];
			cube[2][0][1] = cube[4][0][1];
			cube[2][0][2] = cube[4][0][2];

			cube[4][0][0] = cube[3][2][2];
			cube[4][0][1] = cube[3][2][1];
			cube[4][0][2] = cube[3][2][0];

			cube[3][2][2] = tmpCube[0];
			cube[3][2][1] = tmpCube[1];
			cube[3][2][0] = tmpCube[2];
		} else if(dir == 'D') {//1 -> 2 4 3 5
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cube[1][i][j] = tmp[1][j][3-1-i];
				}
			}
			tmpCube.push_back(cube[4][2][0]);
			tmpCube.push_back(cube[4][2][1]);
			tmpCube.push_back(cube[4][2][2]);

			cube[4][2][0] = cube[2][2][0];
			cube[4][2][1] = cube[2][2][1];
			cube[4][2][2] = cube[2][2][2];

			cube[2][2][0] = cube[5][2][0];
			cube[2][2][1] = cube[5][2][1];
			cube[2][2][2] = cube[5][2][2];

			cube[5][2][0] = cube[3][0][2];
			cube[5][2][1] = cube[3][0][1];
			cube[5][2][2] = cube[3][0][0];

			cube[3][0][2] = tmpCube[0];
			cube[3][0][1] = tmpCube[1];
			cube[3][0][0] = tmpCube[2];
		} else if(dir == 'F') {//2 -> 0 4 1 5
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cube[2][i][j] = tmp[2][j][3-1-i];
				}
			}
			tmpCube.push_back(cube[5][0][0]);
			tmpCube.push_back(cube[5][1][0]);
			tmpCube.push_back(cube[5][2][0]);

			cube[5][0][0] = cube[1][0][2];
			cube[5][1][0] = cube[1][0][1];
			cube[5][2][0] = cube[1][0][0];

			cube[1][0][2] = cube[4][2][2];
			cube[1][0][1] = cube[4][1][2];
			cube[1][0][0] = cube[4][0][2];

			cube[4][2][2] = cube[0][2][0];
			cube[4][1][2] = cube[0][2][1];
			cube[4][0][2] = cube[0][2][2];

			cube[0][2][0] = tmpCube[0];
			cube[0][2][1] = tmpCube[1];
			cube[0][2][2] = tmpCube[2];
		} else if(dir == 'B') {//3 -> 0 5 1 4
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cube[3][i][j] = tmp[3][j][3-1-i];
				}
			}
			tmpCube.push_back(cube[4][2][0]);
			tmpCube.push_back(cube[4][1][0]);
			tmpCube.push_back(cube[4][0][0]);

			cube[4][2][0] = cube[1][2][2];
			cube[4][1][0] = cube[1][2][1];
			cube[4][0][0] = cube[1][2][0];

			cube[1][2][2] = cube[5][0][2];
			cube[1][2][1] = cube[5][1][2];
			cube[1][2][0] = cube[5][2][2];

			cube[5][0][2] = cube[0][0][0];
			cube[5][1][2] = cube[0][0][1];
			cube[5][2][2] = cube[0][0][2];

			cube[0][0][0] = tmpCube[0];
			cube[0][0][1] = tmpCube[1];
			cube[0][0][2] = tmpCube[2];
		} else if(dir == 'L') {//4 -> 0 3 1 2
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cube[4][i][j] = tmp[4][j][3-1-i];
				}
			}
			tmpCube.push_back(cube[2][0][0]);
			tmpCube.push_back(cube[2][1][0]);
			tmpCube.push_back(cube[2][2][0]);
			
			cube[2][0][0] = cube[1][0][0];
			cube[2][1][0] = cube[1][1][0];
			cube[2][2][0] = cube[1][2][0];

			cube[1][0][0] = cube[3][0][0];
			cube[1][1][0] = cube[3][1][0];
			cube[1][2][0] = cube[3][2][0];

			cube[3][0][0] = cube[0][0][0];
			cube[3][1][0] = cube[0][1][0];
			cube[3][2][0] = cube[0][2][0];

			cube[0][0][0] = tmpCube[0];
			cube[0][1][0] = tmpCube[1];
			cube[0][2][0] = tmpCube[2];
		} else if(dir == 'R') {//5 -> 0 2 1 3
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cube[5][i][j] = tmp[5][j][3-1-i];
				}
			}
			tmpCube.push_back(cube[3][0][2]);
			tmpCube.push_back(cube[3][1][2]);
			tmpCube.push_back(cube[3][2][2]);

			cube[3][0][2] = cube[1][0][2];
			cube[3][1][2] = cube[1][1][2];
			cube[3][2][2] = cube[1][2][2];

			cube[1][0][2] = cube[2][0][2];
			cube[1][1][2] = cube[2][1][2];
			cube[1][2][2] = cube[2][2][2];

			cube[2][0][2] = cube[0][0][2];
			cube[2][1][2] = cube[0][1][2];
			cube[2][2][2] = cube[0][2][2];

			cube[0][0][2] = tmpCube[0];
			cube[0][1][2] = tmpCube[1];
			cube[0][2][2] = tmpCube[2];
		}
	}
}

void solution() {
	//input
    int t, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		//init
		init();
		
		for (int j = 0; j < n; j++) {
			string command;
			cin >> command;

			char dir = command[0];
			bool isClockwise = command[1] == '+' ? true : false;
			runCube(dir, isClockwise);
			// cout << dir << commands[j][1] <<  "<<==";
			// p2();
		}
		// cout << "---------result---------\n";
		p();
	}
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
	solution();
	return 0;
}