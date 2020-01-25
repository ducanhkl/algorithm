#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n;
long double e[maxn], u;
long double ans = -1;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> u;
    for (int i = 1; i <= n; i++)
        cin >> e[i];
    int pos = 1;
    for (int i = 1; i <= n; i++)
    {
        while (pos <= n && e[pos] - e[i] <= u)
            pos++;
        pos--;
        if (pos < i+2)
            continue;
        ans = max(ans, (e[pos] - e[i+1])/(e[pos] - e[i]));
    }
    cout << fixed << setprecision(10) << ans;
    return 0;
}
