#include <bits/stdc++.h>
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

const int MOD = 1e6 + 3;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

using TM = ld;
using row = vector<TM>; // Values are int!!
using matrix = vector<row>;

matrix initMatrix (int nRow, int nCol) {
	matrix ret (nRow, row(nCol));

	return ret;
}

const int INF = 2;

ld powMod (ld base, int p) {
	ld ret = 1;
	while (p) {
		if (p&1) ret = fmod ((ret * base), MOD);
		p >>= 1;
		base = fmod(base * base, MOD);
	}

	return ret;
}

int gauss (vector < vector<ld> > a, vector<ld> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                ld c = fmod (a[i][col] * powMod (a[row][col], MOD-2), MOD);
                for (int j=col; j<=m; ++j)
                    // a[i][j] -= a[row][j] * c;
					a[i][j] = fmod (a[i][j] - a[row][j]*c, MOD);
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = fmod (a[where[i]][m] * powMod (a[where[i]][i], MOD-2), MOD);
    for (int i=0; i<n; ++i) {
        ld sum = 0;
        for (int j=0; j<m; ++j)
            // sum += ans[j] * a[i][j];
			sum = fmod (sum + ans[j] * a[i][j], MOD);
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}

int main () {
	vector<ld> ans(12);
	matrix a = initMatrix (12, 12);
	a[0][0] = 1;
	for (int i = 1; i < 12; i++) {
		a[i][0] = 1;
		for (int j = 1; j < 11; j++)
			a[i][j] = fmod (a[i][j-1]*i, MOD);
	}

	for (int x = 0; x < 12; x++) {
		cout << "? " << x << '\n';
		cout << flush;
		cin >> a[x][11];
		if (a[x][11] == 0) {
			cout << "! " << x << '\n';
			cout << flush;
			exit (0);
		}
	}

	gauss (a, ans);
	vector<int> ansInt(11);
	for (int i = 0; i < 11; i++)
		ansInt[i] = (int) round (fmod (fmod (ans[i], MOD) + MOD, MOD));
		
	for (int x = 0; x < MOD; x++) {
		int now = ansInt[0];
		int xx = x;
		for (int i = 1; i < 11; i++) {
			now = (now + xx*1ll*ansInt[i])%MOD;
			xx = (xx*1ll*x)%MOD;
		}
		if (now == 0) {
			cout << "! " << x << '\n';
			cout << flush;
			exit (0);
		}
	}
	cout << "! -1\n";
	cout << flush << '\n';

	
	return 0;
}
