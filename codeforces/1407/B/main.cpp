#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e3+100;

int n;
int a[maxn], b[maxn], ck[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            ck[i] = 0;
        }
        sort(a+1, a+n+1, greater<int>());
        b[1] = a[1];
        int uc = a[1];
        for (int i = 2; i <= n; i++)
        {
            int vt = -1;
            for (int j = 2; j <= n; j++)
            {
                if (ck[j])
                    continue;
                if (vt == -1)
                {
                    vt = j;
                    continue;
                }
                if (__gcd(uc, a[vt]) < __gcd(uc, a[j]))
                    vt = j;
            }
            ck[vt] = 1;
            b[i] = a[vt];
            uc = __gcd(uc, a[vt]);
        }
        for (int i = 1; i <= n; i++)
            cout << b[i] << " ";
        cout << endl;
    }
    return 0;
}
