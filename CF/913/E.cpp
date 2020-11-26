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

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int n;
map<string, vector<string>> mp;

string xyzStr[] = {"x", "y", "z", "!x", "!y", "!z"};
bitset<8> xyz[6] = {bitset<8>("00001111"),
					bitset<8>("00110011"),
					bitset<8>("01010101")};
vector<pair<string, bitset<8>>> XYZ[10];

void justNegate (int p) {
	int ax = len (XYZ[p]);
	for (int i = 0; i < ax; i++)
		XYZ[p].push_back ({"!(" + XYZ[p][i].x + ")", ~XYZ[p][i].y});
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < 3; i++)
		xyz[i+3] = ~xyz[i];
	
	// 0 -> OR
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			XYZ[0].push_back ({xyzStr[i] + "|" + xyzStr[j], xyz[i] | xyz[j]});
	justNegate (0);
	
	// 1 -> AND
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			XYZ[1].push_back ({xyzStr[i] + "&" + xyzStr[j], xyz[i] & xyz[j]});
	justNegate (1);
	
	// 2 -> 0 OR xyz + 1 OR xyz
	for (int i = 0; i < 6; i++) { 
		for (auto p : XYZ[0])
			XYZ[2].push_back ({p.x + "|" + xyzStr[i], xyz[i] | p.y});
		for (auto p : XYZ[1])
			XYZ[2].push_back ({p.x + "|" + xyzStr[i], xyz[i] | p.y});
	}
	justNegate (2);
	
	// 3 -> 0 AND xyz, + 1 AND xyz
	for (int i = 0; i < 6; i++) {
		for (auto p : XYZ[0]) {
			string s;
			if (p.x[0] == '!')
				s = p.x;
			else
				s = "(" + p.x + ")";
			XYZ[3].push_back ({s + "&" + xyzStr[i], p.y & xyz[i]});
		}
		for (auto p : XYZ[1])
			XYZ[3].push_back ({p.x + "&" + xyzStr[i], p.y & xyz[i]});
	}
	justNegate (3);
	
	
	
	set<long unsigned> st;
	for (int i = 0; i < 4; i++)
		for (auto p : XYZ[i])
			st.insert (p.y.to_ulong());
	for (int i = 0; i < 6; i++)
		st.insert (xyz[i].to_ulong());
	printf ("%d\n", len (st));
	
	
	
	return 0;
}
