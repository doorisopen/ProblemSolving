// 2163 ���ݸ� �ڸ���

#include <iostream>

using namespace std;

int n,m;

int main(void) {
	cin >> n >> m;
	/* ���� 
		mĭ�� ���θ� �ڸ��� m-1, ���ΰ� nĭ�� ���ݸ� m�� 
		nĭ�� ���θ� �ڸ��� n-1 
		�� �ڸ� Ƚ�� m-1 + (n-1)*m = n*m-1 
	*/
	cout << n*m-1;
	
	return 0;
} 
 
