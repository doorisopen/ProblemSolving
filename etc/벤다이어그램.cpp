#include <bits/stdc++.h>
using namespace std;
#define ll long long

int arr1[3] = {1,5,4};
int arr2[3] = {2,4,9};
int visit[10];

//기수정렬을 활용한 벤다이어그램
void init() {
    fill(visit, visit+10, 0);
    for (int i = 0; i < 3; i++) {
        visit[arr1[i]]++;
        visit[arr2[i]]++;
    }
}

void myUnion() {
    init();
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < visit[i]; j++){
            cout << i << " ";
        }
    }
    cout << "\n";
}

void myIntersection() {
    init();
    for (int i = 0; i < 10; i++) {
        if(visit[i] > 1) {
            cout << i << " ";
        }
    }
    cout << "\n";
}

void arr1_difference() {
    init();
    for (int i = 0; i < 3; i++) {
        if(visit[arr1[i]] == 1) {
            cout << arr1[i] << " ";
        }
    }
    cout << "\n";
}

void arr2_difference() {
    init();
    for (int i = 0; i < 3; i++) {
        if(visit[arr2[i]] == 1) {
            cout << arr2[i] << " ";
        }
    }
    cout << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //arr1 : 1 5 4
    //arr2 : 2 4 9

    myUnion(); // 합집합: 1 2 4 4 5 9
    myIntersection(); // 교집합: 4
    arr1_difference(); // arr1-arr2: 1 5
    arr2_difference(); // arr2-arr1: 2 9

    return 0;
}