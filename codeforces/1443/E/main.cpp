#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;

int q;
int dd[30];
long long e[maxn];
long long s[maxn], p[30], a[maxn];

void init(long long now, int n)
{
    now --;
    // memset(e, 0, sizeof(e));
    memset(dd, 0, sizeof(dd));
    int l = 1, r = n;
    if (n >= 15)
    {
        l = n-14;
    }
    for (int i = n-l; i >= 0; i--)
    {
        long long vt = now/p[i];
        int k = 0, j = 1;
        // cout << vt << endl;
        while (k < vt)
        {
            if (!dd[j])
                k++;
            j++;
        }
        while (dd[j])
            j++;
        e[n-i] = j;
        dd[j] = 1;
        now %= p[i];
    }
    for (int i = l; i <= r; i++)
    {
        s[i] = s[i-1] + e[i] + a[l-1];
    }
}

int main()
{
    // freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    p[0] = 1;
    for (int i = 1; i < 17; i++)
        p[i] = p[i-1]*i;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
        s[i] = s[i-1] + i;
    }
    long long now = 1;
    for (int i = 1; i <= q; i++)
    {
        int c;
        cin >> c;
        if (c == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << s[r] - s[l-1] << endl;
        } else
        {
            int add;
            cin >> add;
            now += add;
            init(now, n);
        }
    }
    return 0;
}
