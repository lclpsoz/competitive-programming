#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl

#define F first
#define S second
#define PB push_back
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forr(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define for1n(i, n) for(int i = 1; i <= int(n); i++)
#define for1r(i, n) for(int i = int(n); i >= 1; i--)
#define ms(x, v) memset((x), (v), sizeof(x))
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (( (a)/__gcd((a), (b)) )*(b))

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int a, b, c, d;
	
	cin >> a >> b >> c >> d;
	
	if(a==d){
		if(a > 0)
			cout << 1 << endl;
		else if(c == 0)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}else{
		cout << 0 << endl;	
	}
	
	return 0;
}
