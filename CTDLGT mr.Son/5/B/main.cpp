#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

main()
{
    ios_base::sync_with_stdio(false);
	queue<int> a; // khai bao hang doi;
	int q;
	cin >> q;
	int x;
	while( q-- )
	{

		string s;
		cin >> s;
		if( s == "PUSH" ){

			cin >> x; // nhap so de them vao hang doi;
			a.push(x);
		}
		if( s == "POP" )
		{
			if( !a.empty() )
				a.pop();
		}
		if( s == "PRINTFRONT" )
		{
			if( !a.empty() )
				cout << a.front() << endl;
			else cout << "NONE" << endl;
		}
	}
}
