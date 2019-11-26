// BOJ 1152 단어의 개수 
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

string word;
int i = 0, endIdx = 0, cnt = 0; 
int main(void) {
	
	char data[1000001]; 
	fgets(data,1000001,stdin);
	
	if(data[0] == ' ') i=1;
	while(data[i] != NULL){
		if(data[i] == ' ') {
			cnt++;
		}
		i++;
	}
	if(data[i-2] == ' ') cnt--;
	printf("%d",cnt+1); 
	return 0;
} 
