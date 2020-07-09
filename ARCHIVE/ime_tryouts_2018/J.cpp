#include <bits/stdc++.h>
using namespace std;

// ------------
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
	return (int)(((x%m) + m)%m);
}

// ------------

const int N = 1e6 + 10;
int bit[N];

void add(int p, int v)
{
	for(int i = p; i < N; i += i & -i)
	{
		bit[i] += v;
	}
}

int sum(int x)
{
	int ans = 0;
	for(int i = x; i; i -= i & -i)
	{
		ans += bit[i];
	}
	return ans;
}

int sum(int x, int y)
{
	return sum(y) - sum(x - 1);
}

int main () {
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x; x++;
		
		int ans = n - (sum(N - 1) - sum(x - 1));
		cout << ans << endl;
		add(x, 1);
		//cout << "sum: " << sum(x + 1) << endl;
	}
	return 0;
}