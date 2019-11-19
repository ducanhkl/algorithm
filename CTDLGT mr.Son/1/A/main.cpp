#include <bits/stdc++.h>

using namespace std;


int calc(int x)
{
    int ans = 0;
    while (x != 0)
    {
        if (x%2)
            ans++;
        x /= 2;
    }
    return ans;
}

void output(int x, int n)
{
    for (int i = n-1; i >= 0; i--)
        if ((x>>i)&1)
            cout << 1;
        else
            cout << 0;
}

int main()
{
    int t, n, k;
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < (1LL<<n); i++)
            if (calc(i) == k)
            {
                output(i, n);
                cout << endl;
            }
    }
    return 0;
}
