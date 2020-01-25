#include <bits/stdc++.h>
#define maxn 100004
using namespace std;


pair <int, int> a[maxn];

bool dd;

int m, n, kt = 0, dem = 0, res[maxn];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i].first >> a[i].second;
    sort(a+1, a+m+1);
    for (int i = 1; i <= 100; i++)
    {
        dd = 0;
        for (int j = 1; j <= m; j++)
            if ((a[j].second - 1)*i + 1 > a[j].first || a[j].first > a[j].second * i)
            {
                dd = 1;
                break;
            }
        if (!dd) res[++dem] = i;
    }
    for (int i = 1; i <= dem; i++)
        if (kt)
        {
            if (kt != (n-1)/res[i] + 1)
            {
                cout << -1;
                return 0;
            }
        }
            else kt = (n-1)/res[i] + 1;
    cout << kt;
    return 0;
}
