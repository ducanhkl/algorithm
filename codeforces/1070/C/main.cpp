#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;

int n, k, m;
long long ans = 0, cntv = 0;

struct da
{
    long long pos, c, p, val;
};

vector <da> v;

bool cmp (da x, da y)
{
    return x.pos < y.pos;
}

class bittree
{
    public :
    long long tree[maxn+101];
    void reset ()
    {
        memset( tree, 0, sizeof(tree));
    }
    void upd(int x, int val)
    {
        for (; x < maxn; x += (x&(-x)))
            tree[x] += val;
        return ;
    }
    long long get(int x)
    {
        long long res = 0;
        for (; x ; x -= (x&(-x)))
            res += tree[x];
        return res;
    }

    long long firstIndexOf(int val)
    {
        int i = 0;
        int step = (1LL << (int)(log2(maxn)));
        long long now = 0;
        while (step > 0)
        {
            if (i + step < maxn && now + tree[i+step] < val)
            {
                now += tree[i+step];
                i += step;
            }
            step /= 2;
        }
        return i+1;
    }
};

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++)
    {
        int l, r, c, p;
        cin >> l >> r >> c >> p;
        v.push_back((da){l, c, p, 1});
        v.push_back((da){r+1, c, p, -1});
    }
    bittree t1, t2;
    t1.reset(), t2.reset();
    sort (v.begin(), v.end(), cmp);
    for (int i = 1; i <= n; i++)
    {
        while (cntv < v.size () && v[cntv].pos == i)
        {
            t1.upd(v[cntv].p, v[cntv].c*v[cntv].val);
            t2.upd(v[cntv].p, v[cntv].c * v[cntv].val *v[cntv].p);
            cntv ++;
        }
        long long lss = t1.get(maxn);
        if (lss < k)
            ans += t2.get(maxn);
        else
        {
            long long p = t1.firstIndexOf(k);
            long long cnt = t1.get(p);
            ans += (t2.get(p) - 1LL*(cnt - k) * p);
        }
    }
    cout << ans;
    return 0;
}
