#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;
int n;
int a[maxn], b[maxn], res[maxn];
int vta[maxn], vtb[maxn];

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        vta[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        vtb[b[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int numRoto;
        if (vta[i] > vtb[i])
        {
            numRoto = n-vta[i] + vtb[i];
        } else
            {
                numRoto = vtb[i] - vta[i];
            }
        res[numRoto] ++;
    }
    cout << *max_element(res, res+n);
    return 0;
}
