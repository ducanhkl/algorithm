#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;

string s, t;
int dp1[maxn], dp2[maxn], dp[maxn];
int ans = INT_MAX;

void init(string x, int a[maxn])
{
    memset(a, 0, sizeof(a));
    memset(dp, 0, sizeof(dp));
    for (int i = x.size()-1; i >= 0; i--)
        for (int j = 0; j < x.size(); j++)
            if (i != j)
    {
        if (x[i] != x[j])
        {
            dp[j] = 0;
            continue;
        }
        dp[j] = dp[j+1] + 1;
        a[i] = max(dp[j], a[i]);
    }
}

int main()
{
   // freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> s >> t;
    init(s, dp1);
    init(t, dp2);
    memset(dp, 0, sizeof(dp));
    for (int i = (int)s.size()-1; i >= 0; i--)
        for (int j = 0; j < t.size(); j++)
            if (s[i] == t[j])
    {
        dp[j] = dp[j+1]+1;
        if (dp[j] > dp1[i] && dp[j] > dp2[j])
            ans = min(ans, max(dp1[i], dp2[j])+1);
    } else
        dp[j] = 0;
    if (ans > s.size())
        cout << -1;
    else
        cout << ans;
    return 0;
}
