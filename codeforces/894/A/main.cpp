#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

string s, h = "QAQ";
int dem = 0;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> s;
	for (int i = 0; i < s.length(); i++)
        for (int j = i+1; j < s.length(); j++)
            for (int k = j+1; k < s.length(); k++)
    {
        string m;
        m = m+s[i];
        m = m+s[j];
        m = m+s[k];
        if (m == h)
            dem ++;
    }
    cout << dem;
	return 0;
}
