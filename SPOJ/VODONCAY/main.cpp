#include <bits/stdc++.h>

using namespace std;


const int maxn = 4003000;

int n;
int a[maxn];
int dp[maxn], l[maxn], r[maxn], trace[maxn];

void init()
{
    deque <int> s;
    for (int i = 1; i <= n; i++)
    {
        l[i] = i;
        while (!s.empty() && s.back() > i-a[i])
        {
            l[i] = min(l[i], l[s.back()]);
            s.pop_back();
        }
        s.push_back(i);
    }
    s.clear();
    for (int i = n; i>= 1; i--)
    {
        r[i] = i;
        while (!s.empty() && s.back() < i+a[i])
        {
            r[i] = max(r[i], r[s.back()]);
            s.pop_back();
        }
        s.push_back(i);
    }
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        dp[i] = i;
        trace[i]  = -i;
    }
    deque <int> s;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] > dp[l[i]-1] + 1)
        {
            dp[i] = dp[l[i]-1] + 1;
            trace[i] = -(l[i]);
        }
        while (!s.empty() && r[s.back()] < i)
            s.pop_back();
        if (!s.empty() && dp[i] > dp[s.back()-1] + 1)
        {
            dp[i] = dp[s.back() - 1]+1;
            trace[i] = s.back();
        }
        if (s.empty() || dp[s.back()-1] > dp[i-1])
        {
            s.push_back(i);
        }
    }
    cout << dp[n] << endl;
    for (int i = n; i != 0; i = abs(trace[i]) - 1)
    {
        if (trace[i] < 0)
        {
            cout << -i;
        } else
        {
            cout << trace[i];
        }
        cout << " ";
    }
}

int main()
{
    // freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    init();
    solve();
    return 0;
}
