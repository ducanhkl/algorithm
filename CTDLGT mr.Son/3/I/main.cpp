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
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a+1, a+n+1);
        bool check = true;
        for (int i = 1; i < n; i++)
        {
            int val = a[i] + a[i+1];
            int pos = lower_bound(a+1, a+n+1, val)-a;
            if (pos-1 > i+1)
            {
                cout << "YES";
                check = false;
                break;
            }
        }
        if (check)
            cout << "NO";
        cout << endl;
    }
    return 0;
}
