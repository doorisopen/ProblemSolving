// 30
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <functional>
using namespace std;

char n[100001];

int main(void){
	int tmp = 0, len = 0;
	scanf("%s", n);
	len = strlen(n);
	sort(n, n + len, greater<char>());
	
	for(int i = 0; i < len; i++){
		tmp += (n[i] - '0');
	}
	
	if( tmp % 3 == 0 && n[len - 1] == '0'){
		printf("%s", n);	
	}else {
		printf("-1");
	}
	
	return 0;	
}

