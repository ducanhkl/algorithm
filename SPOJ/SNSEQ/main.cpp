#include <bits/stdc++.h>
#define maxn 1006

using namespace std;


const long double eps = 1e-8;
long double a[maxn], res = 0;
int n;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> a[1];
    long double l = 0, r = a[1];
    while (r - l > eps)
    {
        long double mid = (l+r)/2;
        a[2] = mid;
        bool check = true;
        for (int i = 3; i <= n; i++)
        {
            a[i] = (a[i-1]+1)*2 - a[i-2];
            if (a[i] < 0)
                {
                    check = false;
                    break;
                }
        }
        if (check)
            r = mid, res = a[n];
        else l = mid;
    }
    cout << fixed << setprecision(2) << res;
    return 0;
}
