#include <bits/stdc++.h>

using namespace std;

int n;
long long ans = 0, pos, dr = 0, dg = 0, db = 0, ddr = 0, ddb = 0;
char c;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> pos >> c;
        if (c == 'R' || c == 'G')
        {
            if (dr)
            {
                ans += pos - dr;
                ddr = max(ddr, pos - dr);
            }
            dr = pos;
        }
        if (c == 'B' || c == 'G')
            {
                if (db)
                {
                    ans += pos - db;
                    ddb = max(ddb, pos - db);
                }
                db = pos;
            }
        if (c == 'G')
        {
            if (dg)
                ans += min(0LL, pos - dg - ddb - ddr);
            dg = pos, ddb = 0, ddr = 0;
        }
    }
    cout << ans;
    return 0;
}
