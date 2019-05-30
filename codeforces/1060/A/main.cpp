#include <bits/stdc++.h>

using namespace std;

char a[200];
int n, cnt = 0, ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i]  == '8')
            cnt++;
    }
    for (int i = 1; i <= cnt; i++)
        ans = max(ans, min(i, (n-i)/10));
    cout << ans;
    return 0;
}
