#include <bits/stdc++.h>
#define maxn 100001

using namespace std;

map <int, int> m;
int n, b, ans = 0;
int a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        int y = b - a[i];
        ans += m[y];
        m[a[i]] ++;
    }
    cout << ans;
    return 0;
}
