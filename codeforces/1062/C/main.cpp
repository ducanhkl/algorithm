#include <bits/stdc++.h>
#define maxn 100007
using namespace std;


int a[maxn], n, q;
long long ans = 0, p[maxn];
const long long mod = 1e9+7;


int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        char x;
        cin >> x;
        if (x == '1')
            a[i] = 1;
        else
            a[i] = 0;
        a[i] += a[i-1];
    }
    p[0] = 1;
    for (int i = 1; i < maxn; i++)
        p[i] = (p[i-1]*2)%mod;
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        int cnt1 = a[r] - a[l-1];
        if (cnt1 == 0)
            {
                cout << 0 << endl;
                continue;
            }
        int cnt2 = (r-l+1)-cnt1;
        cout << (p[cnt1]-1+mod+(p[cnt1-1]+p[cnt1-1]-1+mod)*(p[cnt2]-1+mod)%mod)%mod << endl;
    }
    return 0;
}
