// 수 정렬하기 2
#include <stdio.h>
#include <algorithm>
using namespace std;
int data[1000001];

int main(void){
	int testcase;
	scanf("%d",&testcase);
	for(int i = 0; i < testcase; i++){
		scanf("%d",&data[i]);
	}
	sort(data, data + testcase);	
	
	
	for(int j = 0; j < testcase; j++){
		printf("%d\n",data[j]);
	}
	return 0;
}
