#include <bits/stdc++.h>

using namespace std;

long long a[50], n, l, r;
int t;

long long counter(long long x, long long y, int tong)
{
    int dd[20], num = 0;
    while (x != 0)
        dd[++num] = x%10, x /= 10;

}
unsigned long long calc(long long x)
{
    long long res = 0, tich;
    for (int i = 1; i < (1<<n); i++)
    {
        tich = 1;
        int tt;
        if (__builtin_popcount(i)%2)
            tt = 1;
        else tt = -1;
        for (int j = 0; j < n; j++)
            if ((i>>j)&1)
                tich *= a[j];
        for (int i = 1; i <= 162/tong; i++)
            res = res + counter(tong, x, tong*y) * tt;
    }
    return res;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> l >> r;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        long long t2 = calc(r);
        long long t1 = calc(l-1);
        cout << t2 - t1 << endl;
    }
    return 0;
}
