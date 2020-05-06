#include <bits/stdc++.h>
using namespace std;
#define ll long long

int arr[1010][1010];

int main() {
    
    int n, m;
    scanf("%d %d",&n ,&m);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%1d",&arr[i][j]);
        }
    }

    int len = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(arr[i][j] != 0) {
                arr[i][j] = min(arr[i-1][j-1], min(arr[i-1][j], arr[i][j-1])) + 1;
                if(len < arr[i][j]) len = arr[i][j];
            }
        }
    }

    printf("%d", len*len);

    return 0;
}