#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;
char a[maxn][maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    int test;
    cin >> test;
    while (test--)
    {
        int n, m;
        int res = 0;
        cin >> n >> m;
        for (int i  = 1; i <= n ;i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        for (int i = 1; i <= n-1; i++)
            if (a[i][m] == 'R')
                res ++;
        for (int i = 1; i <= m-1; i++)
            if (a[n][i] == 'D')
                res ++;
        cout << res << endl;
    }
    return 0;
}
