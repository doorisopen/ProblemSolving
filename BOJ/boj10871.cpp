// 10871 - X���� ���� ��
#include <iostream>
using namespace std;

int main(void) {
	
	int testcase, num, a;
	cin >> testcase >> a;
	
	for(int i = 0; i < testcase; i++){
		cin >> num;
		if(a > num){
			cout << num << ' ';
		}
	}

	return 0;
}
