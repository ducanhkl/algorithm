#include <bits/stdc++.h>

using namespace std;

int n, p, l = INT_MIN, r = INT_MAX;
long long res = 1, ans = 1;
const int mod = 1e9+7;
set <int> m;
string s;
set <int>::iterator it;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    m.insert(INT_MIN), m.insert(INT_MAX);
    for (int i = 1; i <= n; i++)
    {
        cin >> s >> p;

        if (s == "ADD")
        {
            if (p >= l && p <= r)
                ans ++;
            m.insert(p);
            ans = ans % mod;
            continue;
        }

        if (p < l || p > r)
            res = 0;
        if (p != l && p != r)
            res = (res*2)%mod;
        m.erase(p);
        ans = 1;
        it = m.lower_bound(p);
        r =*it;
        l =*(--it);
    }
    cout << res*ans%mod;
    return 0;
}
