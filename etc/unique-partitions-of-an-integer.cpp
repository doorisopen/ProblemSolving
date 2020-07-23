//https://www.geeksforgeeks.org/generate-unique-partitions-of-an-integer/
#include <bits/stdc++.h>
using namespace std;
/**
  Input: n = 2
  Output: 
  2
  1 1

  Input: n = 3
  Output: 
  3
  2 1
  1 1 1
  Note: 2+1 and 1+2 are considered as duplicates.

  Input: n = 4
  Output: 
  4
  3 1
  2 2
  2 1 1
  1 1 1 1 
*/

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) 
       cout << arr[i] << " "; 
    cout << endl;
}
void uniqueParts(int n) {
    int arr[n];
    int last = 0;//last element
    arr[last] = n;//init first partition

    while (1) {
        printArray(arr, last+1);

        int rem_val = 0;
        while (last >= 0 && arr[last] == 1) {
            rem_val += arr[last];
            last--;
        }
        if(last < 0) return;
        arr[last]--;
        rem_val++;

        while (rem_val > arr[last]) {
            arr[last+1] = arr[last];
            rem_val -= arr[last];
            last++;
        }
        arr[last+1] = rem_val;
        last++;
    }
    
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    cout << "\nn=2 Partitions\n";
    uniqueParts(2);
    cout << "\nn=3 Partitions\n";
    uniqueParts(3);
    cout << "\nn=4 Partitions\n";
    uniqueParts(4);
    cout << "\nn=5 Partitions\n";
    uniqueParts(5);

    return 0;
}