#include <bits/stdc++.h>
#define maxn 100006

using namespace std;

long long n, ans = 0, dd[maxn],dem1 = 0, dem2 = 0;
char a[maxn], b[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(dd, 0, sizeof(dd));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], dd[i] = dd[i-1] + a[i] - '0';
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        if (b[i] == '0')
            if (a[i] == '0')
                ans += dd[i-1] + dd[n] - dd[i];
            else
                ans += i-1-dd[i-1] + (n- i) - (dd[n] - dd[i]);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == '1' && b[i] == '0')
            dem1++;
        if (a[i] == '0' && b[i] == '1')
            dem2++;
    }
    cout << ans-dem1*dem2;
    return 0;
}
