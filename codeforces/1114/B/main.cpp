#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;
int n, m, k;
long long a[maxn], b[maxn];
map <long long, int> dd;
long long ans = 0;

int main()
{
    for (int i = 1; i <= 1e7; i++)
            i = i;
    ios_base::sync_with_stdio(false);
    cin >> n >> m>> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = a[i];
    sort(b+1, b+n+1, greater <long long>());
    for (int i = 1; i <= m*k; i++)
        dd[b[i]] ++, ans += b[i];
    cout << ans <<endl;
    int dem = 0, sl = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dd[a[i]])
        {
            dd[a[i]]--;
            dem++, sl++;
            if (dem == m && sl != m*k)
            {
                dem = 0;
                cout << i << " ";
            }
        }
    }
    return 0;
}
