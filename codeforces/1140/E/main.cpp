#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;
const long long mod = 998244353;
long long sa[maxn], di[maxn];

long long solve(long long k, vector <int> v)
{
    int last = 0;
    long long res = 1;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > 0)
        {
            if (last != 0)
            {
                if (v[last] == v[i])
                    res = res*sa[i-last-1]%mod;
                else
                    res = res*di[i-last-1]%mod;
            }
            else
            {
                if (i > 1)
                    res =  (res*((sa[i-2]+di[i-2]*(k-1)%mod)))%mod;
            }
            last = i;
        }
    }
    int n = v.size()-1;
    if ( n == 1 && last == 0)
        return k%mod;
    if (last == 0)
    {
        return (k*sa[n-2]+k*(k-1)%mod*di[n-2])%mod;
    }
    if (last < n)
        if (n-last > 1)
            res = res*((sa[n-last-1]+di[n-last-1]*(k-1))%mod)%mod;
        else
            res = res*(k-1)%mod;
    return res;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    int n;
    long long k;
    vector <int> v[3];
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    sa[0] = 0;
    di[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        sa[i] = (k-1)*di[i-1]%mod;
        di[i] = sa[i-1]+(k-2)*di[i-1]%mod;
        di[i] %= mod;
    }
    v[0].push_back(0);
    v[1].push_back(0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        v[i%2].push_back(x);
    }
    long long res2 = solve(k, v[0])%mod;
    long long res1 = solve(k, v[1])%mod;
    cout << res1*res2%mod;
    return 0;
}
