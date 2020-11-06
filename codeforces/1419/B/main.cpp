#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        long long x;
        cin >> x;
        long long u = 1LL, sum = 1;
        int res = 1;
        while (sum <= x)
        {
            u = u*2 + 1;
            sum += (u*(u+1))/2;
            if (sum > x)
                break;
            res ++;
        }
        cout << res << endl;
    }
    return 0;
}
