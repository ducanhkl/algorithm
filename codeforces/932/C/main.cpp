#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int t[maxn];
int n, a, b;
int sla, slb, check = false;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b;
    for (int i = 0; a*i <= n; i++)
        if ((n-a*i )% b == 0)
    {
        sla = i, slb = (n-a*i)/b;
        check = true;
        break;
    }
    if (!check)
        return cout << -1, 0;
    int vt = 1;
    for (int i = 1; i <= sla; i++)
    {
        cout << i*a << " ";
        for (int j = vt; j < i*a; j++)
            cout << j << " ";
        vt = vt + a;
    }
    vt--;
    int vx = 1;
    for (int i  = 1; i <= slb; i++)
    {
        cout << i*b + vt<< " ";
        for (int j = vx; j < i*b; j++)
            cout << j + vt << " ";
        vx = vx + b;
    }
    return 0;
}
