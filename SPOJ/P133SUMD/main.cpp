#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000006
#define reset(a) memset(a, 0, sizeof(a))

using namespace std;

int n, p;
string s;
int h[10][3], dd[maxn];
struct data
{
    int x;
    int y;
    int d;
} a[maxn];
bool cmp(data x, data y)
{
    if (x.x == y.x)
        return x.y < y.y;
    bool k = x.x < y.x;
    return k;
}
bool check(data x, data y)
{
    return x.x == y.x && x.y == y.y && x.d == y.d;
}
int timkiem(data d)
{
    int l = 1, r = n, g;
    while (l < r)
    {
        g = (l+r)/2;
        if (check(a[g], d))
            return g;
        if (cmp(a[g], d))
            r = g-1;
        else l = g+1;
    }
    return -1;
}
int main()
{
    freopen("inp.txt", "r", stdin);
    reset(a), reset(dd);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> p;
	cin >> s;
	for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x;
        cin >> a[i].y;
    }
    int px = a[1].x, py = a[1].y;
    a[1].d = 1;
    h[0][1] = p, h[0][2] = p;
    h[1][1] = p, h[1][2] = -p;
    h[2][1] = -p, h[2][2] = p;
    h[3][1] = -p, h[3][2] = p;
    //cout << cmp(a[2], a[3]) << endl;
    sort(a+1, a+n+1, cmp);

    for (int i = 0; i < s.length(); i++)
        {
            data d;
            d.x = px + h[s[i] - 'A'][1];
            d.y = py + h[s[i] - 'A'][2];
            d.d = 0;
            int pos = timkiem(d);
            if (pos != -1)
            {
                px = d.x;
                py = d.y;
                a[i].d = 1;
            }
        }
    cout << px << " " << py;
	return 0;
}
