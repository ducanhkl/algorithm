#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        bool check = true;
        cin >> n;
        for (int i = 0; i <= n; i += 4)
            if ((n-i)%7 == 0)

        {
            for (int j = 1; j <= i/4; j++)
                cout << 4;
            for (int j = 1; j <= (n-i)/7; j++)
                cout << 7;
            check = false;
            break;
        }
        if (check)
            cout << -1;
        cout << endl;
    }
    return 0;
}
