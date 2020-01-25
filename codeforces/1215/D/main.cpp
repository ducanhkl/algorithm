#include <bits/stdc++.h>

using namespace std;

int cnt1 = 0, sum1 = 0, cnt2 = 0, sum2 = 0;

int main()
{
    int n;
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char x;
        cin >> x;
        if (i <= n/2)
        {
            if (x == '?')
                cnt1 ++;
            else
                sum1 += x - '0';
        } else
        {
            if (x == '?')
                cnt2 ++;
            else
                sum2 += x-'0';
        }
    }
    if (sum1-sum2 == (cnt2-cnt1)*9/2)
        cout << "Bicarp";
    else
        cout << "Monocarp";
    return 0;
}
