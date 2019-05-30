#include <bits/stdc++.h>
#define maxn 5*1000006 //5*1000006 0
#define mod 1000000007

using namespace std;

long long dd[maxn], p[maxn], prime[maxn];
long long t, l,r, ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    for (int i = 2; i < maxn; i++)
        prime[i] = 0;
    cin >> t >> l >> r;
    for (long long i = 2; i <= r; i++)
    {

        if (!prime[i])
            for (int j = i; j < maxn; j += i)
                if (!prime[j]) prime[j] = i;
        dd[i] = (i*(prime[i]-1)/2+dd[i/prime[i]])%mod;
    }
    p[l] = 1;
    for (int i = l+1; i <= r; i++)
        p[i] = (p[i-1]*t)%mod;
    for (int i = l; i <= r; i++)
        ans = (ans + dd[i]*p[i]%mod)%mod;
    cout << ans;
    return 0;
}
