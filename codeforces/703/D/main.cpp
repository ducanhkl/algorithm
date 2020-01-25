#include <bits/stdc++.h>
#define maxn 1000005
#define int int64_t

using namespace std;

int n, q;
int a[maxn], b[maxn], l[maxn], r[maxn], ans[maxn];
map <int, int> last;
int tree[maxn];
vector <int> dd[maxn];

void update(int x, int val)
{
    for (; x < maxn; x += (x&(-x)))
        tree[x] ^= val;
}

int get(int x)
{
    int res = 0;
    for (; x; x -= (x&(-x)))
        res ^= tree[x];
    return res;
}

int32_t main()
{
    memset(tree, 0, sizeof(tree));
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = b[i-1]^a[i];
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> l[i] >> r[i];
        dd[r[i]].push_back(i);
        ans[i] = b[r[i]]^b[l[i]-1];
    }
    for (int i = 1; i <= n; i++)
    {
        if (last[a[i]])
            update(last[a[i]], a[i]);
        last[a[i]] = i;
        update(i, a[i]);
        for (int j = 0; j < dd[i].size(); j++)
        {
            int pos = dd[i][j];
            ans[pos] ^= get(n)^get(l[pos]-1);
        }
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << endl;
    return 0;
}
