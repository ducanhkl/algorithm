#include <iostream>

using namespace std;

const int maxn = 1e5+100;
int n;
int a[maxn], res[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int mi = 0;
    for (int i = 1; i <= n; i++)
    {
        mi = min(mi, a[i] - i);
        res[i] = mi+i;
    }
    mi = n+1;
    for (int i = n; i >= 1; i--)
    {
        mi = min(mi, a[i] + i);
        res[i] = min(res[i], mi-i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, res[i]);
    cout << ans;
    return 0;
}
