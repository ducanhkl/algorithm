#include <bits/stdc++.h>

using namespace std;

const int maxn = 70000;
int n;
long long ans = 0;
char a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] -= '0';
    for (long long i = 1; i <= n; i++)
        if (a[i] %2 == 0)
            ans += i;
    cout << ans;
    return 0;
}
