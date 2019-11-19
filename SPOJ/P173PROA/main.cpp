#include <bits/stdc++.h>

using namespace std;

int n;
map <long long, int> m;
long long a[1001], s[1001], b[1001];

int ans = 0, res;

void timkiem(int x, int y)
{
    int z = x+y;
    int vt = lower_bound(a+1,a+n+1, z)-a;
    if (s[vt] <= 0 || z != a[vt])
        return;
    s[vt] --;
    res ++;
    ans = max(ans,res);
    timkiem(y, z);
    res--;
    s[vt] ++;
    return;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        m[a[i]] ++;
    }
    n = 0;
    for (map<long long, int>::iterator IT = m.begin(); IT != m.end(); IT++)
        a[++n] = IT->first, s[n] = IT->second;
    for (int i = 1; i <= n; i++)
        b[i] =  lower_bound(a+1,a+n+1, a[i])-a;
    for (int i = 1; i <= n; i++)
        for (int j  = 1; j <= n; j++)
            {
                long long   first = a[i], second = a[j];
                int vt1 = lower_bound(a+1,a+n+1, first)-a, vt2 = lower_bound(a+1,a+n+1, second)-a;
                s[vt1] --;
                s[vt2] --;
                res = 2;
                if (!(s[vt1] < 0 || s[vt2] < 0))
                    timkiem(first, second);
                s[vt1]++;
                s[vt2]++;
                ans = max(ans, res);
            }
    cout << ans;
    return 0;
}
