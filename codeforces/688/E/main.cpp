#include <bits/stdc++.h>
#define maxn 600

using namespace std;

int n, k;
int dp[2][505][505];
int a[505];
vector <int> ans;

int main()
{
    memset(dp, 0, sizeof(dp));
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0;  j <= k; j++)
            for (int h = 0; h <= j; h++)
    {
        int now = i%2;
        int last = (i+1)%2;
        dp[now][j][h] = dp[last][j][h];
        if (a[i] <= j)
        {
            dp[now][j][h] |= dp[last][j-a[i]][h];
            if (h >= a[i])
                dp[now][j][h] |= dp[last][j-a[i]][h-a[i]];
        }
    }
    for (int i = 0; i <= k; i++)
        if (dp[n%2][k][i])
            ans.push_back(i);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}
