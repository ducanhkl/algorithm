#include <bits/stdc++.h>
#define maxn 600000

using namespace std;

long long a[maxn], ma[maxn], mi[maxn], ans = 0;
int n;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n == 1)
        return cout << a[1], 0;
    sort(a+1, a+n+1);
    if (a[1] >= 0)
    {
        for (int i = 2; i <= n; i++)
            ans += a[i];
        ans -= a[1];
        cout << ans;
        return 0;
    }
    else
    {
        int pos = 1;
        while (a[pos+1] < 0 && pos+1 <= n)
            pos ++;
        ans += -a[pos];
        for (int i = 1; i <= n; i++)
            if (i != pos)
                ans += abs(a[i]);
        cout << ans;
        return 0;
    }
    return 0;
}
