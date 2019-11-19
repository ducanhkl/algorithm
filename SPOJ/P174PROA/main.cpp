#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int sl[maxn], a[maxn];
int n, dem = 0, k;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1;; i++)
    {
        memset(sl, 0, sizeof(sl)), dem = 0;
        for (int j = 1; j <= n; j++)
        {
            sl[a[j]%i] ++;
            if (sl[a[j]%i]>1)
                dem ++;
        }
        if (dem <= k)
            return cout << i, 0;
    }
    return 0;
}
