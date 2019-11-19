#include <bits/stdc++.h>

using namespace std;

typedef pair <int, long long> pii;

const int maxn = 4e5+100;
const long long mod = 1e9+7;
int n, q;
int a[maxn];
pii tree[4*maxn], f[4*maxn];
vector <int> pr;

long long fp(long long x, long long y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x%mod;
    long long res = fp(x, y/2);
    res *= res;
    res %= mod;
    if (y%2)
        return res*x%mod;
    return res%mod;
}

long long getbit(int x)
{
    long long res = 0;
    for (int i = 0; i < pr.size(); i++)
    {
        if (x % pr[i] == 0)
        {
            res |= 1LL<<i;
        }
    }
    return res;
}

void down(int cha, int con)
{
    tree[con].first = (long long)tree[con].first*f[cha].first;
    f[con].first = (long long)f[con].first*f[cha].first;
    f[con].second |= f[cha].second;
    tree[con].second |= f[cha].second;
}

void init(int node, int l, int r)
{
    if (l == r)
    {
        tree[node].first = a[l];
        tree[node].second = getbit(a[l]);
        return ;
    }
    int mid = (l+r)>>1;
    init(2*node, l, mid);
    init(2*node+1, mid+1, r);
    tree[node].first = (long long)tree[2*node].first*(tree[2*node+1].first)%mod;
    tree[node].second = tree[2*node].second|tree[2*node+1].second;
    return ;
}

void update(int node, int l, int r, int u, int v, int w)
{
    down(node, 2*node);
    down(node, 2*node+1);
    f[node] = {1, 0};
    if (v < l || u > r)
        return ;
    if (v >= r && u <= l)
    {
        tree[node].first = (long long)tree[node].first*w%mod;
        tree[node].second |= getbit(w);
        f[node] = {w, getbit(w)};
        return ;
    }
    int mid = (l+r)>>1;
    update(2*node, l, mid, u, v, w);
    update(2*node+1, mid+1, r,u, v, w);
    tree[node].first = (long long)tree[2*node].first*(tree[2*node+1].first)%mod;
    tree[node].second = tree[2*node].second|tree[2*node+1].second;
}
pair <long long, long long>  getmul(int node, int l, int r, int u, int v)
{
    down(node, 2*node);
    down(node, 2*node+1);
    f[node] = {1, 0};
    if (v < l || u > r)
        return {1, 0};
    if (v >= r && u <= l)
    {
        return tree[node];
    }
    int mid = (l+r)>>1;
    pair <long long, long long> res1 = getmul(2*node, l, mid, u, v);
    pair <long long, long long> res2 = getmul(2*node+1, mid+1, r,u, v);
    res1.first *= res2.first;
    res1.first %= mod;
    res1.second |= res2.second;
    return res1;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    for (int  i = 0; i < 350; i++)
        f[i].first = tree[i].first = 1;
    for (int i = 2; i <= 350; i++)
    {
        int ck = 1;
        for (int j = 2; j <= sqrt(i); j++)
            if (i % j == 0)
                ck = 0;
        if (ck)
            pr.push_back(i);
    }
    cin >> n >> q;
    for (int i = 1;  i <= n; i++)
        cin >> a[i];
    init(1, 1, n);
    //cout << 6*fp(2, mod-2)%mod*fp(3, mod-2)%mod << endl;
    for (int i = 1; i <= q; i++)
        {
            string s;
            int u, v;
            cin >> s;
            cin >> u >>v;
            if (s[0] == 'M')
            {
                int w;
                cin >> w;
                update(1, 1, n, u, v, w);
                continue;
            }
            long long ans = 1;
            pair <long long, long long> res = getmul(1, 1 , n, u, v);
            for (int j = 0; j < 64; j++)
            {
                if ((((long long)res.second>>j)&1)== 1)
                    {
                        //cout << pr[j] << endl;
                        ans = (ans*(pr[j]-1))%mod*fp(pr[j], mod-2)%mod;
                    }
            }
            cout << ans*res.first%mod <<endl;
        }
    return 0;
}
