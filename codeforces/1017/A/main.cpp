#include <bits/stdc++.h>
#define maxn 2000

using namespace std;

struct data
{
    int m, h, b, f, pos;
};

int n;
data a[maxn];

bool cmp(data x, data y)
{
    int x1 = x.m+x.h+x.b+x.f;
    int x2 = y.m+y.h+y.b+y.f;
    if (x1 == x2)
        return x.pos < y.pos;
    else return x1>x2;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].m >> a[i].h >> a[i].b >> a[i].f, a[i].pos = i;
    sort(a+1,a+n+1, cmp);
    for (int i =1; i <= n; i++)
        if (a[i].pos == 1)
            cout << i;
    return 0;
}
