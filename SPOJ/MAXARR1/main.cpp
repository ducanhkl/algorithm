#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

long long a[maxn], ans[maxn];
int n;

void init()
{
    memset(ans, 0, sizeof(ans));
    a[0] = 0;
    ans[0] = a[0];
    a[1] = 1;
    for (int i = 2; i < maxn; i++)
        if (i%2)
            a[i] = a[i/2] + a[i/2+1];
        else a[i] = a[i/2];
    for (int i = 1; i < maxn; i++)
        ans[i] = max(ans[i-1], a[i]);
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    init();
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}
