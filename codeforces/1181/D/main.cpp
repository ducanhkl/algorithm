#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5+100;
long long n, m, q;
int cnt[maxn];
long long t[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        t[i] = (cnt[x]*m)+x;
        cnt[x] ++;
    }
    sort(t+1, t+n+1);
    for (int i = 1; i <= n; i++)
        t[i] += n-i;
    for (int i = 1; i <= q; i++)
    {
        long long time, ans;
        cin >> time;
        if (time > t[n])
            ans = time;
        else
        {
            int pos = lower_bound(t+1, t+n+1, time) - t;
            ans = time - (n-pos+1);
        }
        ans %= m;
        if (ans == 0)
            ans = m;
        cout << ans << endl;
    }
    return 0;
}
