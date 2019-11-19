#include <bits/stdc++.h>

using namespace std;

typedef pair <long long, int> point;
vector <point> v;
int n, ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        point t;
        cin >> t.first;
        t.second = 1;
        v.push_back(t);
    }
    for (int i = 1; i <= n; i++)
    {
        point t;
        cin >> t.first;
        t.second = 2;
        v.push_back(t);
    }
    sort (v.begin(), v.end());
    for (int i = 0; i < v.size()-1; i++)
        if (v[i].second != v[i+1].second)
            ans ++, i++;
    cout << ans;
    return 0;
}
