#include <bits/stdc++.h>
#define maxn 1000005

using namespace std;

int n, cnt = 0;
map <int, int> m;
pair <int, int> a[maxn];
int b[maxn], tree[maxn];
long long ans = 0;

long long get(int x)
{
    long long res = 0;
    for (; x > 0; x -= (x&(-x)))
        res += tree[x];
    return res;
}

long long update(int x)
{
    for (; x < maxn; x+= x&(-x))
        tree[x] ++;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        //cout << m[u] << " " << m[v] << endl;
        if (m[u] == 0)
            m[u] = u;
        if (m[v] == 0)
            m[v] = v;
        swap(m[u], m[v]);
    }
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        a[++cnt].first = it->first;
        a[cnt].second = it->second;
    }
    for (int i = 1; i <= cnt; i++)
        b[i] = a[i].second;
    sort(b+1, b+cnt+1);
    for (int i = 1; i <= cnt; i++)
        {
            ans += abs(a[i].first-a[i].second);
            int pos = lower_bound(b+1, b+cnt+1, a[i].second)-b;
            ans -= abs(pos-i);
        }
    for (int i = cnt; i >= 1; i--)
    {
        int pos = lower_bound(b+1, b+cnt+1, a[i].second) - b;
        ans += get(pos-1);
        update(pos);
    }
    cout << ans;
    return 0;
}
