#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n;
long double s, res = 0;
int cnt[maxn];
struct p
{
    int x, y;
} a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    for (int i = 1; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
        cnt[a[i].x] ++;
        cnt[a[i].y] ++;
    }
    if (n == 2)
        return cout << fixed << setprecision(10) << s, 0;
    for (int i = 1; i <= n; i++)
        if (cnt[a[i].x] == 1 || cnt[a[i].y] == 1)
            res = res+1;
    cout << fixed << setprecision(10) << s*2/res;
    return 0;
}
