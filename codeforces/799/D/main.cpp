#include <bits/stdc++.h>
#define maxn 1000005

using namespace std;

long long s[maxn], a, b, h, w, n;
int ans;

void dfs(long long x, long long y, int res)
{
    if (((x>=a)&&(y>=b)))
        {
            ans = min(ans, res);
            return;
        }
    if (res == n)
        return ;
    if (s[res+1] == 2)
    {
        while (x < a)
            x *= 2LL, res++;
        while (y < b)
            y *= 2LL, res++;
        ans = min(ans, res);
        return ;
    }
    if (x < a)
        dfs(x*s[res+1], y, res+1);
    if (y < b)
        dfs(x, y*s[res+1], res+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> h >> w >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    ans = n+1;
    sort(s+1, s+n+1, greater<long long>());
    dfs(h, w, 0);
    dfs(w, h, 0);
    if (ans == n+1)
        cout << -1;
    else
        cout << ans;
    return 0;
}
