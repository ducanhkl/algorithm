#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

vector <int> x, y, ans;
ll res = 0,a, c;

int main()
{
    freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> a >> c;
	while (a != 0)
    {
        x.push_back(a%3);
        a = a/3;
    }
    while (c != 0)
    {
        y.push_back(c%3);
        c /= 3;
    }
    while (x.size() < y.size())
        x.push_back(0);
    while (y.size() < x.size())
        y.push_back(0);
    for (int i = y.size() - 1; i >= 0; i--)
    {
        if (y[i] < x[i])
        {
            ans.push_back(3+y[i] - x[i]);
            continue;
        }
        ans.push_back(y[i] - x[i]);
    }
    for (int i = ans.size()-1; i >= 0; i--)
        res += ans[i]*pow(3, ans.size()-1-i);
    cout << res;
	return 0;
}
