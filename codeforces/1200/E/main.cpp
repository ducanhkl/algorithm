#include <bits/stdc++.h>

using namespace std;

const long long maxn = 1e6+100;
string ans, a[maxn];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ans = a[1];
    for (int i = 2; i <= n; i++)
    {
        int len = min((int)a[i].length(), min((int)ans.length(), 10)), j;
        for (j = min(ans.length(), a[i].length()); i >= 0; j --)\
        {
            cout << ans.substr(ans.length()-min(j, len)) << " " << a[i].substr(j-min(j, len), min(j, len)) << endl;
            if (ans.substr(ans.length()-min(j, len)) != a[i].substr(j-min(j, len), min(j, len)))
                {
                    continue;
                }
            if (ans.substr(ans.length()-j) == a[i].substr(0, j))
                {
                    break;
                }
        }
        ans += a[i].substr(j);
    }
    cout << ans;
}
