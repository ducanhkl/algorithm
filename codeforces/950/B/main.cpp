#include <bits/stdc++.h>

using namespace std;

int n, m, ans = 0;
int a[100001], b[100001], tong = 0, s = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        tong += a[i];
        while (s < tong)
            s += b[j++];
        if (s==tong)
            ans ++,  s= 0, tong = 0;
    }
    cout << ans;
    return 0;
}
