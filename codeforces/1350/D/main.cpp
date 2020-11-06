#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;

int n, k;
int a[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test -- )
    {
        cin >> n >> k;
        int ck1 = 0, ck2 = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] == k)
                ck1 = 1;
        }
        a[0] = -1;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] >= k && (a[i-1] >= k || a[i-2] >= k))
                ck2 = 1;
        }
        if (ck1 && (ck2 || n == 1))
            cout << "yes";
        else
            cout << "no";
        cout << endl;
    }
    return 0;
}
