#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;

struct point
{
    long long x, y;
} p[maxn];

bool cmp(point x, point y)
{
    if (x.x == y.x)
    {
        return x.y > y.y;
    }
    return x.x < y.x;
}

int n, ans = 0;

bool ccw(point a, point b, point c)
{
    return  a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x * (a.y - b.y) > 0;
}

bool cw(point a, point b, point c)
{
    return  a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x * (a.y - b.y) < 0;
}

void solve()
{
    vector <point> res;
    sort(p+1, p+n+1, cmp);
    point p1 = p[1], p2 = p[n];
    res.push_back(p1);
    for (int i = 1; i <= n; i ++)
    {
        if (p[i].x == res.back().x)
            continue;
        if (i == n || cw(p1, p[i], p2))
        {
            while (res.size() >= 2 &&
                    !cw(res[res.size()-2], res[res.size()-1], p[i]) )
            {
                //cout << res.back().x << " " << res.back().y << endl;
                res.pop_back();
            }
            // cout << endl;
            res.push_back(p[i]);
        }
    }
    ans = res.size()-1;
}

int main()
{
    // freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].x >> p[i].y;
        p[i].y =  p[i].y - p[i].x * p[i].x;
    }
    solve();
    cout << ans;
    return 0;
}
