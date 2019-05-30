#include <bits//stdc++.h>

using namespace std;


long long dp[20][70][2100], d[100];
long long b, l, r;

long long calc(int val, int l, int mask, int first)
{
    if (val <= 0)
        return mask == 0;
    if (!l && !first && dp[b][val][mask]!=-1)
        return dp[b][val][mask];
    long long res = 0;
    for (int i = first; i < b; i++)
    {
        if (l & i > d[val])
            break;
        res += calc(val-1, l && (i == d[val]), mask^(1<<i), 0);
    }
     if (!l && !first)
        return dp[b][val][mask] = res;
    return res;
}

long long get(long long mid)
{
    memset(d, 0, sizeof(d));
    long long ans = 0;
    int x = 0;
    while (mid != 0)
        d[++x] = mid%b, mid /= b;
    for (int i = 1; i <= x; i++)
        ans += calc(i, (int)(i == x), 0, 1);
    return ans;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 70; j++)
            for (int k = 0; k < 2100; k++)
                dp[i][j][k] = -1;
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> b >> l >> r;
        cout << get(r) - get(l-1)<< endl;
    }
    return 0;
}
