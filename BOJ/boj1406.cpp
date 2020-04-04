#include <bits/stdc++.h>
using namespace std;
#define idx 10
// https://www.acmicpc.net/problem/1406
const int MAX = 1000005;
char dat[MAX];
int pre[MAX], nxt[MAX];
int unused = 1;


void insert(int addr, char c) {
    dat[unused] = c;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr) {
    nxt[pre[addr]] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

void traverse(){
    int cur = nxt[0];
    while (cur != -1)
    {
        cout << dat[cur];
        cur = nxt[cur];
    }
    cout << "\n";
}
void log() {
    cout << "==========\ndat= ";
    for(int i = 0; i < idx; i++) {
        cout << dat[i] << "  ";
    }
    cout << "\npre= ";
    for(int i = 0; i < idx; i++) {
        cout << pre[i] << "  ";
    }
    cout << "\nnxt= ";
    for(int i = 0; i < idx; i++) {
        cout << nxt[i] << "  ";
    }
    cout << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false); 
    fill(pre, pre+MAX, -1);
    fill(nxt, nxt+MAX, -1);
    string s;
    cin >> s;

    int cursor = 0;
    for(int i = 0; i < s.length(); i++) {
        insert(i, s[i]);
        cursor++;
    }
    
    int tc;
    cin >> tc;

    for(int i = 0; i < tc; i++) {
        char command;
        cin >> command;
        if(command == 'L') { // 커서 왼쪽으로 1 이동
            if(pre[cursor] != -1) cursor = pre[cursor];
        }
        else if(command == 'D') { // 커서 오른쪽으로 1 이동
            if(nxt[cursor] != -1) cursor = nxt[cursor];
        }
        else if(command == 'B') {// 커서 왼쪽 문자 삭제
            if(cursor != 0) {
                erase(cursor);
                cursor = pre[cursor];
            }
        }
        else { // $문자 커서 왼쪽에 문자 추가
            char add;
            cin >> add;
            insert(cursor, add);
            cursor = nxt[cursor];
        }
    }
    traverse();
    return 0;
}