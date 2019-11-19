#include <bits/stdc++.h>

using namespace std;


const int maxn = 100;
int n;
char s[maxn], t[maxn];
int v[maxn];
int cnt = 0;
vector <pair <int, int> > ans;

void solve()
{
    ans.resize(0);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == t[i])
            continue;
        for (int j = i+1; j <= n; j ++)
        {
            if (s[i] == s[j]  && s[j] != t[j])
            {
                swap(s[j], t[i]);
                ans.push_back({j, i});
                break;
            }
        }
        if (s[i] == t[i])
            continue;
        for (int j = i+1; j <= n; j++)
        {
            if (s[i] == t[j] && t[i] == s[j] && s[j] != t[j] )
            {
                swap(s[j], t[j]);
                swap(s[j], t[i]);
                ans.push_back({j, j});
                ans.push_back({j, i});
                break;
            }
        }
        if (s[i] == t[i])
            continue;
        for (int j = i+1; j <= n; j++)
        {
            if (s[i] == t[j] && t[i] != s[j] && s[j] != t[j] )
            {
                swap(s[j], t[j]);
                swap(s[j], t[i]);
                ans.push_back({j, j});
                ans.push_back({j, i});
                break;
            }
        }
    }
    if (ans.size() > 2*n)
    {
        cout << "No" << endl;
        return ;
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[i] !=  t[i])
        {
            cout << "No" << endl;
            return ;
        }
    }
    cout << "Yes" << endl;
    cout << ans.size() << endl;
    for (auto pi : ans)
    {
        cout << pi.first << " " << pi.second << endl;
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    int test;
    cin >> test;
    int nt = test, dem = 0;;
    while (test--)
    {
        dem ++;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> s[i];
        for (int i = 1; i <= n; i++)
            cin >> t[i];
//         if (dem == 99)
//        {
//            for (int i = 1; i <= n; i++)
//            {
//                cout << s[i];
//            }
//            cout << endl;
//            for (int i = 1; i <= n; i++)
//            {
//                cout << t[i];
//            }
//            return 0;
//        }
        cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] != t[i])
            {
                v[++cnt] = i;
            }
        }
        solve();
    }
    return 0;
}
