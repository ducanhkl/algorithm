#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 100005

using namespace std;

vector <int> v;
int dd[maxn*2], d[2*maxn];

void init()
{
    for (int i = 2; i <= maxn; i++) if (!dd[i])
        for (int j = 2*i; j <= maxn; j += i) dd[j] = 1;
    for (int i = 2; i <= maxn; i++)
        if (!dd[i])
            v.push_back(i);
}
int main()
{
    int n;
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	init();
	for (int i = 0; i < v.size(); i++)
    {
        int t = v[i];
        d[t] ++;
        for (int j = i+1; j < v.size() && t < maxn; j++)
            d[t+v[j]] ++, t += v[j];
    }
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cout << d[x] << endl;
    }
	return 0;
}
