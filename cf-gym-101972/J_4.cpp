#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

#define LEN(x) (int)x.size()
#define ALL(x) x.begin(), x.end()

using ll = long long;
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

int values[N];

int dp[N][N];
int calc(int i, int j)
{
	if(!i && !j) return 1;
	if(j < 0 || j > i) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	// cout << i << ' ' << j << '\n';
	return dp[i][j] = calc(i - 1, j - 1) + calc(i - 1, j);
}

void recu(int node, int parent, int pos, string s, int qntRL, int qntR) {
	if(pos < 0) return;
	const int ax = 6;
	// cout << "pos = " << node << ", value = " << values[node] << '\n';
	int dif = values[node]-values[parent];
	// cout << bitset<ax>(dif) << ' ' << dif << '\n';
	int msk = 1<<(pos+1);
	if(LEN(s)) {
		if(LEN(s) > 1 and s[LEN(s)-2] == 'R' and s[LEN(s)-1] == 'L') {
			qntRL += qntR;
			qntR = 0;
		} else if(s[LEN(s)-1] == 'R')
			qntR++;
		// cout << __builtin_popcount(dif) << '\n';
		
		if((s[LEN(s)-1] == 'L' and __builtin_popcount(dif) != qntRL+1) or (s[LEN(s)-1] == 'R' and __builtin_popcount(dif) != 1))
			cout << "NO!\n";

		if(s[LEN(s)-1] == 'L') {
			for(int i = pos+2; i <= pos+qntRL+1; i++)
				msk ^= 1<<i;
		}
	}
	for(int i = 0; i < ax-pos; i++)
		for(int j = 0; j < 3; j++) cout << ' ';
	cout << s << ' ' << bitset<ax>(dif) << ' ' << dif << ' ' << qntRL << ' ' << bitset<ax>(msk) << ' ' << (bitset<ax>(msk).to_string() != bitset<ax>(dif).to_string() )<< '\n';
	int nodeL = node ^ (1<<pos);
	int nodeR = nodeL ^ (1<<(pos+1));
	recu(nodeL, node, pos-1, s+"L", qntRL, qntR);
	recu(nodeR, node, pos-1, s+"R", qntRL, qntR);
}


ll solve(ll node, ll target, ll parent, int pos, string s, int qntRL, int qntR) {
	const int ax = 6;
	// cout << "pos = " << node << ", value = " << values[node] << '\n';
	int dif = values[node]-values[parent];
	// cout << bitset<ax>(dif) << ' ' << dif << '\n';
	ll msk = 1LL<<(pos+1);
	if(LEN(s)) {
		if(LEN(s) > 1 and s[LEN(s)-2] == 'R' and s[LEN(s)-1] == 'L') {
			qntRL += qntR;
			qntR = 0;
		} else if(s[LEN(s)-1] == 'R')
			qntR++;
		// cout << __builtin_popcount(dif) << '\n';
		
		// if((s[LEN(s)-1] == 'L' and __builtin_popcount(dif) != qntRL+1) or (s[LEN(s)-1] == 'R' and __builtin_popcount(dif) != 1))
		// 	cout << "NO!\n";

		if(s[LEN(s)-1] == 'L') {
			for(int i = pos+2; i <= pos+qntRL+1; i++)
				msk ^= 1<<i;
		}
	}
	if(node == target) return msk;
	// for(int i = 0; i < ax-pos; i++)
	// 	for(int j = 0; j < 3; j++) cout << ' ';
	// cout << s << ' ' << bitset<ax>(dif) << ' ' << dif << ' ' << qntRL << ' ' << bitset<ax>(msk) << ' ' << (bitset<ax>(msk).to_string() != bitset<ax>(dif).to_string() )<< '\n';
	cout << "node = " << node << '\n';
	ll nodeL = node ^ (1LL<<pos);
	ll nodeR = nodeL ^ (1LL<<(pos+1));
	if(target < node)
		return solve(nodeL, target, node, pos-1, s+"L", qntRL, qntR) + msk;
	return solve(nodeR, target,  node, pos-1, s+"R", qntRL, qntR) + msk;
}


// int solve(int node, int target, int parent, int pos, string s, int qntRL, int qntR) {
// 	if(pos < 0) return 0;
// 	const int ax = 6;
// 	// cout << "pos = " << node << ", value = " << values[node] << '\n';
// 	int dif = values[node]-values[parent];
// 	// cout << bitset<ax>(dif) << ' ' << dif << '\n';
// 	if(LEN(s)) {
// 		if(LEN(s) > 1 and s[LEN(s)-2] == 'R' and s[LEN(s)-1] == 'L') {
// 			qntRL += qntR;
// 			qntR = 0;
// 		} else if(s[LEN(s)-1] == 'R')
// 			qntR++;
// 		// cout << __builtin_popcount(dif) << '\n';
// 		if((s[LEN(s)-1] == 'L' and __builtin_popcount(dif) != qntRL+1) or (s[LEN(s)-1] == 'R' and __builtin_popcount(dif) != 1))
// 			cout << "NO!\n";
// 	}
// 	for(int i = 0; i < ax-pos; i++)
// 		for(int j = 0; j < 3; j++) cout << ' ';
// 	cout << s << ' ' << bitset<ax>(dif) << ' ' << dif << ' ' << qntRL << '\n';
// 	int nodeL = node ^ (1<<pos);
// 	int nodeR = nodeL ^ (1<<(pos+1));
// 	if(target == node)
// 		return dif;
// 	if(target < node)
// 		return solve(nodeL, target, node, pos-1, s+"L", qntRL, qntR) + dif;
// 	solve(nodeR, target, node, pos-1, s+"R", qntRL, qntR);
// }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);
	
	memset(dp, -1, sizeof dp);
	for(int n = 128; n <= 256-2; n++)
	{
		// cout << "n = " << n << '\n';
		int ans = 0;
		for(int i = 0; i <= n; i++)
		{
			// cout << "\tm = " << i << '\t' << calc(n, i) << '\t' << bitset<16>(calc(n, i)) <<'\n';
			// cout << i << ": " << calc(n, i) % 2 << endl;
			ans += ((calc(n, i) % 2) == 0);
		}
		// if(ans != 5) continue;
		// for(int i = 0; i <= n; i++)
			// cout << i << ": " << calc(n, i) % 2 << endl;
		cout << "ans(" << n << " | " << bitset<10>(n) << "): " << ans;
		for(int i = 0; i < ans; i++)
			cout << '.';
		cout << '\n';
		values[n] = ans;
	}
	cout << (128+256-2)/2 << '\n';
	cout << solve((128+256-2)/2, 240, (128+256-2)/2, 5, "", 0, 0) << '\n';

	return 0;
}