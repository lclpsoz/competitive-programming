#include <bits/stdc++.h>
using namespace std;
     
#define len(x) (int)x.size()
#define all(x) x.begin(), x.end()
     
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
     
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
     
ll expll(ll b, ll e)
{
  if(e == 0)
    return 1;
  ll aux = expll(b, e / 2);
     
  if(e % 2)
    return b * aux * aux;
  else
    return aux * aux;
}
     
int main()
{
  ios_base::sync_with_stdio(false);
  cout.precision(10);
     
  int t; cin >> t;
     
  while(t--)
    {
      int d; cin >> d;
      vi vv(d);
     
      for(int& vvv : vv)
	cin >> vvv;
     
      sort(all(vv));
     
      ll n; cin >> n;
     
      string ans;
      int m = 0;
      ll a = expll(d, m);
     
      while(a <= n)
	{
	  //cout << "a: " << a << endl;
     
	  int dd = (int)(((n - a) / expll(d, m)) ) % d;
     
	  //cout << "dd: " << dd << endl;
     
	  if(dd >= 0) ans.push_back(char('0' + vv[dd]));
	  else break;
     
	  a += expll(d, ++m);
	}
     
      reverse(all(ans));
     
      cout << ans << endl;
    }
     
  //cerr << "Tempo de execucao: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
  return 0;
}
