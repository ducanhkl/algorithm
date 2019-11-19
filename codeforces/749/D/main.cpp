#include <bits/stdc++.h>
#define maxn 200004

using namespace std;

int n, a[maxn], b[maxn], dd[maxn], q, k, l[maxn];
vector <pair<int, int> > v;
vector <int> c[maxn];

bool cmp(pair<int, int> x, pair <int, int> y)
{
    return x.second > y.second;
}

void solve()
{
    int x = 0, y = 0, pos;
    for (int i = 0; i < v.size(); i++)
        if (!dd[v[i].first])
    {
        x = v[i].first;
        pos = i;
        break;
    }
    if (x == 0)
    {
        cout << "0 0 \n";
        return;
    }
    for (int i = pos+1; i < v.size(); i++)
        if (!dd[v[i].first])// && v[i].first != x)
    {
        y = v[i].second;
        break;
    }
    cout << x << " " << *upper_bound(c[x].begin(), c[x].end(), y) << endl;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i];
            c[a[i]].push_back(b[i]);
        }
    for (int i = n; i >= 1; i--)
        if (!dd[a[i]])
            {
                v.push_back({a[i], b[i]});
                dd[a[i]] = 1;
            }
    memset(dd, 0, sizeof(dd));
    sort(v.begin(), v.end(), cmp);
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> k;
        for (int i = 1; i <= k; i++)
            cin >> l[i], dd[l[i]] = 1;
        solve();
        for (int i = 1; i <= k; i++)
            dd[l[i]] = 0;
    }
    return 0;
}
