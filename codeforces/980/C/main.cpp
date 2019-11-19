#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int a[maxn], dd[500], res[maxn], d[maxn];
int n, k;

int main()
{
    freopen("inp.txt", "r", stdin);
    for (int i = 0; i < 500; i++)
        dd[i] = INT_MAX;
    memset(d, 0, sizeof(d));
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    return 0;
}
