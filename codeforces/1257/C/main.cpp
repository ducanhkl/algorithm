#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5+100;

int n;
int a[maxn], pre[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int l = 0;
        memset(pre, 0, sizeof(pre));
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            if (pre[a[i]] == 0)
                pre[a[i]] = i;
            else
            {
                if (pre[a[i]] > l)
                    l = pre[a[i]];
                ans = min(ans, i-pre[a[i]]+1);
                pre[a[i]] = i;
            }
        }
        if (ans == INT_MAX)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
