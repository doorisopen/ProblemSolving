// 1629 - °ö¼À 
#include <stdio.h> 

long long int tmp = 1;
long long int a, b, c;
void div(long long int a, long long int b) {

	while(b>0) {
		if(b%2) {
			tmp *= a;
			tmp %= c;		
		}
		a *= a;
		a %= c;
		b /= 2;
	}
	printf("%lld",tmp);
}

int main(void) {
	
	scanf("%lld %lld %lld",&a ,&b ,&c);
	div(a%c,b);
	
	return 0;
}
