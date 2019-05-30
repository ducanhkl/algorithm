#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n;
int a[maxn], pos, res, temp, ans[maxn], arr[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    ans[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        int temp = 0;
        for (int j = 1; j <= i; j++)
            arr[j] = ans[j];
        ans[i] = a[i];
        ans[i+1] = ans[1];
        for (int j = 1; j <= i; j++)
            temp = max(abs(ans[j] - ans[j+1]), temp);
        int pos = i;
        for (int j = i-1; j >= 1; j--)
        {
            res = 0;
            swap(ans[j], ans[j+1]);
            ans[i+1] = ans[1];
            for (int k = 1; k <= i; k++)
                res = max(res, abs(ans[k]-ans[k+1]));
            if (res < temp)
            {
                temp = res;
                pos = j;
            }
        }
        for (int j = 1; j <= i; j++)
            ans[j] = arr[j];
        for (int j = i; j >= pos; j--)
            ans[j] = ans[j-1];
        ans[pos] = a[i];
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}
