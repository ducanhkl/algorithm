#include <bits/stdc++.h>

using namespace std;

int solve(int c,int m, int x)
{
    int l = 0, r = 1e9 ,res = 0;
    while (l <= r)
    {
        int mid = (l+r)/2;
        if (mid <= c && mid <= m && (c-mid+m-mid+x >= mid))
            res = mid, l = mid+1;
        else
            r = mid-1;
    }
    cout << res << endl;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    int c, m, x;
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> c >> m >> x;
        solve(c, m, x);
    }
    return 0;
}
