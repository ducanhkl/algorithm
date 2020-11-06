#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;

int n;
int a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        int l, r, m = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort (a+1, a+n+1);
        if (n%2)
        {
            r = (n+1)/2;
            l = (n/2);
        } else
        {
            r = n/2+1;
            l = r-1;
        }
        while (l >= 1 || r <= n)
        {
            if (m == 0)
            {
                cout << a[r];
                r ++;
            } else
            {
                cout << a[l];
                l --;
            }
            m = !m;
            cout <<  " ";
        }
        cout << endl;
    }
    return 0;
}
