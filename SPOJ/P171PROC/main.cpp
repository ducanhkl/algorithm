#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

long double l;
int n, a[maxn];
pair <long double, long double> dd[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    long double l = 0, r = 1000000001, g = (l+r)/2;
    while (r - l > 1e-10)
    {
        g = (l+r)/2;
        memset(dd, 0, sizeof(dd));
        dd[0].second = 0;
        dd[n+1].first = l;
        for (int i = 1; i <= n; i++)
        {
            dd[i].first = a[i] - g;
            dd[i].second = a[i] + g;
        }
        bool check = true;
        for (int i = 1; i <= n; i++)
            if (dd[i].first > dd[i-1].second || dd[i].second < dd[i+1].first)
                check = false;
        if (check)
            r = g;
        else l = g;
    }
    cout << fixed << setprecision(10) << (l+r)/2;
    return 0;
}
