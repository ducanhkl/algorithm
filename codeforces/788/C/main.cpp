/*
#include <bits/stdc++.h>

using namespace std;

int n, k;
map <int, int> dd, tt;
deque <int> q;
int a[1000006];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= k; i++) cin >> a[i], tt[a[i]-n] = 1;;
    q.push_back(0);
    while (q.size())
    {
        int u = q.front();
        q.pop_front();
        for (int i = -1000; i <= 1000; i++)
                if (tt[i] && !dd[u+i])
                    {
                        dd[u+i] = dd[u] + 1;
                        if (u+i == 0)
                            return cout << dd[u+i], 0;
                        if (u+i >= -1000 && u+i <= 1000)
                            q.push_back(u+i);
                    }
    }
    cout << -1;
    return 0;
}
*/

#include <bits/stdc++.h>

using namespace std;

const long long mod= 1e9+7;
long long dp[10000007], n;
int main()
{
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
        if (i%2)
            dp[i] = (dp[i-1]*(dp[i-1]+1)-2+mod)%mod;
        else
            dp[i] = ((dp[i-1]-1)*(dp[i-1])-2+mod)%mod;
    cout << dp[n];
}
