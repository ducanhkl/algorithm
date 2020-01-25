#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

ll x;
int t;

int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> t;
    while (t--)
    {
        cin >> x;
        int t1 = x/500;
        x %= 500;
        int t2 = x/200;
        x %= 200;
        int t3 = x/100;
        x %= 100;
        int t4 = x/50;
        x %= 50;
        int t5 = x/20;
        x %= 20;
        int t8 = x/10;
        x %= 10;
        int t6 = x/5;
        x %=  5;
        int t7 = x/2;
        x %= 2;
        cout << t1 + t2 + t3+ t4+t5+t6+t7+x+t8 << endl;
    }
	return 0;
}
