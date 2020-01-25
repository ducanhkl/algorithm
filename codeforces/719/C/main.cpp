#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+10;
int n, t, dp[maxn], pos, ans = maxn;
char a[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> t;
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < maxn; i++)
        dp[i] = INT_MAX;
    for (int i = n; i >= 1; i--)
        {
            if (a[i] == '.')
                {
                    pos = i;
                    break;
                }
            if (a[i] <= '4')
                dp[i] = INT_MAX/2;
            if (a[i] == '4')
                dp[i] = dp[i+1] + 1;
            if (a[i] > '4')
                dp[i] = 1;
        }
    for (int i = pos; i <= n; i++)
        if (dp[i]  <= t)
        {
            ans = i;
            break;
        }
    if (ans == maxn)
    {
        for (int i  = 1; i <= n; i++)
            cout << a[i];
        return 0;
    }
    a[ans] = '0';
    int vt = ans-1;
    if (a[vt] == '.') vt--;
    while (a[vt] == '9')
        {
            a[vt] = '0';
            vt --;
            if (a[vt] == '.')
                vt--;
        }
    a[vt] ++;
    if (vt == 0)
        cout << 1;
    while (a[ans] == '0')
        ans--;
    if (a[ans] == '.')
        ans --;
    for (int i = 1; i <= ans; i++)
        cout << a[i];
    return 0;
}
