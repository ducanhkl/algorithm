#include <bits/stdc++.h>

using namespace std;

long long n, m, ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    if (n > m)
        swap(n, m);
    for (int i = 1; i <= n; i++)
        ans += (m-(5-(i%5)))/5+1;
    cout << ans;
    return 0;
}
