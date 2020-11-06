#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+100;

char a[maxn];
int n, pre[maxn], lst[3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    lst[0] = lst[1] = -1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == '?')
        {
            pre[i] = min(lst[0], lst[1]);
        } else
        {
            char c = a[i];
            c -= '0';
            lst[c] = i;
            pre[i] = lst[c^1];
        }
    }
    for (int len = 1; len <= n; len ++)
    {
        if (len == 3)
        {
            n ++;
            n --;
        }
        int r = len, ans = 0;
        while (r <= n)
        {
            if (pre[r] <= r-len)
            {
                ans ++;
                r += len;
            } else
            {
                r = pre[r]+len;
            }
        }
        cout << ans << " ";
    }
    return 0;
}
