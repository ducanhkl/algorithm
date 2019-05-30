#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n;
int a[maxn], ans[maxn], cnt = 0;

void solve()
{
    deque <int> q;
    for (int i = n; i >= 1; i--)
    {
        while (q.size() && q.back() <= a[i])
            q.pop_back();
        if (q.size() == 0)
            ans[++cnt] = -1;
        else
            ans[++cnt] = q.back();
        q.push_back(a[i]);
    }
    for (int i = n; i >= 1; i--)
        cout << ans[i] << " ";
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
        memset(ans, 0, sizeof(ans));
        cnt = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        solve();
    }
    return 0;
}
