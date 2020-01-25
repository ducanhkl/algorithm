#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair

using namespace std;

ll n;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    int t = n/10;
    if (n-t*10 > (t+1)*10-n)
        cout << (t+1)*10;
    else cout <<t*10;
    return 0;
}
