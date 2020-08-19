#include <iostream>
using namespace std;
int main(void){
	int a = 1;
    int b = 2;
    a^=b^=a^=b;
    cout << a << " " << b;
    return 0;
}