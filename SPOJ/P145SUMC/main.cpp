#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000004
using namespace std;

pii d[maxn];
int n, b, a;
vector <int> v;

int main()
{
    //freopen("inp.txt", "r", stdin);
    //freopen("out.txt","w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> a >> b >> n;
	if (a > b)
        swap(a, b);
	for (int i = 1;i <= n; i++)
        cin >> d[i].first >> d[i].second;
    int t = __gcd(a, b);
    for (int i = 1; i <= sqrt(t); i++)
        if (t%i == 0)
    {
        if (i*i == t)
        {
            v.push_back(i);
            continue;
        }
        v.push_back(i);
        v.push_back(t/i);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++)
    {
        int l = lower_bound(v.begin(), v.end(),d[i].first)-v.begin();
        int r = upper_bound(v.begin(), v.end(),d[i].second)-v.begin();
        int dem = 0;
        for (int j =r; j >= l; j--)
            if (v[j] >= d[i].first && v[j] <= d[i].second)
                {
                    cout << v[j] << " ";
                    dem ++;
                    break;
                }
        if (dem == 0)
            cout << -1;
        cout << endl;
    }
    return 0;
}
