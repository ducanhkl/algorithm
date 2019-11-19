#include <bits/stdc++.h>
#define maxn 1000006
#define mod 1000000007

using namespace std;

vector <pair <int, int> > v[maxn];
vector <long long> res;
long long dd[1<<22], a[maxn], ans, dp[maxn];
int n, q;


int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(dd, 0, sizeof(dd));
    memset(dp, 0, sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i =1; i <= q; i++)
    {
        int l, x;
        cin >> l >> x;
        v[l].push_back({x, i});
    }
    dd[0] = 1;
    ans = 1;
    res.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        if (i == 4)
            i = 4;
        if (dd[a[i]])
            ans = (ans*2)%mod;
        else
        {
            int m = res.size();
            for (int j = 0; j < m; j++)
                {
                    //cout << (a[i]^res[j]) << endl;
                    if ((a[i]^res[j]) < (1<<21))
                    {
                        res.push_back(res[j]^a[i]);
                        dd[res[j]^a[i]] = 1;
                    }
                }
        }
        for (int j = 0; j < v[i].size(); j++)
            dp[v[i][j].second] = ans*dd[v[i][j].first];
    }
    for (int i = 1; i <= q; i++)
        cout << dp[i] << endl;
    return 0;
}
