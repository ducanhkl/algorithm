#include <bits/stdc++.h>

using namespace std;

set <int> a, b;
long long pre = 0;
int n, k, dem = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> k >> n;
    for (int i = 1; i <= k; i++)
    {
        long long x;
        cin >> x;
        x += pre;
        pre = x;
        a.insert(x);
    }
    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        b.insert(x);
    }
    for (set <int>::iterator i = a.begin(); i != a.end(); i++)
    {
        bool dd = true;
        for (set <int>::iterator f = b.begin(); f != b.end(); f ++)
            if (a.count(*i - *(b.begin()) + *f) == 0)
                dd = false;
        if (dd)
            dem ++;
    }
    cout << dem;
    return 0;
}
