#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7;


string x1;
string x2;

class hashString {
public:
	vector<long long> h[3];
	vector <long long> base = {123, 117 , 111};
	vector <long long> po[3];
	void set_string(string a)
	{
		for (int i = 0; i < base.size(); i++)
		{
			int len = a.length()+1;
			h[i].resize(len);
			h[i][0] = 0;
			po[i].resize(len);
			po[i][0] = 1;
			for (int j = 0; j < a.length(); j++)
			{
				po[i][j+1] = (po[i][j]*base[i])%mod;
				h[i][j+1] = (h[i][j]*base[i] + a[j])%mod;
			}
		}
	}
	vector <long long> get_hash(int l, int r)
	{
		vector <long long> result;
		for (int i = 0; i < base.size(); i++)
		{
			long long res = (h[i][r+1] -h[i][l]*po[i][r-l+1] + mod*mod)%mod;
			result.push_back(res);
		}
		return result;
	}
};

hashString h1, h2;

int check(int mid)
{
	if (mid == 4)
	{
		mid ++;
		mid --;
	}
	vector <long long> res1 = h1.get_hash(x1.length()-mid, x1.length()-1);
	vector <long long> res2 = h2.get_hash(0, mid-1);
	for (int i = 0; i < res1.size(); i++)
	{
		if (res2[i] != res1[i])
		{
			return false;
		}
	}
	return true;
}

int
main()
{
	//freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin >> x1 >> x2;
	h1.set_string(x1);
	h2.set_string(x2);
	int ans = 0;
	for (int i = 1; i <= min(x1.length(), x2.length()); i++)
	{
		if (check(i))
		{
			ans = i;
		}
	}
	// cout << ans << endl;
	cout << x1;
	for (int i = ans; i < x2.length(); i++)
	{
		cout << x2[i];
	}
	return 0;
}
