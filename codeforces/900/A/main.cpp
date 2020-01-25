#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair

using namespace std;

int t1 = 0, t2 = 0;
int n;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x; int y;
        cin >> x >> y;
        if (x > 0)
            t1 ++;
        else t2 ++;
    }
    if (t1 <= 1 || t2 <= 1)
        cout << "YES";
    else cout << "NO";
    return 0;
}
