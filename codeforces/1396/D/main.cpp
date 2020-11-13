#include <bits/stdc++.h>

using namespace std;


void init()
{
    vx.push_back()
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    vx.erase(unique(vx.begin(), vx.end()));
    vy.erase(unique(vx.begin(), vx.end()));
    for (int i = 1; i <= n; i ++ )
    {

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> l;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].x >> p[i].y >> p[i].c;
        p[i].x ++;
        p[i].y ++;
        vx.push_back(p[i].x);
        vy.push_back(p[i].y);
        vx.push_back(p[i].x+1);
        vy.push_back(p[i].y+1);
    }
    init();
    solve();
    return 0;
}
