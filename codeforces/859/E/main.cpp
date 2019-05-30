#include <bits/stdc++.h>
#define maxn 1000005

using namespace std;

int n;
int cnt[maxn], dd[maxn], root[maxn];
long long ans = 1;
const long long mod = 1e9+7;

int getroot(int u)
{
    if (root[u] == u)
        return u;
    else return root[u] = getroot(root[u]);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= 2*n; i++)
        cnt[i] = 1, root[i] = i, dd[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        dd[u] = 1;
        if (u == v)
            continue;
        int ru = getroot(u), rv = getroot(v);
        if (ru == rv)
            ans = ans*2%mod;
        cnt[rv] += cnt[ru];
        root[ru] = root[rv];
    }
    for (int i = 1; i <= 2*n; i++)
        if (!dd[i])
            ans = (ans*cnt[i])%mod;
    cout << ans;
    return 0;
}
