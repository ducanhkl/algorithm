#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;

int n, t;
int a[maxn], b[maxn];

void solve ()
{
    cin >> n >> t;
    for (int i = 1; i <=  n; i++)
        cin >> a[i];
    set <int> s1, s2;
    for (int i = 1; i <= n; i++)
    {
        if (s2.count(a[i]) == 0)
        {
            s1.insert(a[i]);
            s2.insert(t-a[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (s1.count(a[i]))
            b[i] = 1;
        else
            b[i] = 0;
    }
    if (t%2 == 0)
    {
        int c = t/2;
        int num = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] == c)
                num ++;
        int num2 = num/2;

        for (int i = 1; i <= n && num2 != 0; i++)
            if (a[i] == c)
                b[i] = 0, num2--;
    }
    for (int i = 1; i <= n; i++)
        cout << b[i] << " ";
    cout << endl;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
