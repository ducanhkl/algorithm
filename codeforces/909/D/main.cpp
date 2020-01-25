#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+100;

int n;
int ans = 0;
string s;

struct data
{
    int val, len;
} a[maxn];

void Merge()
{
    int len = n;
    n = 0;
    for (int i = 1; i <= len; i++)
    {
        if (a[i].len <= 0)
            continue;
        if (a[i].val == a[n].val)
            a[n].len += a[i].len;
        else
            a[++n] = a[i];
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> s;
    n = s.length();
    a[0].len = 0;
    a[0].val = -1;
    for (int i = 1; i <= n; i++)
        a[i].val = s[i-1] - 'a' + 1, a[i].len = 1;
    Merge();
    while (n > 1)
    {
        for (int i = 2; i < n; i++)
            a[i].len -= 2;
        a[1].len --;
        a[n].len --;
        Merge();
        ans++;
    }
    cout << ans;
    return 0;
}
