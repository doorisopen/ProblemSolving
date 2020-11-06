/* 
 * summer/winter codgin 2019, 2단계
 * 멀쩡한 사각형
 */
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if(b==0) return a;
	return gcd(b, a%b);
}
long long solution(int w,int h) {
	if(w<h) {w^=h^=w^=h;}
    long long W = w, H = h;
    long long answer = 0;
    long long area = W*H;
    long long cross = (W+H)-gcd(W,H);
    return answer = area-cross;
}