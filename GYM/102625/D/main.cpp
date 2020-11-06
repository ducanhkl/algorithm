#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+100;

int dp[4*maxn], trace[4*maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    for (int i = 0; i < maxn; i++)
        dp[i] = INT_MAX;
    dp[1] = 1;
    trace[1] = 0;
    for (int i = 1; i < maxn; i++)
        {
            if (dp[2*i] > dp[i]+1)
            {
                dp[2*i] = dp[i]+1;
                trace[2*i] = i;
            }
            if (dp[3*i] > dp[i]+1)
            {
                dp[3*i] = dp[i]+1;
                trace[3*i] = i;
            }
            if (dp[i+1] > dp[i]+1)
            {
                dp[i+1] = dp[i]+1;
                trace[i+1] = i;
            }
        }
    while (test -- )
    {
        int x;
        cin >> x;
        vector <int> v;
        while (x != 1)
        {
            v.push_back(x);
            x = trace[x];
        }
        v.push_back(1);
        reverse(v.begin(), v.end());
        cout << v.size() << endl;
        for (auto x: v)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
