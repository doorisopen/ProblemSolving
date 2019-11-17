// 2163 초콜릿 자르기

#include <iostream>

using namespace std;

int n,m;

int main(void) {
	cin >> n >> m;
	/* 설명 
		m칸의 가로를 자르면 m-1, 세로가 n칸인 초콜릿 m개 
		n칸의 세로를 자르면 n-1 
		총 자른 횟수 m-1 + (n-1)*m = n*m-1 
	*/
	cout << n*m-1;
	
	return 0;
} 
 
