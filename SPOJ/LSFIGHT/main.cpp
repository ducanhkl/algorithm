#include <bits/stdc++.h>

using namespace std;

int a[600][600], dp[600][600];
int n;
int dinh(int x)
{
    if (x > n)
        return x-n;
    return x;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
    {
        cin >> a[i][j];
        dp[i][dinh(i+1)] = 1;
    }
    for (int l = 3; l <= n+1; l++)
        for (int i = 1; i <= n; i++)
    {
        int k = i+l-1;
        int m = dinh(k);
        if (i == 3 && m == 1)
            n = n;
        for (int j = i+1; j <= k; j++)
            if (dp[i][dinh(j)] && dp[dinh(j)][m] && (a[i][dinh(j)] || a[m][dinh(j)]))
        {
            dp[i][m] = 1;
            break;
        }
    }
    int dem = 0;
    for (int i = 1; i <= n; i++)
        if (dp[i][i])
            dem ++;
    cout << dem << endl;
    for (int i = 1; i <= n; i++)
        if (dp[i][i])
            cout << i << endl;
    return 0;
}
