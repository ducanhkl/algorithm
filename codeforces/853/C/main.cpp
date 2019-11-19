#include <bits/stdc++.h>
#define maxn 2000006

using namespace std;

struct data
{
    int x, y, pos,l, cf;
    long long bonus;
};
vector <data> v;
int n, q, a[maxn];
long long ans[maxn], tree[maxn];

long long update(int x)
{
    for (; x < maxn; x += (x&(-x)))
        tree[x] ++;
}

long long get(int x)
{
    long long res = 0;
    for (; x > 0; x -= (x&(-x)))
        res += tree[x];
    return res;
}

long long calc(long long x)
{
    return x*(x-1)/2;
}

bool cmp(data x, data y)
{
    return x.x < y.x;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    memset(tree, 0, sizeof(tree));
    memset(ans, 0, sizeof(ans));
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= q; i++)
    {
        ans[i] = calc(n);
        int l, d, r, u;
        cin >> l >> d >> r >> u;
        ans[i] -= calc(l-1) + calc(d-1) + calc(n-r) + calc(n-u);
        v.push_back((data){l-1, d-1, i, 1, 0});
        v.push_back((data){l-1, u, i, -1,  l-1});
        v.push_back((data){r, d-1, i, -1, d-1});
        v.push_back((data){u, r, i, 1, n-u-r});
    }
    sort(v.begin(), v.end(), cmp);
    int j = 0;
    while (v[j].x == 0)
        j++;
    for (int i = 1; i <= n; i++)
    {
        update(a[i]);
        for (; j < v.size() && v[j].x == i; j++)
        {
            long long res = get(v[j].y)*v[j].cf + v[j].bonus;
            ans[v[j].pos] += calc(res);
        }
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << endl;
    return 0;
}
