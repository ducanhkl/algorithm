#include <bits/stdc++.h>
#define maxn 100

using namespace std;

int n, tt = 0;
int a[maxn], b[maxn];

void dfs(int x)
{
    if (b[x] != a[x])
        return;
    tt ++;
    if (tt > 20000000)
        return;
    if (x == n)
    {
        cout << "YES";
        exit(0);
    }
    if (x == 13)
        n =n;
    for (int i = x+1; i <= n; i++)
        if (b[i]+a[x] <= a[i] && a[x] <= a[i] - 2)
    {
        b[i] += a[x];
        dfs(x+1);
        b[i]  -= a[x];
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        b[i] = 1;
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] == 2)
            {
                cout << "NO";
                exit(0);
            }
        }
    sort(a+1, a+n+1);
    dfs(1);
    cout << "NO";
    return 0;
}
