// 시리얼 번호
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string array[1000];
int n;

int getSum(string a){
	int length = a.length(), sum = 0;
	for(int i = 0; i < length; i++){
		// 숫자인 경우에만 더한다. 
		if(a[i] -'0' <= 9 && a[i] - '0' >= 0){
			sum += a[i] - '0';
		}
	}
	return sum;
} 

bool compare(string array1, string array2){
	// 길이가 짧은 순서
	if(array1.length() < array2.length()){
		return 1;
	} else if(array1.length() > array2.length()){
		return 0;
	}
	// 길이가 같은 경우 
	else {
		int sum1 = getSum(array1);
		int sum2 = getSum(array2);
		// 글자에 포함된 합이 다를때 
		if( sum1 != sum2 ){
			// 작은 것을 먼저 선택 
			return sum1 < sum2;
		}else{
			// 사전순으로 정렬
			return array1 < array2;	
		}
		  
	}
}

int main(void) {
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> array[i];
	}
	sort(array, array+n, compare);
	
	for(int i=0; i<n; i++){
		if(i>0 && array[i] == array[i-1]){
			continue;
		} else {
			cout << array[i] << endl;
		}
	}
	return 0;
}
