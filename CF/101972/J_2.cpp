#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

#define LEN(x) (int)x.size()
#define ALL(x) x.begin(), x.end()

using ll = long long;
using llu = long long unsigned;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vpii = vector<pii>;

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

inline int fcmp(double x, double y)
{ return (x < y + EPS ? (x < y - EPS ? -1 : 0) : 1);}

const int N = 1e3 + 10;

llu solve(llu node, llu target, llu parent, int pos, char befChar, char lstChar, int qntRL, int qntR) {
	const int ax = 6;
	llu msk = 1LLU<<(pos+1);
	if(lstChar != '-') {
		if(befChar == 'R' and lstChar == 'L') {
			qntRL += qntR;
			qntR = 0;
		} else if(lstChar == 'R')
			qntR++;

		if(lstChar == 'L') {
			for(int i = pos+2; i <= pos+qntRL+1; i++)
				msk ^= 1LLU<<i;
		}
	}
	if(node == target) return msk;
	llu nodeL = node ^ (1LLU<<pos);
	llu nodeR = nodeL ^ (1LLU<<(pos+1));
	if(target < node)
		return solve(nodeL, target, node, pos-1, lstChar, 'L', qntRL, qntR) + msk;
	return solve(nodeR, target,  node, pos-1, lstChar, 'R', qntRL, qntR) + msk;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t;
	cin >> t;
	while(t--) {
		llu n;
		cin >> n;
		if(n <= 1) cout << 0 << '\n';
		else
			for(int i = 0; i < 64; i++) {
				if ((1LLU<<(i+1))-1 == n) {
					cout << "0\n";
					break;
				}
				else if((1LLU<<i) <= n and (1LLU<<(i+1)) > n) {
					llu l = (1LLU<<i);
					llu r = (1LLU<<(i+1))-2;
					cout << solve((l+r)/2, n, (l+r)/2, i-2, '-', '-', 0, 0) << '\n';	
					break;
				}
			}
	}

	return 0;
}