#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;
int qqqqq;
long long a[maxn], ans[maxn] = {0, 1,1,5,1 ,21 ,1 ,85 ,73 ,341 ,89 ,1365,1 ,5461,4681 ,
21845 ,
1 ,
87381 ,
1 ,
349525,
299593 ,
1398101 ,
178481 ,
5592405 ,
1082401 ,
22369621};


int cnt1 = 0;

void init1()
{
    long long res = 3;
    while (res <= 1e10)
        a[++cnt1] = res, res = res*2+1;
}


int main()
{
    //freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    init1();
    cin >> qqqqq;
    for (int i = 1; i <= qqqqq; i++)
    {
        int x;
        cin >> x;
        if (!binary_search(a+1, a+cnt1+1, x))
        {
            int pos = upper_bound(a+1, a+cnt1+1, x)-a;
            cout << a[pos] << endl;
        } else
            {
                int pos = lower_bound(a+1, a+cnt1+1, x) - a;
                cout << ans[pos] << endl;
            }
    }
    return 0;
}
