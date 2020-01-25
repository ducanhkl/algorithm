#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;

map <string, vi> ma;
set <string> a;
int mid = 0;
long long ans = 0;
int k, n;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> k >> n;
    for (int i = 1; i <= k; i++)
    {
        string s;
        int val;
        cin >> s >> val;
        a.insert(s);
        ma[s].push_back(val);
    }
    for (auto s : a)
    {
        string z;
        z = s;
        reverse(z.begin(), z.end());
        if (z < s)
            continue;
        if (s == z)
        {
            vi &v = ma[s];
            sort(v.begin(), v.end(), greater<int>());
            int i;
            for (i = 0; i < v.size()-1; i += 2)
            {
                if (v[i] + v[i+1] >= 0)
                {
                    ans += v[i] + v[i+1];
                    mid = max(mid, -v[i+1]);
                }
                else
                {
                    break;
                }
            }
            if (i < v.size())
            {
                mid = max(mid, v[i]);
            }
            continue;
        }
        vector <int> &v1 =ma[s], &v2 = ma[z];
        sort(v1.begin(), v1.end(), greater<int>());
        sort(v2.begin(), v2.end(), greater<int>());
        for (int i = 0; i < v1.size() && i < v2.size(); i++)
        {
            if (v1[i] + v2[i] > 0)
            {
                ans += v1[i] + v2[i];
            }
        }
    }
    cout << ans+mid;
    return 0;
}
