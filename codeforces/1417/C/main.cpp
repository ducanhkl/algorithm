#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5+100;
int n;
int a[maxn], ans[maxn], last[maxn], maxD[maxn];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        last[i] = 0;
        ans[i] = INT_MAX;
        maxD[i] = INT_MIN;
    }
    for (int i = 1; i <= n; i++)
    {
        maxD[a[i]] = max(maxD[a[i]], i-last[a[i]]);
        last[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        maxD[i] = max(maxD[i], n+1-last[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (maxD[i]  != INT_MIN)
        {
            ans[maxD[i]] = min(i, ans[maxD[i]]);
        }
    }
    for (int i = 2; i <= n; i++)
        ans[i] = min(ans[i] ,ans[i-1]);
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == INT_MAX)
        {
            cout << -1;
        } else
        {
            cout << ans[i];
        }
        cout <<  " ";
    }
    cout << endl;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
