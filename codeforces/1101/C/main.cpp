#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e5+100;
struct data
{
    int first, second, pos;
} a[maxn];

bool cmp(data x, data y)
{
    if (x.first == y.first)
        return x.second < y.second;
    return x.first < y.first;
}

int n;
int dd[maxn];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second, a[i].pos = i;
    sort(a+1, a+n+1, cmp);
    int r = a[1].second, tt = 1;
    dd[a[1].pos] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i].first <= r)
        {
            dd[a[i].pos] = dd[a[i-1].pos];
            r = max(r, a[i].second);
            continue;
        }
        dd[a[i].pos] = 3-dd[a[i-1].pos];
        r = max(r, a[i].second);
    }
    for (int i = 2; i <= n; i++)
        if (dd[i] != dd[1])
    {
        for (int i = 1; i <= n; i++)
            cout << dd[i] << " ";
        return;
    }
    cout << -1;
}

void reset()
{
    memset(dd, 0, sizeof(dd));
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    int t, check;
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        reset();

        solve();
        cout << endl;
    }
    return 0;
}
