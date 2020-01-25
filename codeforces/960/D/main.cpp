#include <bits/stdc++.h>

using namespace std;

long long l[100];
int q;

int get(long long x)
{
    for (int i = 63; i >= 0; i--)
        if ((1LL<<i)&x)
            return i;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            long long x, k;
            cin >> x >> k;
            int p = get(x);
            long long mod = (1LL<<(p));
            l[p] = (l[p]+k%mod+mod)%(mod);
            continue;
        }
        if (t == 2)
        {
            long long x, k;
            cin >> x >> k;
            int p = get(x);
            for (int ii = p; ii <= 62; ii++)
            {
                long long mul = 1LL<<(ii-p), mod = (1LL<<(ii));
                mul *= k;
                mul = mul%mod;
                l[ii] = (l[ii]+mul)%mod;
            }
            continue;
        }
        long long x;
        cin >> x;
        int p = get(x);
        long long mod = (1LL<<p);
        while (p != 0)
        {
            cout << x << " ";
            long long cur  = (((x-mod)+l[p])%mod+mod)%mod+mod;
            cur /= 2;
            mod /= 2;
            cur = (((cur-mod)-l[p-1])%mod+mod)%mod+mod;
            x = cur;
            p--;
        }
        cout << 1;
        cout << endl;
    }
    return 0;
}
