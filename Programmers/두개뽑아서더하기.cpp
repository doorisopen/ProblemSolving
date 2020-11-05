/*
 * 월간 코드 챌린지 시즌1
 */
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> s;
    for(int i = 0; i < numbers.size(); i++) {
        for(int j = i; j < numbers.size(); j++) {
            if(i!=j) {                
                s.insert(numbers[i]+numbers[j]);
            }
        }
    }
    for(auto i : s) {
        answer.push_back(i);
    }
    return answer;
}