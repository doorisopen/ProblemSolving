/*
 * 연습문제
 */
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) {
    auto pos = min_element(arr.begin(),arr.end())-arr.begin();
    arr.erase(arr.begin()+pos);
    if(arr.size() == 0) arr.push_back(-1);
    return arr;
}