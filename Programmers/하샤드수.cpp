/*
 * 연습문제
 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(int x) {
    int temp = x;
    int val = 0;
    while(temp) {
        val += temp%10;
        temp/=10;
    }
    cout << val;
    return x%val==0?true:false;
}