#include <bits/stdc++.h>

using namespace std;

void solve(long long x, long long y)
{
    set <int> s;
    if (x >= y)
    {
        cout << "YES" << endl;
        return ;
    }
    while (x <= y)
    {
        if (s.count(x))
        {
            break;
        }
        s.insert(x);
        if (x == 1)
        {
            break;
        }
        if (x%2)
        {
            x --;
            continue;
        }
        x /= 2;
        x *= 3;
        if (x >= y)
        {
            cout << "YES" << endl;
            return ;
        }
    }
    cout << "NO" << endl;
    return ;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        long long x, y;
        cin >> x >> y;
        solve(x, y);
    }
    return 0;
}
