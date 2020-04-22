#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int num, check = 1;
        deque<int> dq;
        string str, arr;
        cin >> str; // 명령어
        cin >> num; // 원소 개수
        cin >> arr; // 원소

        //배열 저장
        string tmp = "";
        for(int j = 0; j < arr.length(); j++) {
            if(arr[j] == '[') {
                continue;
            } else if('0' <= arr[j] && arr[j] <= '9') {
                tmp += arr[j];
            } else if(arr[j] == ',' || arr[j] == ']') {
                if(!tmp.empty()) {
                    dq.push_back(stoi(tmp));
                    tmp.clear();
                }
            }
        }

        //명령 수행
        bool reverse = false;
        for(int k = 0; k < str.length(); k++) {
            if(str[k] == 'R') {
                reverse ? reverse = false : reverse = true;
            } else if(str[k] == 'D') {
                if(dq.size() > 0) {
                    if(reverse) {
                        dq.pop_back();
                    } else {
                        dq.pop_front();
                    }
                } else {
                    check = 0;
                    break;
                }
            }
        }

        if(check == 0) {
            printf("error\n");
        } else {
            // 원소 출력
            if(reverse) {
                printf("[");
                for(int s = dq.size()-1; s >= 0 ; s--) {
                    if(s == 0) {
                        printf("%d",dq[s]);
                    } else {
                        printf("%d,",dq[s]);
                    }
                }
                printf("]\n");
            } else {
                printf("[");
                for(int s = 0; s < dq.size(); s++) {
                    if(s == dq.size()-1) {
                        printf("%d",dq[s]);
                    } else {
                        printf("%d,",dq[s]);
                    }
                }
                printf("]\n");
            }

        }
    }
    return 0;
}