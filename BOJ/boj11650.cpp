// 11650 좌표 정렬하기
#include <stdio.h> 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int num;
pair<int,int> a[100001];


int main(void){
	
	scanf("%d",&num);
	for(int i=0; i < num; i++){
		scanf("%d %d",&a[i].first, &a[i].second);
	}
	
	sort(a, a+num);

	for(int i=0; i < num; i++){
		printf("%d %d\n",a[i].first, a[i].second);
	}
	
	return 0;
}

