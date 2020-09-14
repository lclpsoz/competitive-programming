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

const int N = 1e5 + 10;

int n, a, b, c;
int val[4];
int ch[4];
string vv[] = {"AB", "AC", "BC"};
vector<int> pos[3];
char ans[N];

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	cin >> n >> val[0] >> val[1] >> val[2];
	string s;
	for(int i = 1; i <= n; i++) {
		cin >> s;
		if(s == "AB") {
			pos[0].push_back(i);
			if(val[0] +val[1] == 0) {
				cout << "No\n";
				exit(0);
			}
		}
		else if(s == "AC") {
			pos[1].push_back(i);
			if(val[0] +val[2] == 0) {
				cout << "No\n";
				exit(0);
			}
		}
		else {
			pos[2].push_back(i);

			if(val[1] +val[2] == 0) {
				cout << "No\n";
				exit(0);
			}
		}
	}
	for(int i = 0; i < 3; i++) {
		while(LEN(pos[i]) > 4) {
			ans[pos[i].back()] = vv[i][0]; pos[i].pop_back();
			ans[pos[i].back()] = vv[i][1]; pos[i].pop_back();
		}
	}

	vector<pii> ax;
	for(int i = 0; i < 3; i++)
		for(auto p : pos[i])
			ax.push_back({i, p});

	for(int i = 0; i < (1<<(LEN(ax))); i++) {
		for(int j = 0; j < 3; j++)
			ch[j] = val[j];
		for(int j = 0; j < LEN(ax); j++) {
			bool yes = i&(1<<j);
			if(ax[j].x == 0) {
				if(yes)
					ch[0]--, ch[1]++;
				else 
					ch[0]++, ch[1]--;
			} else if(ax[j].x == 1) {
				if(yes) ch[0]--, ch[2]++;
				else ch[0]++, ch[2]--;
			} else {
				if(yes) ch[1]--, ch[2]++;
				else ch[1]++, ch[2]--;
			}
		}
		if(ch[0] >= 0 and ch[1] >= 0 and ch[2] >= 0) {

			for(int j = 0; j < LEN(ax); j++) {
				if(i&(1<<j))
					ans[ax[j].y] = vv[ax[j].x][1];
				else
					ans[ax[j].y] = vv[ax[j].x][0];
			}
			cout << "Yes\n";
			for(int i = 1; i <= n; i++) cout << ans[i] << '\n';
			exit(0);
		}
	}
	cout << "No\n";
	return 0;
}
