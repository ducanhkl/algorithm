#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 3005
using namespace std;

string s;
int dem = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> s;
	for (int i = 0; i<s.length(); i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') dem = 0;
            else
            {
                dem ++;
                if (dem > 2 && (s[i] != s[i-1] || s[i] != s[i-2]))
                    cout << " " ,dem = 1;
            }
            cout << s[i];
        }
	return 0;
}
