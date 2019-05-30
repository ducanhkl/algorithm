#include <bits/stdc++.h>

using namespace std;

int n, h, a, b, k, ans, ta, fa, tb, fb;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> h >> a >> b >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> ta >> fa >> tb >> fb;
        ans = abs(tb - ta);
        if (fa > b)
            ans += fa - b + abs(fb-b);
        else
            if (fa < a)
                ans += a-fa+abs(a-fb);
            else ans += abs(fa-fb);
        if (tb == ta)
            ans = abs(fb - fa);
        cout << ans << endl;
    }
    return 0;
}
