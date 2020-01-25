#include <bits/stdc++.h>
#define maxn 100006

using namespace std;

int n1, n2, y;
int a[maxn], b[maxn], ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n1 >> y;
    for (int i = 1; i <= n1; i++)
        cin >> a[i];
    cin >> n2 >> y;
    for (int i = 1; i <= n2; i++)
        cin >> b[i];
    if (n1 == n2 && n2 == 1 && a[1] == b[1])
    {
        cout << 2;
        return 0;
    }
    for (long long dx = 1; dx <= 1e9; dx *= 2)
    {
        long long mx = dx*2;
        map <long long, int> m;
        for (int i = 1; i <= n1; i++)
            m[a[i]%mx]++;
        for (int i = 1; i <= n2; i++)
            m[(b[i]+dx)%mx]++;
        for (map <long long, int>::iterator it = m.begin(); it != m.end(); it++)
            ans = max(ans, it->second);
    }
    cout << ans;
    return 0;
}
