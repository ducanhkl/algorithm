#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    sort (a+1, a+n+1);
    int l = 0;
    res[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        while (a[l].second < a[i].first)
            l++;
        res[i] = res[l+1];
        if (res[i] == n)
            cout << ""
    }
    return 0;
}
