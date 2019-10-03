#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;
typedef pair <int, int> pii;

int n, m;
int ans = 0;
int a[maxn];
pair <int, int> e[maxn];



void check ()
{
    map <pii, int> s;
    int res = 0;
    for (int i = 1; i <= m; i++)
    {
        int fi = a[e[i].first];
        int se = a[e[i].second];
        if (s[(pii){fi, se}] == 1 || s[(pii){se, fi}] == 1)
            {
                continue;
            }
        res ++;
        s[{fi, se}] = 1;
    }
    ans = max(ans, res);
}

int solve(int pos)
{
    if (pos > n)
    {
        check();
        return 0;
    }
    for (int i = 1; i <= 6; i++)
    {
        a[pos] = i;
        solve(pos+1);
    }
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> e[i].first >> e[i].second;
    }
    solve(1);
    cout << ans;
    return 0;
}
