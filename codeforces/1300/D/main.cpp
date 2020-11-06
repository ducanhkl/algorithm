#include <bits/stdc++.h>

using namespace std;

struct point {
    double x, y;
};

const int maxn = 1e5+100;

int n;
point p[maxn];

void solve()
{
    if (n%2 != 0)
    {
        cout << "NO";
        return ;
    }
    point m;
    m.x = (p[1].x + p[n/2+1].x)/2;
    m.y = (p[1].y + p[n/2+1].y)/2;
    for (int i = 1; i <= n; i++)
    {
        if (m.x != (p[i].x + p[(i+n/2)%(n+1)+(int)((i+n/2) > n)].x)/2)
        {
            cout << "NO";
            return;
        }
        if (m.y != (p[i].y + p[(i+n/2)%(n+1)+(int)((i+n/2) > n)].y)/2)
        {
            cout << "NO";
            return ;
        }
    }
    cout << "YES";
}


int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y;
    solve();
    return 0;
}
