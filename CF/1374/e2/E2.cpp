#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

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

const int N = 2e5 + 10;

int typ[N];

void no() {
	cout << "-1\n";
	exit(0);
}

const int BOTH = 2;
const int LFT = -1;
const int RIG = 1;
const int ZERO = 0;
const int BOTH_LFT_RIG = -3;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, m, k;
	cin >> n >> m >> k;
	int _v1, _v2;
	_v1 = _v2 = 0;
	vpii both, lft, rig, zero; // 2, -1, 1, 0
	for(int i = 1; i <= n; i++) {
		int v, x, y;
		cin >> v >> x >> y;
		_v1 += x, _v2 += y;
		if(x and y) {
			both.push_back({v, i});
			typ[i] = BOTH;
		}
		else if(x)
			lft.push_back({v, i}), typ[i] = LFT;
		else if(y)
			rig.push_back({v, i}), typ[i] = RIG;
		else
			zero.push_back({v, i}), typ[i] = ZERO;
	}
	sort(ALL(both));
	sort(ALL(lft));
	sort(ALL(rig));
	sort(ALL(zero));
	if(_v1 < k or _v2 < k)
		no();
	else {
		int k_lft = 0, k_rig = 0;
		int p_both = 0, p_lft = 0, p_rig = 0, p_zero = 0;
		set<int> ans_idx;
		ll ans_val = 0;
		while(p_both < LEN(both) and k_lft < k) {
			k_lft++;
			ans_val += both[p_both].x;
			ans_idx.insert(both[p_both++].y);
		}
		k_rig = k_lft;
		while(p_lft < LEN(lft) and k_lft < k) {
			k_lft++;
			ans_val += lft[p_lft].x;
			ans_idx.insert(lft[p_lft++].y);
		}
		while(p_rig < LEN(rig) and k_rig < k) {
			k_rig++;
			ans_val += rig[p_rig].x;
			ans_idx.insert(rig[p_rig++].y);
		}

		if(k_rig < k or k_lft < k or LEN(ans_idx) > m)
			no();
		else {
			set<pii> opt;
			while(LEN(ans_idx) < m) {
				opt.clear();
				if(p_both < LEN(both))
					opt.insert(both[p_both]);
				if(p_zero < LEN(zero))
					opt.insert(zero[p_zero]);
				if(p_lft < LEN(lft))
					opt.insert(lft[p_lft]);
				if(p_rig < LEN(rig))
					opt.insert(rig[p_rig]);
	
				if(p_both and p_lft < LEN(lft) and p_rig < LEN(rig))
					opt.insert({lft[p_lft].x+rig[p_rig].x-both[p_both-1].x, BOTH_LFT_RIG});

				pii p = *opt.begin();
				if(p.y >= 0) {
					ans_idx.insert(p.y);
					ans_val += p.x;
					if(typ[p.y] == BOTH) {
						p_both++;
					}
					else if(typ[p.y] == LFT) {
						p_lft++;
					}
					else if(typ[p.y] == RIG) {
						p_rig++;
					}
					else if(typ[p.y] == ZERO) {
						p_zero++;
					}
				}
				else if(p.y == BOTH_LFT_RIG) {
					p_both--;
					ans_idx.erase(both[p_both].y);
					ans_val -= both[p_both].x;
					ans_idx.insert(lft[p_lft].y);
					ans_val += lft[p_lft++].x;
					ans_idx.insert(rig[p_rig].y);
					ans_val += rig[p_rig++].x;
				}
			}
			cout << ans_val << '\n';
			for(int v : ans_idx)
				cout << v << ' ';
			cout << '\n';
		}
	}

	return 0;
}
