#include <bits/stdc++.h>

using namespace std;

int f1[300], f2[300], p[300];
int n, t;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> t;
    p[0] = 1;
    while (t--)
    {
        memset(f1, 0, sizeof(f1));
        memset(f2, 0, sizeof(f2));
        cin >> n;
        for (int i = 1; i <= 210;i++)
            p[i] = (p[i-1]*10)%n;
        for (int i = 1; i <= 200; i ++)
            f1[i] = (f1[i-1]*10+8)%n;
        for (int i = 1; i <= 200; i++)
            f2[i] = (f2[i-1]*10+6)%n;
        bool check = 1;
        for (int i = 1; i <= 200 && check; i++)
            for (int j = i; j >= 0 && check; j--)
        {
            int du = ((f1[i-j]*p[j])%n+f2[j])%n;
            if (du == 0)
                {
                    for (int k = 1; k <= i-j; k++)
                        cout << 8;
                    for (int k = 1; k <= j; k++)
                        cout << 6;
                    cout << endl;
                    check = 0;
                }
        }
        if (check)
            cout << -1 << endl;
    }
    return 0;
}
