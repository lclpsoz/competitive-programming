#include<bits/stdc++.h>
using namespace std;

// ----------------
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

// ----------------

const int M = 400015;
int p[M], sz[M];

map<string, int> mp;

int findSet(int i)
{
	return (p[i] == i ? i : p[i] = findSet(p[i]));
}

void join(int i, int j)
{
	int x = findSet(i);
	int y = findSet(j);
	
	if(x != y)
	{
		if(sz[x] > sz[y])
		{
			sz[x] += sz[y];
			p[y] = x;
		}
		else
		{
			sz[y] += sz[x];
			p[x] = y;
		}
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	
	int m; cin >> m;
	
	for(int i = 0; i < 2*m + 1; i++)
		p[i] = i, sz[i] = 1;
	
	int i = 0;
	while(m--)
	{
		string a, b;
		cin >> a >> b;
		
		
		if(!mp.count(a)) mp[a] = i++;
		if(!mp.count(b)) mp[b] = i++;
		
		//cout << a << ' ' << findSet(mp[a]) << " -> ";
		//cout << b << ' ' << findSet(mp[b]) << endl;
		
		join(mp[a], mp[b]);
	}
	
	int q; cin >> q;
	
	while(q--)
	{
		string a; cin >> a;
// 		cout << sz[findSet(mp[a])] << ": ";
		cout << (sz[findSet(mp[a])] % 2 ? 'N' : 'S') << endl;
	}
	return 0;
}
