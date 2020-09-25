#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string n; int x = 0, y = 0, l = 0, i = 0, c = 0;
	cin >> l >> x >> y;
	cin >> n;
	for (i = (l - x); i < (l - y - 1); ++i)
	{
		if (n[i] == '1')
		{
			++c;
			n[i] = '0';
		}
	}
	if (n[l - y - 1] == '0')
	{
		++c;
		n[l - y - 1] = '1';
	}
	for (i = (l - y); i < l; ++i)
	{
		if (n[i] == '1')
		{
			++c;
			n[i] = '0';
		}
	}
	cout << c << endl;
}
