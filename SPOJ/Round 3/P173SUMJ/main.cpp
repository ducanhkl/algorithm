#include <bits/stdc++.h>
#define maxn 100004

using namespace std;

int a[maxn], d[maxn];
int t, n;

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> t;
    while (t --)
    {
        memset(a, 0, sizeof(a));
        memset(d, 0, sizeof(d));
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i], d[a[i]] ++;
        int dem = 0;
        for (int i = 1; i <= 110; i++) dem += d[i]/2;
        cout << dem/2 << endl;
    }
    return 0;
}
