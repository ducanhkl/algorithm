#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+100;
int n;
long long cnt1, cnt2, ans1, ans2;
int a[maxn];

int main()
{
    //freopen("inp,txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > 0)
        {
            cnt1 ++;
        } else
        {
            swap(cnt1, cnt2);
            cnt2++;
        }
        ans1 += cnt1;
        ans2 += cnt2;
    }
    cout << ans2 << " " << ans1;
    return 0;
}
