#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;
/**
 * space : O(1)
 * time : O(n)
 */
int main(void) {
    int data1[] = {3, 6, 2, 4, 2, 3, 4, 3, 3, -4, -4, -4};
    int data2[] = {1, 1, 1, 2, 2, 3, 3, 3, 3, -4, -4, -5};

    /*
        짝수 자릿수: ood value
        홀수 자릿수: even value
        갯수 홀수: 1
        갯수 짝수: 0
    */
    int data = 0;
    for (int i = 0; i < 12; i++) {
        if(data1[i] >= 0) {
            data ^= 1 << (2*data1[i]);
        } else {
            data ^= 1 << (-2*data1[i]+1); 
        }
        cout << bitset<32>(data) << "\n";
    }

                               
    //홀수 : - 짝수 : +
    cout << "===\n";
    int i = 0;
    while (data) {
        cout << bitset<32>(data) << "\n";
        if(data & 1) {
            cout << i << "\n";
        } else if(data & 2) {
            cout << (-1 * i) << "\n";
        }
        i+=1;
        data >>= 2;

    }
    return 0;
}

/*python
def solution(input):
    data = 0

    # O(n)
    for val in input:
        if val >= 0:
            data ^= 1 << (2 * val)
        else:
            data ^= 1 << (-2 * val + 1)

    i = 0
    # worst case : O(n)
    while data:
        if data & 1:
            print(i)
        elif data & 2:
            print(-1 * i)
        i += 1
        data >>= 2

    return data
*/