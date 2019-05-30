#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000006

using namespace std;

int n;
vector <int> a1, a2, b1, b2;

int main()
{
    freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (a > 0)
            a1.push_back(a);
        else a2.push_back(-a);
    }
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (a > 0)
            b1.push_back(a);
        else b2.push_back(-a);
    }
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    sort(b1.begin(), b1.end());
    sort(b2.begin(), b2.end());
    int pos = 0, ans = 0;
    for (int i = 0; i < a1.size() && pos < b2.size(); i++)
        {
            int h = pos;
            while (a1[i] < b2[pos] && pos < b2.size())
                pos ++;
            if (pos != h && pos < b2.size())
                ans ++;
            pos ++;
        }
    pos = 0;
    for (int i = 0; i < a2.size(); i++)
        {
            int h = pos;
            while (a2[i] > b1[pos] && pos < b1.size())
                pos ++;
            if (pos != h && pos < b1.size())
                ans ++;
            pos ++;
        }
    cout << ans;
	return 0;
}
