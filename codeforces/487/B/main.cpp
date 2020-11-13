#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
const int maxc = 123456789;
multiset <long long> g, mul;
int n, l;
int s;
long long  dp[maxn], a[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> s >> l;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1, j = 1; i <= n; i++)
    {
        g.insert(a[i]);
        while ((*g.rbegin() - *g.begin()) > s)
        {
            g.erase(g.find(a[j]));
            if (i - j >= l)
            {
                // cerr << "del " << dp[j-1] << endl;
                mul.erase(mul.find(dp[j-1]));
            }
            j ++;
        }
        if (i -j + 1 >= l)
        {
            // cerr << i << " ins " << dp[i-l] << endl;
            mul.insert(dp[i-l]);
        }
        if (mul.size() == 0)
            dp[i] = maxc;
        else
        {
            dp[i] = *mul.begin() + 1;
        }
    }
    if (dp[n] >= maxc)
    {
        cout << -1;
    } else
        cout << dp[n];
    return 0;
}
