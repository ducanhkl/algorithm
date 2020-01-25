#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000006

using namespace std;

string s, a, b;
int xuly(string x)
{
    int dem = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] != x[i] && s[i] == 'r')
        dem ++;
    return dem;
}
int xuly1(string x)
{
    int dem = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] != x[i] && s[i] == 'b')
        dem ++;
    return dem;
}
int main()
{
    freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> s;
	a = s;
	b = s;
	for (int i = 0; i < s.length(); i++)
        if (i % 2 ==0)
          a[i] = 'r', b[i] = 'b';
        else a[i] = 'b', b[i] = 'r';
    cout << a << " " << b << endl;
    int dem1 = min(xuly(a), xuly1(a)) + abs(xuly(a)-xuly1(a))/2;
    int dem2 = min(xuly(b), xuly1(b)) + abs(xuly(b)-xuly1(b))/2;
    cout << min(dem1, dem2);
}
