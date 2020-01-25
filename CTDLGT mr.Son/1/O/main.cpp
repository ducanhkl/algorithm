#include <bits/stdc++.h>

using namespace std;

int n;
int a[40], b[40];
long long s;

void solve1()
{
    int ans = INT_MAX;
    for (int i = 1; i < (1<<n); i++)
    {
        long long t = 0;
        for (int j = 0; j < n; j++)
            if ((i>>j)&1)
                t += a[j+1];
        if (t == s)
            ans = min(ans, __builtin_popcount(i));
    }
    cout << ans;
}

void solve2()
{
    int ans = INT_MAX;
    map <long long, int> m1, m2, dd1, dd2;
    for (int i = 16; i <= n; i++)
        b[i-15] = a[i];
    int m = n-15;
    for (int i = 0; i < (1<<15); i++)
    {
        long long t = 0;
        for (int j = 0; j < 15; j++)
            if ((i>>j)&1)
                t += a[j+1];
        dd1[t] = 1;
        if (m1[t] != 0)
            m1[t] = min(m1[t], __builtin_popcount(i));
        else
            m1[t] = __builtin_popcount(i);
    }
    for (int i = 0; i < (1<<m); i++)
    {
        long long t = 0;
        for (int j = 0; j < m; j++)
            if ((i>>j)&1)
                t += b[j+1];
        dd2[t] = 1;
        if (m2[t] != 0)
            m2[t] = min(m2[t], __builtin_popcount(i));
        else
            m2[t] = __builtin_popcount(i);

    }
    for (map<long long, int>::iterator it = dd1.begin(); it != dd1.end(); it ++)
    {
        long long val = it->first;
        //cout << m1[val] << " " << m2[s-val] << endl;
        if (dd2[s-val])
            ans = min(ans, m1[val]+m2[s-val]);
    }
    cout << ans;
}


int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    if (s == 0)
        return cout << 0, 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n <= 15)
        solve1();
    else
        solve2();
    return 0;
}
