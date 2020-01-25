#include <bits/stdc++.h>
#define maxn 1000

using namespace std;

long long a[maxn], b[maxn];
long long ans = 0;
int n, m;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans += (i-j)*(abs(a[i] - b[j]));
    cout << ans;
}
