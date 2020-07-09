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
	int l, w;
	cin >> l >> w;
	
	vector<ll> grid(l, 0LL);
	vector<int> speed(l), dist(l);
	
	for(int i = 0; i < l; i++)
	{
		int s;
		cin >> s >> dist[i] >> speed[i];
		
		if(i % 2 == 0)
			s = w - s - 1;
		
		for(int j = s; j < 63; j += dist[i])
			grid[i] |= 1LL << j;//, cout << bitset<63>(grid[i]).to_string() << endl;
		for(int j = s; j >= 0; j -= dist[i])
			grid[i] |= 1LL << j;//, cout << bitset<63>(grid[i]).to_string() << endl;
	}
	
	string path;
	int p; cin >> p >> path;
	
	auto update = [&]()
	{
		for(int lane = 0; lane < l; lane++)
		{
			ll aux = grid[lane];
			
			if(speed[lane] == 0) continue;
			
			if(lane % 2)
			{
				aux <<= speed[lane];
				int xx = __builtin_ctzll(aux);
				for(int j = xx; j >= 0; j -= dist[lane])
					aux |= 1LL << j;
			}
			else
			{
				aux >>= speed[lane];
				int xx = 63 - __builtin_clzll(aux);
				for(int j = xx; j < 63; j += dist[lane])
					aux |= 1LL << j;
			}
			
			grid[lane] = aux;
		}
	};
	
	p = w - p - 1;
	int now = l, b = 1;

	for(char c : path)
	{
		if(c == 'U')
			now--, b ^= 1;
		else if(c == 'D')
			now++, b ^= 1;
		else if(c == 'L')
			p--;
		else
			p++;
		
		if(p < 0) p = 0;
		if(now < 0) now = -1;
		
		if(p >= w) p = w - 1;
		if(now > l) now = l;
		
		update();
		
		int paux = p;
		
		if(now >= l || now < 0) continue;
		
		if(b)
		{
			for(int i = p + 1; i < w; i++)
			{
				if(grid[now] && (1LL << i))
				{
					paux = i;
					break;
				}
			}
			
			int lft = paux + speed[now];
			int rgh = paux + 1;
			
			if(grid[now] & (1LL << p))
			{
				cout << "squish" << endl;
				return 0;
			}
			
			if(speed[now] && (p >= lft && p <= rgh))
			{
				cout << "squish" << endl;
				return 0;
			}
		}
		else
		{
			for(int i = p - 1; i >= 0; i--)
			{
				if(grid[now] && (1LL << i))
				{
					paux = i;
					break;
				}
			}
			
			int rgh = paux - speed[now];
			int lft = paux - 1;
			
			if(grid[now] & (1LL << p))
			{
				cout << "squish" << endl;
				return 0;
			}
			
			if(speed[now] && (p <= lft && p >= rgh))
			{
				cout << "squish" << endl;
				return 0;
			}
		}
	}
	
	if(now < 0)
		cout << "safe" << endl;
	else
		cout << "squish" << endl;		
		
	return 0;
}