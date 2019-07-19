// °Å½º¸§µ· 
#include <iostream>
using namespace std;

int coin[6] = {500, 100, 50, 10, 5, 1};

int main(void){
	int n, i = 0, cnt = 0;
	int rest;
	cin >> n;
	rest = 1000 - n;
	
	while(rest > 0 || i < 6){
		if(rest/coin[i] != 0){
			//cout << coin[i] <<":"<< rest / coin[i];
			cnt += rest / coin[i];
			rest = rest % coin[i]; 
			//cout << " rest :" << rest << " cnt :" << cnt <<endl;
		}
		i++;
	}
	cout << cnt;
	
	return 0;
}
