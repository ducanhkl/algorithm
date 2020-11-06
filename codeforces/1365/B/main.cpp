#include <bits/stdc++.h>

using namespace std;

int n;
int a[1000];
int b[1000];
int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n;
        //cout << n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        int sl0 = 0, sl1 = 0;
        for (int i = 1; i <= n; i++)
            if (b[i] == 0)
                sl0 ++;
            else
                sl1 ++;
        if (sl0 != n && sl1 != n)
        {
            cout << "Yes" << endl;
            continue;
        } else{
            string res = "Yes";
            for (int i = 2; i <= n; i++)
                if (a[i] < a[i-1])
                {
                    res = "No";
                    break;
                }
            cout << res << endl;
        }
    }
    return 0;
}
