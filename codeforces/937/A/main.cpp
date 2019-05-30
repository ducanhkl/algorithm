#include <bits/stdc++.h>

using namespace std;

int n;
int a[700];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
            i--, n--;
    }
    sort(a+1, a+n+1);
    int ans = 1;
    for (int i = 2; i <= n; i++)
        if (a[i] != a[i-1])
            ans ++;
    cout << ans;
    return 0;
}
