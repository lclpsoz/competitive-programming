#include "bits/stdc++.h"
using namespace std;

// -------------------------------
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int) (((x%m) + m)%m);
}

// ------

int main () {
	string s;
	char op;
	cin >> op >> s;
	
	if(op == 'E')
	{
		string ans;
		for(int i = 0, j = 1; i < len(s); i = j)
		{
			j = i + 1;
			while(s[i] == s[j]) j++;
			
			int sz = j - i;
			
			ans.push_back(s[i]);
			ans.push_back('0' + sz);
		}
		
		cout << ans << endl;
	}	
	else
	{
		string ans;
		for(int i = 0; i < len(s); i+=2)
		{
			int sz = s[i + 1] - '0';
			
			ans += string(sz, s[i]);
		}
		
		cout << ans << endl;
	}
	
	return 0;
}