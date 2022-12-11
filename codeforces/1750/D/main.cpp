#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5+100;
const long long MOD = 998244353;
int n, m;
int a[maxn];
vector<int> factor;

long long calc_dp(int num, int vt)
{
    if (vt == -1)
    {
        return (long long)num;
    }
    long long all = calc_dp(num, vt-1);
    long long redundant = calc_dp(num / factor[vt], vt-1);
//    cout << all << " " << redundant << " " << num << endl;
    return  all - redundant;
}

long long calc(int num, int p)
{
    factor.clear();
    int i;
    for (i = 2; i <= sqrt(p); i++)
    {
        if (p%i == 0)
        {
            factor.push_back(i);
            while(p % i == 0)
            {
                p /= i;
            }
        }
    }
    if (p > 1)
    {
        factor.push_back(p);
    }
    return  calc_dp(num, factor.size() - 1);
}

void solve()
{
    long long ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] % a[i+1] != 0)
        {
            cout << 0 << endl;
            return;
        }
        ans = ans * calc(m / a[i+1], a[i] / a[i+1]) % MOD;
    }
    cout << ans << endl;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while(test--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        solve();
    }
    return 0;
}
