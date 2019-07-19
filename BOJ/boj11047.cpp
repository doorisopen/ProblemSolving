// µ¿Àü 0 
#include <iostream>
#include <algorithm>

using namespace std;

int n[10];
int k;

int main(void){
	int Cnum, min = 0;
	cin >> Cnum >> k;
	
	for(int i = 0; i < Cnum; i++){
		cin >> n[i];
	}
	while(k != 0 && Cnum > 0){
		if(k / n[Cnum-1] != 0){
			min += k / n[Cnum-1];
			k = k % n[Cnum-1];	
		}
		Cnum--;
	}
	cout << min;
	
	return 0;
}
