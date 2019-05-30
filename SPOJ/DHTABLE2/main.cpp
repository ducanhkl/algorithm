#include <bits/stdc++.h>

using namespace std;

int n;
long long a[20], p[20], t, _t, ans[200];

int get(long long x, int y)
{
    int dem = 0;
    int dd[20];
    while (x != 0)
        dd[++dem] = x%10, x/=10;
    if (y == 0)
        return dd[1];
    return dd[dem-y+1];
}
void init()
{
    a[1] = 9;
    p[0] = 1;
    for (int i = 1; i <= 16; i++)
        p[i] = p[i-1]*10;
    for (int i = 1; i <= 16; i++)
        a[i] = a[i-1] + p[i-1]*9*i;
    for (int i = 0; i <= n; i++)
        ans[i] = -1;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> _t;
    init();
    for (int i = 1; i <= n; i++)
    {
        long long t = _t+i-n;
        if (t <= 0)
            continue;
        int dem = 1;
        while (a[dem] < t)
            dem ++;
        dem --;
        if (dem == 0)
        {
            ans[i] = t;
            continue;
        }
        t -= a[dem];
        long long res = ceil(t*1.0/(dem+1)) + p[dem] - 1;
        ans[i] = get(res, t%(dem+1));
    }
    for (int i = 1; i <= n; i++)
        if (ans[i] != -1)
            cout << ans[i];
        else cout << " ";
    return 0;
}
