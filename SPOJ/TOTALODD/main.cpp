#include <bits/stdc++.h>

using namespace std;

vector <int> v;

void init()
{
    v.assign({1, 3, 5, 7, 9});
    int last = 0;
    for (int i = 1; i <= 8; i++)
    {
        int sz = v.size();
        for (int j = last; j < sz; j++)
        {
            for (int k = 1; k <= 9; k += 2)
            {
                v.push_back(v[j]*10 + k);
                // cout << v.back() << " ";
            }
        }
        last = sz-1;
    }
    // cout << endl << v.size() << endl;
}

int main()
{
    //freopen("inp.txt",  "r", stdin);
    ios_base::sync_with_stdio(false);
    init();
    string s;
    while (cin >> s)
    {
        if (s == "[END]")
        {
            return 0;
        }
        int x;
        cin >> x;
        int res = v.back();
        res *= 2;
        int pos = lower_bound(v.begin(), v.end(), x) - v.begin();
        // cout << v[pos] << endl;
        for (int i = 0; i <= pos; i++)
        {
            while (pos > i && v[i] + v[pos-1] >= x)
            {
                res = min(v[i]+v[pos], res);
                pos --;
            }
            if (v[i] + v[pos] >= x)
            {
                res = min(res, v[i]+v[pos]);
            }
        }
        cout << res << endl;
    }
    return 0;
}
