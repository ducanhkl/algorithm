#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n, test;
long long a[maxn];


bool check()
{
    for (int i = 2; i <= n; i++)
        if (a[i] < a[i-1])
            return false;
    return true;
}

void solve()
{
    if (check())
    {
        cout << 0 << endl;
        return ;
    }
    long long val = 0, num = a[1];
    for (int i = 1; i <= n; i++)
    {
        val = max(val, num-a[i]);
        num = max(num, a[i]);
    }
    int ans = 0;
    while (((1LL << ans+1)-1) < val)
        ans++;
    cout << ans+1 << endl;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> test;
    while (test--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        solve();
    }
    return 0;
}
