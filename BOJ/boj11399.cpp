// ATM
#include <iostream>
#include <algorithm>
using namespace std;

int t[1000];

int main(void){
	int p, tmp = 0, min = 0;
	cin >> p;
	
	for(int i = 0; i < p; i++){
		cin >> t[i];
	}
	sort(t, t+p);
	for(int i = 0; i < p; i++){
		tmp += t[i];
		min += tmp;
	}
	
	
	printf("%d",min);
	return 0;
}
