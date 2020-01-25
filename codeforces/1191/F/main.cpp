#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;
const int maxn = 4*1e5;

ii a[maxn];
long long tree[maxn], ans = 0;
int num[maxn], dd[maxn], n;


long long update (int x)
{
    for (; x < maxn; x += x&(-x))
        tree[x] ++;
}

long long get (int x)
{
    long long res = 0;
    for (; x > 0; x -= (x&(-x)))
        res += tree[x];
    return res;
}

bool cmp(ii x, ii y)
{
    if (x.second == y.second)
        return x.first < y.first;
    return x.second > y.second;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
        num[i] = a[i].first;
    }
    sort(num+1, num+n+1);
    for (int i = 1; i <= n; i++)
        a[i].first = lower_bound(num+1, num+n+1, a[i].first)-num;
    sort(a+1, a+n+1, cmp);
    for (int i = 1, j; i <= n; i = j)
    {
        for (j = i; j <= n && a[i].second == a[j].second; j++)
            if (!dd[a[j].first])
                dd[a[j].first] = 1,
                update(a[j].first);
        for (int k = i, trc = -1; k < j; k++)
        {
            ans  = ans + (get(a[k].first) - get(trc))*(get(n)-get(a[k].first-1));
            trc = a[k].first;
        }
    }
    cout << ans;
    return 0;
}
