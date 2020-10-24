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

const int N = 1e4 + 10;

map<string, int> mp;
int avail = 0;
int room[N];

// 0: sudoeste
// 1: norte
// 2: sudeste
// 3: center

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		string s, now;
		cin >> s >> now;
		
		if(!mp.count(s)) {
			mp[s] = avail++;
			room[avail-1] = 0;
		}
		int id_player = mp[s];

		int sensor = 0;
		if(now == "norte") sensor = 1;
		else if(now == "sudeste") sensor = 2;

		// cout << "s = " << s << ", room = " << room[id_player] << ", sensor = " << sensor << '\n';
		if(room[id_player] != -1) {
			if(room[id_player] != 3 and sensor != room[id_player]) {
				room[id_player] = -1;
				cout << s << '\n';
			} else if(room[id_player] == 3)
				room[id_player] = sensor;
			else
				room[id_player] = 3;
		}
	}

	return 0;
}
