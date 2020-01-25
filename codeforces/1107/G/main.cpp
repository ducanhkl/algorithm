#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5+100;

int root[maxn];
long long l[maxn], r[maxn], ans[maxn], d[maxn], c[maxn], sum[maxn];
int n, a;
pair <int, int> p[maxn];

int getroot(int u)
{
    if (root[u] == 0)
        return u;
    return root[u] = getroot(root[u]);
}

long long get(int v)
{
    int u = getroot(v-1);
    long long dis = (d[v] - d[v-1]);
    ans[u] = max(max(ans[u], ans[v]), r[u] + l[v] - dis*dis);
    l[u] = max(l[u], sum[u] + l[v]);
    r[u] = max(r[v], r[u] + sum[v]);
    sum[u] += sum[v];
    root[v] = u;
    return ans[u];
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin  >> n >> a;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i] >> c[i];
        p[i]  = {abs(d[i] - d[i-1]), i};
        sum[i] = a-c[i];
        ans[i] = l[i]  = r[i] = max(sum[i], 0LL);
    }
    sort(p+1, p+n+1);
    for (int i = 1; i <= n; i++)
    {
        get(p[i].second);
    }
    cout <<ans[1];
    return 0;
}
