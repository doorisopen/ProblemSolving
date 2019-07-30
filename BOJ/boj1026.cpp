// º¸¹° 
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[101];
int b[101];
bool compare(int a, int b){
	return a > b;
}

int main(void){
	int num, tmp = 0;
	scanf("%d",&num);
	
	for(int i = 0; i < num; i++) scanf("%d",&a[i]);
	for(int i = 0; i < num; i++) scanf("%d",&b[i]);
	
	sort(a, a + num);
	sort(b, b + num, compare);
	
	for(int i = 0; i < num; i++){
		tmp += a[i] * b[i];
	}
	printf("%d",tmp);
	return 0;
} 
