#include <bits/stdc++.h>
#define maxn 150052

using namespace std;

int n, m, d;
long long dp[3][maxn], q[maxn], a[maxn], b[maxn], t[maxn];

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> d;
    for (int i = 1; i <= m; i++)
        cin >> a[i] >> b[i] >> t[i];
    for (int h = 1; h <= m; h++)
    {
        int i = 1;
        memset(q, 0, sizeof(q));
        int l = 1, r = 0, k = 1;
        long long len = (t[h] - t[h-1])*d;
        for (int j = 1; j <= n; j++)
        {
            while(l <= r && q[l] < j - len)
                l ++;
            while (k <= n && k <= j+len)
            {
                while (r >= l && dp[i-1][k] >= dp[i-1][q[r]])
                    r--;
                q[++r] = k;
                k++;
            }
            dp[i][j] = dp[i-1][q[l]] + b[h] - abs(j-a[h]);
        }
        //for (int j = 1; j <= n; j++) cout << dp[i][j] << " "; cout << endl;
        swap(dp[1], dp[0]);
    }
    cout << *max_element(dp[0] + 1, dp[0]+n+1);
    return 0;
}
