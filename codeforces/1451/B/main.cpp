#include <bits/stdc++.h>

using namespace std;


const int maxn = 200;
int n;
int a[maxn], d1[maxn], d2[maxn];


bool solve(int l, int r)
{
    int _l = l;
    for (int i = 1; i <= n; i++)
        d1[i] = 0, d2[i] = 0;
    int tot = l-5;
    for (int i = 1; i <= n; i++)
    {
        d1[i] = tot;
        if (l <= r && a[i] == a[l])
        {
            tot = l;
            l ++;
            d1[i] = tot;
        }
    }
    l = _l;
    tot=r+5;
    for (int i = n; i >= 1; i--)
    {
        d2[i] = tot;
        if (l <= r && a[i] == a[r])
        {
            tot = r;
            r --;
            d2[i] = tot;
        }
    }
    for (int i = 1; i < n-1; i++)
    {
        if (d1[i]+1 >= d2[i+2])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while ( test --)
    {
        int q;
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
        {
            char c;
            cin >> c;
            a[i] = c- '0';
        }
        for (int i = 1; i <= q; i++)
        {
            int l, r;
            cin >> l >> r;
            if (solve(l, r))
            {
                cout << "YES";
            }
            else
            {
                cout << "NO";
            };
            cout << endl;
        }
    }
    return 0;
}
