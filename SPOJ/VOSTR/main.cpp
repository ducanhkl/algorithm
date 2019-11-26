#include <bits/stdc++.h>

using namespace std;

const long long base = 29, mod = 1e9+7;
const int maxn = 1e6+100;

char a[maxn], b[maxn];
long long ha[maxn], hb[maxn], p[maxn];

int la, lb;

void init ()
{
    for (int i = 1; i <= la; i++)
        a[i] -= 'a';
    for (int i = 1; i <= lb;  i++)
        b[i] -= 'a';
    for (int i = 1; i <= la; i++)
    {
        ha[i] = ((ha[i-1] + a[i])*base)%mod;
    }
    for (int i = 1; i <= lb; i++)
    {
        hb[i] = ((hb[i-1]+ b[i])*base)%mod;
    }
    p[0] = 1;
    for (int i = 1; i  <= max(la, lb); i++)
        p[i] = (p[i-1]*base)%mod;
}

long long gethash(long long *arr, int l, int r)
{
    return (arr[r] - arr[l-1]*p[r-l+1] + mod*mod) % mod;
}

void solve(int l, int r, int u, int v)
{
    int lena = r-l+1, lenb = v-u+1;
    int lo = 1, hi = min(lena, lenb);
    int ans = 0;
    while  (lo <= hi)
    {
        int mid = (lo+hi) >> 1;
        unsigned hash1 = gethash(ha, l, l+mid-1);
        unsigned hash2 = gethash(hb, u, u+mid-1);
        if (hash1 == hash2)
            ans = mid, lo = mid +1;
        else
            hi = mid - 1;
    }
    if (lena == lenb)
    {
        if (ans == lena)
        {
            cout << "=";
        } else
        {
            if (a[l+ans] < b[u+ans])
                cout << '<';
            else
                cout << ">";
        }
    } else
    {
        if (ans == min(lena, lenb))
        {

            if (lena < lenb)
                cout << '<';
            else
                cout << '>';
        } else
        {
            if (a[l+ans] < b[u+ans])
                cout << '<';
            else
                cout << ">";
        }
    }
}

int main() {
    //freopen ("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> la >> lb;
    for (int i = 1; i <= la; i++ )
        cin >> a[i];
    for (int i = 1; i <= lb; i++)
        cin >> b[i];
    init();
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int l, r, u, v;
        cin >> l >> r >> u >> v;
        solve(l, r, u, v);
    }
    return 0;
}