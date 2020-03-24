#include <bits/stdc++.h>
using namespace std;

/*
A 도 배 0:1
B 개 배 0:2
C 걸 배 0:3
D 윷 배 0:4
E 모 등 1:4
*/

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, back = 0, front = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int i = 0; i < 4; i++)
        {
            cin >> N;
            if (N == 0){ back++; }
            else { front++; }
        }
        if(back == 1) { cout << "A\n"; }
        else if (back == 2){ cout << "B\n"; }
        else if (back == 3){ cout << "C\n"; }
        else if (back == 4){ cout << "D\n"; }
        else if( front == 4) { cout << "E\n"; }
        back = 0;
        front = 0;
    }
    return 0;
}