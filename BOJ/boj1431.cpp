// �ø��� ��ȣ
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string array[1000];
int n;

int getSum(string a){
	int length = a.length(), sum = 0;
	for(int i = 0; i < length; i++){
		// ������ ��쿡�� ���Ѵ�. 
		if(a[i] -'0' <= 9 && a[i] - '0' >= 0){
			sum += a[i] - '0';
		}
	}
	return sum;
} 

bool compare(string array1, string array2){
	// ���̰� ª�� ����
	if(array1.length() < array2.length()){
		return 1;
	} else if(array1.length() > array2.length()){
		return 0;
	}
	// ���̰� ���� ��� 
	else {
		int sum1 = getSum(array1);
		int sum2 = getSum(array2);
		// ���ڿ� ���Ե� ���� �ٸ��� 
		if( sum1 != sum2 ){
			// ���� ���� ���� ���� 
			return sum1 < sum2;
		}else{
			// ���������� ����
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
