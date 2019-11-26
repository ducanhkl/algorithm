#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e5+100;

int n;
int p[maxn], a[maxn], dd[maxn], s[maxn];

void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    a[1] = p[1];
    dd[a[1]] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (p[i] != p[i-1])
        {
            a[i] = p[i];
            dd[a[i]] = 1;
        }
    }
    int top = 0, now = 0;
    for (int i = 1; i <= n; i++)
        if (dd[i] == 0)
            s[++top] = i;
    for (int i = 1; i <= n; i++)
        if (a[i] == 0)
    {
        a[i] = s[++now];
    }
    int mx = a[1];
    for (int i = 2; i <= n; i++)
    {
        mx = max(a[i], mx);
        if (mx != p[i])
        {
            cout << -1 << endl;
            return ;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] <<  " ";
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
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            a[i] = 0;
            dd[i] = 0;
        }
        solve();
    }
    return 0;
}
