#include <bits/stdc++.h>

using namespace std;

const int maxn = 1024*512;

int n, x, dd[maxn];
vector <int> ans;



int main()
{
    memset(dd, 0, sizeof(dd));
    ios_base::sync_with_stdio(false);
    cin >> n >> x;
    dd[x] = 1;
    for (int i = 1; i < (1<<n); i++)
        if (dd[i] == 0)
        {
            dd[i] = 1;
            dd[x^i] = 1;
            ans.push_back(i);
        }
    cout << ans.size() << endl;
    if (ans.size())
        cout << ans[0] << " ";
    for (int i = 1; i < ans.size(); i++)
    {
        int val = ans[i]^ans[i-1];
        cout << val << " ";
    }
    return 0;
}
