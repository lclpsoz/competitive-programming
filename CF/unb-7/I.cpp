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
inline int cmp(ld x, ld y = 0, ld tol = EPS)
{
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD)
{
	return (int)(((x % m) + m) % m);
}

////////////////////////// Solution starts below. //////////////////////////////

int n, m;
int ideal[110];
vector<pii> vec;

int getS()
{
	int h, mi, s;
	scanf("%d:%d:%d ", &h, &mi, &s);
	return h * 3600 + mi * 60 + s;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		ideal[i] = getS();

	for (int i = 1; i <= m; i++) {
		int now = 0;
		for (int i = 0; i < n; i++) {
			int dif = ideal[i] - getS();
			if (dif < 0)
				now += -dif;
			else if (dif > 0)
				now += 2*dif;
		}
		vec.push_back ({now, i});
	}
	sort (vec.begin(), vec.end());
	printf ("Equipe vencedora: %d\n", vec.begin()->y);
	printf ("Penalidade: %d ponto(s)\n", vec.begin()->x);

	return 0;
}