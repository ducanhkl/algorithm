#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n, p;
int a[maxn];
map <int, int> dd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> p;
    for (int i = 1;  i <= n; i++)
        cin >> a[i];
    sort (a+1, a+n+1);
    int minn = 1;
    for (int i = 1; i <= n;i ++)
    {
        minn = max(minn, a[i] - i + 1);
    }
    for (int i = p; i <= n; i++)
    {
        int x = (a[i] - i)%p+p;
        x %= p;
        dd[x] = 1;
    }
    vector <int> ans;
    for (int i = minn; i < a[p]; i++)
    {
        if (dd[i%p] == 0)
        {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (auto v : ans)
    {
        cout << v << " ";
    }
    return 0;
}
