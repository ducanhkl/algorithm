#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+100;
int dd[maxn], a[8], b[9];

int toint(int arr[])
{
   return arr[6]+arr[5]*1e1+arr[4]*1e2+arr[3]*1e3+arr[2]*1e4+arr[1]*1e5;
}

int nxt1(int x)
{
    int p[] = {1, 10, 100, 1000, 10000, 100000}, arr[10], res[10];
    for (int i = 1; i <= 6; i++)
        arr[i] = (x/p[6-i])%10;
    res[1] = arr[4];
    res[2] = arr[1];
    res[3] = arr[3];
    res[4] = arr[5];
    res[5] = arr[2];
    res[6] = arr[6];
    return toint(res);
}

int nxt2(int x)
{
    int p[] = {1, 10, 100, 1000, 10000, 100000}, arr[10], res[10];
    for (int i = 1; i <= 6; i++)
        arr[i] = (x/p[6-i])%10;
    res[1] = arr[1];
    res[2] = arr[5];
    res[3] = arr[2];
    res[4] = arr[4];
    res[5] = arr[6];
    res[6] = arr[3];
    return toint(res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    for (int i = 1; i <= 6; i++)
        cin >> a[i];
    for (int i = 1; i <= 6; i++)
        cin >> b[i];
    int f = toint(a);
    int s = toint(b);
    memset(dd, 0, sizeof(dd));
    dd[f] = 1;
    deque <int> q;
    q.push_back(f);
    while (q.size())
    {
        int u = q.front();
        q.pop_front();
        int v1 = nxt1(u);
        int v2 = nxt2(u);
        if (dd[v1] == 0)
            dd[v1] = dd[u]+1, q.push_back(v1);
        if (dd[v2] == 0)
            dd[v2] = dd[u]+1, q.push_back(v2);
        if (dd[s])
            break;
    }
    cout << dd[s]-1;
    return 0;
}
