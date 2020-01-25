#include<bits/stdc++.h>
#define ll long long

using namespace std;

long long n,l,a,pos = 0,ans = 0;
int main()
{
	cin >> n >> l >> a;
	for (int i = 0; i <= n-1; i++)
    {
	    int x,y;
	    cin >> x >> y;
	    ans+=(x-pos)/a;
	    pos = x+y;
	}
    if (pos < l) cout << ans + (l-pos)/a;
    else cout << ans << endl;
	return 0;
}
