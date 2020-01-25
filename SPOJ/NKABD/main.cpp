#include <bits/stdc++.h>
#define maxn 100005

using namespace std;


int l, r;
long long dd[maxn], ans[maxn];

void init()
{
    memset(ans, 0, sizeof(ans));
    memset(dd, 0, sizeof(dd));
    for (int i = 1; i < maxn; i++)
        for (int j = 2*i; j < maxn; j += i)
            dd[j] += i;
    for (int i = 1; i < maxn; i++)
        if (dd[i] > i)
            ans[i] = ans[i-1] + 1;
        else ans[i] += ans[i-1];
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    init();
    cin >> l >> r;
    cout << ans[r] - ans[l-1];
    return 0;
}
