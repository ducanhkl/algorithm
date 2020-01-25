#include<bits/stdc++.h>
#define FU(i,a,b) for(int i = a;i <= b;i++)
#define FD(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	int test;
	cin >> test;
	while (test--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if (a + c > b + d){
            cout << 1 << endl;
            continue;
        }
        if (a + c < b + d){
            cout << 2 << endl;
            continue;
        }
        if (c > b){
            cout << 1 << endl;
            continue;
        }
        if (b > c){
            cout << 2 << endl;
            continue;
        }
        cout << -1 << endl;
	}
	return 0;
}
