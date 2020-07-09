#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const ll MOD = 1'000'000'000'000LL;
inline ll mod (ll x, ll m = MOD) {
	return (((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e6+100;

string str;
// unordered_map<ll, vector<int>> mp;

int eval (int x) {
	int aux = 5;
	int r = 0;
	while (aux <= x) {
		r += x/aux;
		aux *= 5;
	}
	
	return r;
}

int binSearch (int qnt) {
	int l = 1, r = 1'000'000;
	while (l < r) {
		int md = (l+r)/2;
		if (eval (md) > qnt)
			r = md-1;
		else if (eval (md) == qnt)
			return md;
		else
			l = md;
	}
	
	return l;
}

int main () {
// 	ll fat = 1;
// 	for (int i = 1; i < N; i++) {
// 		fat *= i;
// 		while (fat%10 == 0) fat /= 10;
// 		fat = mod (fat);
// 		mp[fat].push_back (i);
// 	}
// 	for (auto p : mp)
// 		if (len (p.y) > 1) {
// 			bool dif = false;;
// 			for (int i = 1; i < len (p.y); i++)
// 				if (p.y[i]/5 == p.y[i-1]/5) {
// 					dif = true;
// 					break;
// 				}
// 			if (dif) {
// 				printf ("%lld: ", p.x);
// 				for (int u : p.y)
// 					printf ("%d ", u);
// 				putchar ('\n');
// 			}
// 		}
				

	cin >> str;
	ll val = 0;
	int qntZ = 0, zero = true;
	ll ax = 1;
	for (int i = len (str)-1, j = 0; i >= 0 and j < 16; i--) {
		if (zero and str[i] == '0')
			++qntZ;
		else {
			zero = false; 
			val += (str[i]-'0')*ax;
			++j;
			ax *= 10;
		}
	}
	val = mod (val);
	
	ll fat = 1;
	int st = (binSearch (qntZ)/5)*5;
	if (st == 0)
		++st;
	for (int i = 1; i < st; i++) {
		fat = fat*1ll*i;
		while (fat%10 == 0) fat /= 10ll;
		fat = mod (fat);
	}
	for (int i = st; i < st+5; i++) {
		fat = i*1ll*fat;
		while (fat%10 == 0) fat /= 10ll;
		fat = mod (fat);
		if (fat%1'000'000 == val%1'000'000) {
			printf ("%d\n", i);
 			return 0;
		}
	}
	assert (false);
	

	return 0;
}
