#include<iostream>
using namespace std;

long long n, m, c;
string s;

int main() {

    cin >> n >> m >> s;
    m--;
	int p = 0;
	for(int i = 1; i < n; i++) {
		if(s[i] == s[i-1]) c += n * m, p = i;
		else if(s[i] != s[i-2]) p = i - 1;
		c += i - p;
	}
	cout << n*n*m - c;
	return 0;
}
