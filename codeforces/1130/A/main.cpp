#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;
int n;
int a[maxn], dem1 = 0, dem2 = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > 0)
            dem1++;
        if (a[i] == 0)
            dem2++;
    }
    if (dem1 >= (n+1)/2)
        return cout << 1, 0;
    if (n-dem1-dem2 >= (n+1)/2)
        return cout << -1, 0;
    cout << 0;
    return 0;
}
