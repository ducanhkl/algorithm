#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;

struct point
{
    int p, l;
} a[maxn];

int n;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].p;
        a[i].l = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i+n].p;
        a[i].l = 2;
    }
    n *= 2;
    sort (a+1, a+n+1, [] (point x, point y) {
            return x.p < y.p;
        });
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i].l != a[i-1].l)
        {
            ans ++;
            i ++;
        }
    }
    cout << ans;
    return 0;
}
