/*
#include <bits/stdc++.h>

using namespace std;

int n, p, vt[20], ans = 0, a[20];

void check()
{
    int res = 0;
    int m = 0;
    for (int i = 1; i <= p; i++)
    {
        if (m == 1)
            if (vt[i] == 1)
                res += a[i]+10-1;
            else
                res += a[i]-1;
        else
            if (vt[i] == 1)
                res += a[i]+10;
            else
                res += a[i];
        if (vt[i] == 1)
            m = 1;
        else
            m = 0;
    }
    if (m == 1)
        return;
    else
        ans = max(ans , res);
    if (ans == 19)
        n = n;
    return;

}

int gen(int pos)
{
    if (pos > p)
    {
        check();
        return 0;
    }
    for (int i = 0; i <= 2; i++)
    {
        vt[pos] = i;
        gen(pos+1);
    }
    return 0;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    int _n = n;
    while (_n != 0)
        _n /= 10, p ++;
    _n = n;
    int tt = 0;
    while (_n != 0)
        a[++tt] = _n%10, _n/= 10;
    gen(1);
    cout << ans;
    return 0;
}*/


#include <bits/stdc++.h>

using namespace std;

long long n;
int cnt = 0;
int a[20], res = 0;

int main()
{
    cin >> n;
    long long _n = n;
    while (_n != 0)
        a[++cnt] = _n%10, _n /= 10;
    for (int i = 2; i < cnt; i++)
        res += 10 + a[i]-1;
    if (cnt == 1)
        res += a[1];
    else res += a[cnt]-1, res += a[1]+10;
    cout << res;
}
