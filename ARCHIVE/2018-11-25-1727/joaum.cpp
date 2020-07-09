#include <bits/stdc++.h>
using namespace std;

#define len(x) (int)x.size()
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

const int MOD = 1000'000'007;
const double EPS = 0.000'000'001;

inline int fcmp(double x, double y)
{ return (x < y + EPS ? (x < y - EPS ? -1 : 0) : 1);}

const int N = 1e4+10;

vpii trips;
double dp[N][121][6];
int n;

double solve(int i, int t, int p)
{	
  if(i >= n)
    return 0;

  if(t >= 120 || p >= 6)
    return solve(i, 0, 0);

  double &r = dp[i][t][p];
  if(r != 1e9)
    return r;

  if(p > 0) r = min (r, solve(i, 0, 0));
  if(p > 1) r = min (r, 0.25 * trips[i].second + solve(i + 1, t + trips[i].first, p + 1));	
  if(p == 1) r = min (r, 0.5 * trips[i].second + solve(i + 1, t + trips[i].first, p + 1));	
  r = min(r, trips[i].second + solve(i + 1, t + trips[i].first, p + 1));	

  return r;
}

int main()
{
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  ios_base::sync_with_stdio(false);
  cout.precision(2);
	
  cin >> n;

  trips.resize(n);

  for (int i = 0; i < N; i++)
    for (int j = 0; j < 121; j++)
      for (int k = 0; k < 6; k++)
	dp[i][j][k] = 1e9;

  for(pii& t : trips)
    cin >> t.first >> t.second;

  cout << fixed << solve(0, 0, 0) << endl;
	
  //cerr << "Tempo de execucao: " << (double)clock() / CLOCKS_PER_SEC << endl;
  return 0;
}
