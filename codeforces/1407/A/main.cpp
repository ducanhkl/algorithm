#include <bits/stdc++.h>

using namespace std;


const int maxn = 1200;

int n;
int sum = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n;
        int dem = 0;
        sum = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            sum += x;
        }
        int x;
        if (sum > n-sum)
            n = (sum/2)*2, x = 1;
        else
            n = n-sum, x = 0;
        cout << n << endl;
        for (int i = 1; i <= n; i++)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
