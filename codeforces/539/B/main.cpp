#include <bits/stdc++.h>
#define maxn 100001

using namespace std;

int a[maxn], b[maxn];
int n, k, dem = 0;

int main()
{
    memset(a, 0, maxn);
    memset(b, 0, maxn);
    freopen("inp.txt", "r", stdin);
    cin >> n >> k;
    a[4] = n, a[2] = 2*n;
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        while (x >= 3)
            if (a[4] > 0)
                a[4] --, x -= 4;
            else if (a[2] > 0)
                a[2] --, x -= 2;
            else return cout << "NO", 0;
        b[x] ++;
    }
    while (b[2])
        if (a[2] > 0)
            b[2] --, a[2] --;
        else if (a[4] > 0)
            b[2] --, a[4] --, a[1] ++;
        else b[2] --, b[1] += 2;
    if (b[1] > a[2] + a[4]*2 + a[1])
        return cout << "NO", 0;
    cout << "YES";
    return 0;
}
