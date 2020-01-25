#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+200;
int n, ans = 0;
int a[2000], dd[maxn], cnt[maxn];

int main()
{
    freopen("inp.txt", "r", stdin);
    memset(cnt, 0, sizeof(cnt));
    memset(dd, 0, sizeof(dd));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]] ++;
    }
    for (int i = 1; i <= 2e5+100; i ++)
    {
        int res = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[j] > i)
                continue;
            if (dd[a[j]] < cnt[a[j]] && dd[i-a[j]] < cnt[i-a[j]])
            {
                if (a[j] == i-a[j])
                {
                    if (dd[a[j]] > cnt[a[j]]-2)
                        continue;
                    dd[a[j]] += 2;
                    ans += 1;
                }
                dd[a[j]] ++;
                dd[i-a[j]] ++;
                res ++;
            }
        }
        if (res == 3)
            n = n;
        for (int j = 0; j <= n; j++)
            dd[a[j]] = 0;
        ans = max(ans, res);
    }
    cout << ans;
    return 0;
}
