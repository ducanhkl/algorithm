#include <iostream>

using namespace std;

const int maxn = 1e4+100;



int main()
{
    //freopen("inp.txt", "r", stdin);
    int test;
    cin >> test;
    while (test --)
    {
        int n;
        int oo =0, oe = 0, eo = 0, ee = 0;
        char a[maxn];
        cin >> n;
        if (n == 1)
        {
            int x;
            cin >> x ;
            if (x%2)
                cout << 1;
            else
                cout << 2;
            cout << endl;
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] -= '0';
            if (a[i]%2 == 0)
            {
                if (i % 2 == 0)
                {
                    ee ++;
                } else
                {
                    eo ++;
                }
            } else
            {
                if (i % 2 == 0)
                {
                    oe ++;
                } else
                {
                    oo++;
                }
            }
        }
        if (n % 2 == 0)
        {
            if (oe == (n/2)) {
                cout << 1;
            } else
            {
                cout << 2;
            }
        } else
        {
            if (eo == (n/2+1))
            {
                cout << 2;
            } else
            {
                cout << 1;
            }
        }
        cout << endl;
    }
    return 0;
}
