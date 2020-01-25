#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5+100;

int n;
long long res1 = 0, res2 = 0, res3 = 0;

struct data
{
    char s;
    int val;
} a[maxn];

long long calc(long long x)
{
    for (int i = 1; i <= n; i++)
    {
        if (a[i].s == '|')
            x |= a[i].val;
        if (a[i].s == '^')
            x ^= a[i].val;
        if (a[i].s == '&')
            x &= a[i].val;
    }
    return x;
}

long long get_bit(long long x, long long y)
{
    return (x>>y)&1;
}

int main()
{
    res1 = 1023;
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].s >> a[i].val;
    for (int i = 0; i <= 9; i++)
    {
        int num = (1LL<<i);
        long long on = calc(num);
        long long off = calc(0);
        int u = get_bit(on, i);
        int v = get_bit(off, i);
        if (u == 0 && v == 0)
            res1 ^= num;
        if (u == 1 && v == 1)
            res2 |= num;
        if (u == 0 && v == 1)
            res3 |= num;
    }
    cout << 3 << endl;
    cout << "& " << res1 << endl << "| " << res2 << endl << "^ " << res3;
    return 0;
}
