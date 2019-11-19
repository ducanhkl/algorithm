#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n, ans = 0;
int a[maxn], dd[maxn];

int main()
{
    memset(dd, 0, sizeof(dd));
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (a[j] > a[i] && !dd[j])
    {
        dd[j] = true;
        ans ++;
        break;
    }
    cout << ans;
    return 0;
}
