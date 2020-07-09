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

const int N = 2e5 + 10;

int n;
string s;

int main () {
	cin.tie (0);
	ios_base::sync_with_stdio (false);
	cin >> n;
	cin >> s;
	int now = 1, i = 0;
	
	if(s[0] == 'R')
		cout << now++ << endl;
	else
	{
		int cnt = 0;
		int k = i;
		while(k < n - 1 && s[k] == 'L')
			k++, cnt++;
		
		for(int j = now + cnt; j >= now; j--)
			cout << j << endl;
			
		now += cnt + 1;
		i = k;
	}
	
	for(; i < n - 1; i++)
	{
		if(s[i] == 'R')
		{
			int cnt = 0;
			int k = i + 1;
			while(k < n - 1 && s[k] == 'L')
				k++, cnt++;
			
			for(int j = now + cnt; j >= now; j--)
				cout << j << endl;
			
			now += cnt + 1;
			i = k - 1;
		}
		else
		{
			int cnt = 0;
			int k = i + 1;
			while(k < n - 1 && s[k] == 'L')
				k++, cnt++;
			
			for(int j = now + cnt; j >= now; j--)
				cout << j << endl;
			
			now += cnt + 1;			
			i = k - 1;
		}
	}
	
		
	return 0;
}