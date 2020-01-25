#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n, c;
int a[maxn], b[maxn], trc[maxn], dp1[maxn], dp2[maxn], dp3[maxn], dp4[maxn];
int ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(trc, 0, sizeof(trc));
    for (int i = 1; i <= n; i++)
    {
        b[i] = trc[a[i]];
        trc[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int pos = b[i];
        if (a[i] == c)
            dp1[i] = dp1[i-1]+1;
        else
            dp1[i] = dp1[i-1];
        dp2[i] = max(dp1[i-1], dp2[pos])+1;
        dp3[i] = max(dp2[i-1], max(dp1[i-1], dp3[i-1]));
        if (a[i] == c)
            dp3[i] ++;
    }
    ans = max(dp3[n], max(dp2[n], dp1[n]));
    for (int i = 0; i < maxn; i++)
        trc[i] = dp1[i] = dp4[i] = b[i] = 0;
    for (int i = n; i >= 1; i--)
    {
        b[i] = trc[a[i]];
        trc[a[i]] = i;
    }
    for (int i = n; i >= 1; i--)
    {
        int pos = b[i];
        if (a[i] == c)
            dp1[i] = dp1[i+1]+1;
        else
            dp1[i] = dp1[i+1];
        dp4[i] = max(dp1[i+1], dp4[pos])+1;
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp2[i] + dp4[i]-1);
    cout << ans;
    return 0;
}
