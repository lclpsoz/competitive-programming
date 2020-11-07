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

int dijkstra(vpii vc, vector<bool> t, vector<bool> h)
{
	if(!h[0]) return -1;

	set<pair<int, vpii>> pq;
	map<vpii, int> mp;

	mp[vc] = 0;
	pq.insert({mp[vc], vc});

	while(!empty(pq))
	{
		auto [d, v] = *pq.begin();
		pq.erase(pq.begin());

		if(d != mp[v]) continue;

		if(v[0].second + 1 == 5)
			return d + 2;

		if(d == 8) continue;

		vector<vi> board(6, vi(6, 0));

		for(int c = 1; c <= 10; c++)
		{
			auto& [row, col] = v[c - 1];
			if(row == -1) continue;
			if(h[c - 1])
			{
				board[row][col] = board[row][col + 1] = c;
				if(t[c - 1]) board[row][col + 2] = c;
			}	
			else
			{
				board[row][col] = board[row + 1][col] = c;
				if(t[c - 1]) board[row + 2][col] = c;
			}
		}

		// for(int i = 0; i < 6; i++)
		// 	for(int j = 0; j < 6; j++)
		// 		cout << board[i][j] << " \n"[j == 5];
		// cout << "====================   " << d << endl;

		for(int c = 1; c <= 10; c++)
		{
			auto& [row, col] = v[c - 1];
			if(row == -1) continue;
		
			if(h[c - 1])
			{
				if(col && !board[row][col - 1])
				{
					v[c - 1].second--;
					if(!mp.count(v) || mp[v] > d + 1)
					{
						mp[v] = d + 1;
						pq.insert({d + 1, v});
					}
					v[c - 1].second++;
				}
				if(col + 2 + t[c - 1] < 6 && !board[row][col + 2 + t[c - 1]])
				{
					v[c - 1].second++;
					if(!mp.count(v) || mp[v] > d + 1)
					{
						mp[v] = d + 1;
						pq.insert({d + 1, v});
					}
					v[c - 1].second--;
				}
			}
			else
			{
				if(row && !board[row - 1][col])
				{
					v[c - 1].first--;
					if(!mp.count(v) || mp[v] > d + 1)
					{
						mp[v] = d + 1;
						pq.insert({d + 1, v});
					}
					v[c - 1].first++;
				}
				if(row + 2 + t[c - 1] < 6 && !board[row + 2 + t[c - 1]][col])
				{
					v[c - 1].first++;
					if(!mp.count(v) || mp[v] > d + 1)
					{
						mp[v] = d + 1;
						pq.insert({d + 1, v});
					}
					v[c - 1].first--;
				}
			}
		}

	}

	return -1;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	vector<vi> board(6, vi(6, 0));

	for(int i = 0; i < 6; i++)
		for(int j = 0; j < 6; j++)
			cin >> board[i][j];

	vpii v(10, pii(-1, -1));
	vector<bool> h(10, false), t(10, false);
	for(int c = 1; c <= 10; c++)
	{
		bool found = false;
		for(int i = 0; i < 6 && !found; i++)
			for(int j = 0; j < 6 && !found; j++)
				if(board[i][j] == c)
				{
					v[c - 1] = {i, j};
					if(i + 1 < 6 && board[i + 1][j] == c)
					{
						if(i + 2 < 6 && board[i + 2][j] == c)
							t[c - 1] = 1;
					}
					else if(j + 1 < 6 && board[i][j + 1] == c)
					{
						h[c - 1] = 1;
						if(j + 2 < 6 && board[i][j + 2] == c)
							t[c - 1] = 1;
					}

					found = true;
				}
	}

	cout << dijkstra(v, t, h) << endl;
	
	return 0;
}

// 0 0 6 6 0 0
// 0 4 4 0 5 5
// 2 2 1 1 3 3
// 0 9 7 7 0 0
// 0 9 8 8 0 0
// 0 0 0 0 10 10