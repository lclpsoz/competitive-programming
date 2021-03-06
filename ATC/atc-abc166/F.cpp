#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
using namespace std;
////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define LEN(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
using ll = long long;
using llu = long long unsigned;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

using pp = pair<int, pair<int, int>>;

const int N = 1e5 + 10;

int n;
int val[4];
int ch[4];
vector<int> pos[3];
pii inp[N][2];
char choice[N][2];
map<int, map<int, map<int, bool>>> mp;
int total = 0;
vector<char> ans;

bool solve(int p, int a, int b) {
	if(a+b > total or a < 0 or b < 0) return 0;
	if(p == n+1) return true;
	if(mp.count(p) and mp[p].count(a) and mp[p][a].count(b)) return mp[p][a][b];
	bool &ret = mp[p][a][b];
	pii *now = inp[p];
	return ret = solve(p+1, a+now[0].x, b+now[0].y) || solve(p+1, a+now[1].x, b+now[1].y);
}

bool recu(int p, int a, int b) {
	if(a+b > total or a < 0 or b < 0) return false;
	if(p == n+1) return true;
	if(mp.count(p) and mp[p].count(a) and mp[p][a].count(b) and mp[p][a][b]) {
		if(recu(p+1, a+inp[p][0].x, b+inp[p][0].y))
			ans.push_back(choice[p][0]);
		else {
			recu(p+1, a+inp[p][1].x, b+inp[p][1].y);
			ans.push_back(choice[p][1]);
		}
		return true;
	}
	return false;
}
int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
	int a, b, c;
	cin >> n >> a >> b >> c;
	string s;
	for(int i = 1; i <= n; i++) {
		cin >> s;
		if(s == "AB") {
			inp[i][0] = {+1, -1};
			inp[i][1] = {-1, +1};
			choice[i][0] = 'A';
			choice[i][1] = 'B';
		}
		else if(s == "AC") {
			inp[i][0] = {+1, 0};
			inp[i][1] = {-1, 0};
			choice[i][0] = 'A';
			choice[i][1] = 'C';
		}
		else if(s == "BC") {
			inp[i][0] = {0, +1};
			inp[i][1] = {0, -1};
			choice[i][0] = 'B';
			choice[i][1] = 'C';
		}
	}
	total += a + b + c;
	if(!solve(1, a, b))
		cout << "No\n";
	else {
		cout << "Yes\n";
		recu(1, a, b);
		reverse(ALL(ans));
		for(char c : ans)
			cout << c << '\n';
	}

	return 0;
}
