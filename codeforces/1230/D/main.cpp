#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000;
long long a[maxn], b[maxn], ans = 0;
map <long long, int> m;
vector <long long> s;
int n;

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (m[a[i]] == 1)
            s.push_back(a[i]);
        m[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        for (auto x : s)
            if ((a[i]&x)==a[i])
        {
            ans += b[i];
            break;
        }
    }
    cout << ans;
    return 0;
}
