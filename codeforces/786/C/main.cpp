#include <bits/stdc++.h>
#define maxn 100004

using namespace std;

int n;
int a[maxn], trc[maxn], len[maxn], now[maxn], _next[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(now, 0, sizeof(now));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        trc[i] = now[a[i]];
        now[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        _next[i] = i;
    for (int i = 1; i <= n; i++)
    {
        int ans = 0;
        int j = 1;
        while (j <= n)
        {
            int tmp = len[j];
            int _j = j;
            j = _next[j];
            while (j <= n && tmp <= i)
            {
                if (trc[j] < _j)
                    tmp++;
                j++;
            }
            if (tmp > i)
                j--;
            ans ++;
            len[_j] = i;
            _next[_j] =  j;
        }
        cout << ans << " ";
    }
    return 0;
}
