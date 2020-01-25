#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 1000006
#define maxn 11
using namespace std;

vector <int> t, ans;
int a[maxn], n;

bool check(int x)
{
    t.clear();
    ans.clear();
    t.push_back(x);
    for (int i = 0; i < n - 1; i++)
        t.push_back(a[i] - x);
    for (int i = 0; i < t.size(); i++)
        for (int j = i + 1; j < t.size(); j++)
            ans.push_back(t[i]+t[j]);
    for (int i = 0; i < ans.size(); i++)
        if (a[i] != ans[i])
        return false;
    cout << 1 << " ";
    for (int i = 0; i < t.size(); i++)
        cout << t[i] << " ";
    cout << endl;
    return true;
}
int main()
{
    int t;
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> t;
	while (t--)
    {
        memset(a, 0, sizeof(a));
        cin >> n;
        for (int i = 0; i < n*(n-1)/2; i++)
            cin >> a[i];
        sort(a, a+n);
        bool kt = false;
        for (int i  = -maxnum; i <= maxnum; i++)
            if(check(i))
                {
                    kt = true;
                    break;
                }
        if (!kt)
            cout << -1 << endl;
    }
	return 0;
}
