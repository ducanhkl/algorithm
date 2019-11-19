#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e3+100;

long long x[maxn], y[maxn];

long long area(int a, int b, int c)
{
    return abs((x[b]-x[a])*(y[c]-y[a])-(x[c]-x[a])*(y[b]-y[a]));
}
int n;

int maxarea(int &a, int &b, int &c)
{
    while (true)
    {
        bool flag = false;
        long long s = area(a, b, c);
        for (int i = 1; i <= n; i++)
        {
            if (s < area(i, b, c))
                a = i, flag = true;
            else
                if (s < area(a, i, c))
                    b = i, flag = true;
            else
                if (s < area(a, b, i))
                    c = i, flag = true;
        }
        if (!flag)
            break;
    }
    //return (ld)area(a, b, c)/2;
    return 0;
}

void out(int a, int b, int c)
{
    cout << x[a] + x[b] - x[c] << " " << y[a] + y[b] - y[c] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("inp.txt", "r", stdin);
    int a, b, c;
    long long _;
    cin >> n >> _;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    a = 1, b = 2, c = 3;
    maxarea(a, b, c);
    out(a, b, c);
    out(a, c, b);
    out(b, c, a);
    return 0;
}
