#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+100;
int n;

struct point
{
    int x, y;
    int pos;
} p[maxn];

bool cmp(point &x, point &y)
{
    if (x.x == y.x)
    {
        if (x.x%2)
            return x.y > y.y;
        else
            return x.y < y.y;
    }
    return x.x < y.x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].x >> p[i].y;
        p[i].pos = i;
        p[i].x /= 1000;
    }
    sort (p+1, p+n+1, cmp);
    for (int i = 1; i <= n; i++)
        cout << p[i].pos << " ";
    return 0;
}
