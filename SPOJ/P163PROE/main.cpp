#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000005

using namespace std;

int a = 0, b = 0, c = 0, d = 0;
string s;
int get(int x)
{
    return x*(x-1)/2;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> s;
	for (int i = 0; i < s.length(); i++)
        if (i%2)
            if (s[i] == 'a')
                a++;
            else b++;
        else
            if (s[i] == 'a')
                c++;
        else d++;
    cout << a*c+b*d << " " << get(a) + get(b) + get(c) + get(d) + a + b + c + d;
	return 0;
}
