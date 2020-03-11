
[문제 링크](https://programmers.co.kr/learn/courses/30/lessons/42746)

## c++

```
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
bool cmp(string &a, string &b) {
    return a + b < b + a ?  true : false;
}
 
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    
    for (int i = 0; i < numbers.size(); i++) {
        v.push_back(to_string(numbers.at(i)));
    }
    
    sort(v.begin(), v.end(), cmp);
    
    // for(int i = 0; i < v.size(); i++) {
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    
    while (!v.empty()) {
        answer += v.back();
        // cout << answer << endl;
        v.pop_back();
    }
    
    if (answer[0] == '0')
        return "0";
    
    return answer;
}

// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// vector<string> v;
// vector<string> arr;
// bool selected[100001];
// int maxnum = 0;

// void print() {
// 	for(int i = 0; i < v.size(); i++) {
// 		cout << v[i];	
// 	}
// 	printf("\n");
// }
// void isMaxCheck() {
//     string tmp = "";
//     for(int i = 0; i < v.size(); i++) {
// 		tmp+=v[i];	
// 	}
//     maxnum = max(maxnum, stoi(tmp));
// }


// void dfs(int cnt, int size) {
//     if(cnt == size) {
//         // print();
//         isMaxCheck();
//         return;
//     }
    
//     for(int i = 0; i < size; i++) {
//         if(selected[i] == true) continue;
//         selected[i] = true;
        
//         v.push_back(arr[i]);
// 		dfs(cnt+1, size);
// 		v.pop_back();
// 		selected[i] = false;
//     }
// }

// string solution(vector<int> numbers) {
//     string answer = "";
    
//     for(int i = 0; i < numbers.size(); i++) {
//         arr.push_back(to_string(numbers[i]));
//     }
//     sort(arr.begin(), arr.end());
    
//     dfs(0, arr.size());
//     answer = to_string(maxnum);
//     return answer;
// }
```