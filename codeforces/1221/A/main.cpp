#include <bits/stdc++.h>

using namespace std;

int n;
int dd[70];

void solve()
{
    memset(dd, 0, sizeof(dd));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, cnt = 0;
        cin >> x;
        while (x != 1)
            x /= 2, cnt ++;
        dd[cnt] ++;
    }
    for (int i = 0; i <= 11; i++)
    {
        if (dd[i] != 0)
        {
            dd[i+1] += dd[i]/2;
        }
    }
    if (dd[11] != 0)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
