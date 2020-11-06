#include <bits/stdc++.h>

using namespace std;


const int maxn = 300;

int n, m;
int a[maxn], b[maxn];
int dp[maxn][2000];

int main()
{
    //freopen("inp.txt", "r" , stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m;  j++)
        {
            for (int k = 0; k < 1024; k++)
            {
                if (dp[i-1][k])
                {
                    dp[i][k|(a[i]&b[j])] = 1;
                }
            }
        }
    }
    for (int i = 0; i < 1024; i++)
    {
        if (dp[n][i] == 1)
        {
            cout << i;
            cout << endl;
            return 0;
        }
    }
    return 0;
}
