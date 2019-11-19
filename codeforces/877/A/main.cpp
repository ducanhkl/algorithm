#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

string a[] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
string s;
int dem  = 0;
int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	getline(cin, s);
	for (int i = 0; i < 5; i++)
	    for (int j = 0; j <= s.length()-a[i].length(); j++)
            {
                int h = s.length()-a[i].length();
                if (h < 0)
                    break;
                int check = 1;
                for (int k = 0; k < min(a[i].length(), s.length()); k++)
                    if(a[i][k] != s[j+k])
                    {
                        check = 0;
                        break;
                    }
                    if (check)
                        dem ++;
            }
    if (dem == 1)
        cout << "Yes"; else
    cout << "No";
	return 0;
}
