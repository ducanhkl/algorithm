#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5+100;
int n;
char s[maxn], t[maxn];
vector <pair <int, int> > ans;
stack <int> st1, st2;


int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == t[i])
            continue;
        if (s[i] == 'a' && t[i] == 'b')
            st1.push(i);
        if (s[i] == 'b' && t[i]  == 'a')
            st2.push(i);
    }
    if (((st1.size()%2 == 0) ^ st2.size()%2 == 0) && st1.size() != st2.size())
        return cout << -1, 0;
    while (st1.size()>=2)
    {
        int pos1 = st1.top();
        st1.pop();
        int pos2 = st1.top();
        st1.pop();
        ans.push_back({pos1, pos2});
    }
    while (st2.size()>=2)
    {
        int pos1 = st2.top();
        st2.pop();
        int pos2 = st2.top();
        st2.pop();
        ans.push_back({pos1, pos2});
    }

    if (st1.size())
    {
        int pos1 = st1.top();
        int pos2 = st2.top();
        ans.push_back({pos1, pos1});
        ans.push_back({pos1, pos2});
    }
    cout << ans.size() <<endl;
    for (auto &x : ans)
        cout << x.first << " " << x.second << endl;
    return 0;
}
