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

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const ld EPS = 1e-9;
const int MOD = 1;

inline int fcmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod (ll x, int m = MOD) {
	int ret = (int)x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n; cin >> n;
	map<int, vpii> mp;
	vi room;
	for(int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		mp[a].emplace_back(i, 1);
		room.emplace_back(a);
	}

	vpii team;
	for(int i = 1; i <= n; i++)
	{
		int l, r;
		cin >> l >> r;
		mp[l].emplace_back(i, 0);
		team.emplace_back(l, r);
	}

	auto inside = [&](int id_room, int id_team)
	{
		return room[id_room] >= team[id_team].first
			 && room[id_room] <= team[id_team].second;
	};

	bool bad = false, perfect = true;
	vi ans(n, 0), order;
	set<pii> st;
	int mx = 0;
	for(auto& [key, item] : mp)
	{
		if(!empty(st) && st.begin()->first < key)
		{
			bad = true;
			break;
		}

		for(auto [id, is_room] : item)
			if(!is_room) st.insert({team[id - 1].second, id});
		for(auto [id, is_room] : item)
		{
			if(is_room)
			{
				if(empty(st))
				{
					bad = true;
					break;
				}
				else
				{
					int id_team = st.begin()->second;
					ans[id_team - 1] = id;
					order.emplace_back(id_team);
					
					if(mx && inside(ans[mx - 1] - 1, id_team - 1) && inside(id - 1, mx - 1)) 
						perfect = false;

					if(!mx || team[mx - 1].second < st.begin()->first)
						mx = id_team;
					st.erase(st.begin());
				}
			}
		}

		if(bad) break;
	}	

	if(bad)
	{
		cout << "Let's search for another office." << endl;
		return 0;
	}

	if(!perfect)
	{
		cout << "Ask Shiftman for help." << endl;
		return 0;
	}

	// for(int i = 1; i < n; i++)
	// {
	// 	int a = order[i - 1];
	// 	int b = order[i];

	// 	int x = ans[a - 1];
	// 	int y = ans[b - 1];

	// 	if(inside(x - 1, b - 1) && inside(y - 1, a - 1))
	// 	{
	// 		cout << "Ask Shiftman for help." << endl;
	// 		return 0;
	// 	}
	// }

	cout << "Perfect!" << endl;
	for(int i = 0; i < n; i++)
		cout << ans[i] << " \n"[i == n - 1];

	return 0;
}
