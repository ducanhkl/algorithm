#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;

int q;
int  k[maxn], _k[maxn], tree[4*maxn], no[4*maxn], pos[maxn];
char qe[maxn];

void init(int node, int l, int r)
{
    if (l == r)
    {
        no[l] = node;
        tree[node] = 0;
        return ;
    }
    int mid = (l+r)>>1;
    init(2*node, l, mid);
    init(2*node+1, mid+1, r);
    tree[node] = tree[2*node] + tree[2*node+1];
}

int get(int node, int l, int r, int u, int v)
{
    if (l > v || r < u)
        return 0;
    if (l >= u && v >= r)
    {
        return tree[node];
    }
    int mid = (l+r)>>1;
    int res1 = get(2*node, l, mid, u, v);
    int res2 = get(2*node+1, mid+1, r, u, v);
    return res1+res2;
}

void upd(int p, int val)
{
    int node = no[p];
    tree[node] = val;
    node /= 2;
    while (node > 0)
    {
        tree[node] = tree[2*node] + tree[2*node+1];
        node /= 2;
    }
    return ;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> q;
    for (int i = 1; i <= q; i++ )
    {
        cin >> qe[i] >> k[i];
    }
    for (int i = 1; i <= q; i++)
    {
        _k[i] = k[i];
    }
    sort(_k+1, _k+q+1);
    for (int i = 1; i <= q; i++)
    {
        pos[i] = lower_bound(_k+1, _k+q+1, k[i]) - _k;
    }
    init(1, 1, q);
    for (int i = 1; i <= q; i++)
    {
        if (qe[i] == 'I')
        {
            upd(pos[i], 1);
        }
        if (qe[i] == 'D')
        {
            upd(pos[i], 0);
        }
        if (qe[i] == 'K')
        {
            int l = 1, r = q, ans = 0;
            if (k[i] > get(1, 1, q , 1 , q))
            {
                cout << "invalid" << endl;
                continue;
            }
            while (l <= r)
            {
                int mid = (l+r) >> 1;
                if (get(1, 1, q,1 , mid) < k[i])
                {
                    l = mid+1;
                } else
                    {
                        ans = mid;
                        r = mid-1;
                    }
            }
            cout << _k[ans];
            cout << endl;
        }
        if (qe[i] == 'C')
        {
            int l = 1, r = q, ans = 0;
            cout << get(1, 1, q, 1, pos[i]-1) << endl;
        }
    }
    return 0;
}
