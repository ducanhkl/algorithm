#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e4+200;

struct data
{
    long long x, y, z, pos;
} p[maxn];

int n;
int lasz = -1e9, lasy = -1e9l;

bool cmpbyx(data x, data y)
{
    return x.x < y.x;
}

bool cmpbyy(data x, data y)
{
    return abs(x.y-lasy) < abs(y.y - lasy);
}
bool cmpbyz(data x, data y)
{
    return abs(x.z - lasz) < abs(y.z - lasz);
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].x >> p[i].y >> p[i].z;
        p[i].pos = i;
    }
    sort(p+1, p+n+1, cmpbyx);
    for (int i = 1; i <= n; )
    {
        int l = i, r = i;
        while (r+1 <= n && p[r+1].x == p[i].x)
            r++;
        sort(p+l, p+r+1, cmpbyy);
        for (int j = l; j <= r;)
        {
            int ll = j, rr = j;
            while (rr+1 <= r && p[rr+1].y == p[j].y)
                rr++;
            sort(p+ll, p+rr+1, cmpbyz);
            lasz = p[rr].z;
            j = rr+1;
        }
        lasy = p[r].y;
        i=r+1;
    }
    for (int i = 1; i <= n; i += 2)
        cout << p[i].pos << " " << p[i+1].pos << endl;
    return 0;
}
