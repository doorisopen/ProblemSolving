// �ܾ� ����
#include <iostream>
#include <algorithm>

using namespace std;

string array[20000];
int n;

bool compare(string array1, string array2){
	// ���̰� ª�� ����
	if(array1.length() < array2.length()){
		return 1;
	} else if(array1.length() > array2.length()){
		return 0;
	}
	// ���̰� ���� ��� 
	else {
		return array1 < array2; // ���������� ���� 
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
