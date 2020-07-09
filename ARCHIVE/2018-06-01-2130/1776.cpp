#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int MAXP = sqrt (1e9+100);

int t, x;
ll ans;
bool not_prime[MAXP];
vector<int> primes;

int main ()
{
	not_prime[0] = not_prime[1] = true;
	for (int i = 2; i*i < MAXP; i++)
		if (!not_prime[i])
			for (int j = i*i; j < MAXP; j+=i)
				not_prime[j] = true;

	for (int i = 2; i < MAXP; i++)
		if (!not_prime[i])
			primes.pb (i);

	scanf ("%d", &t);
	bool take;
	int en = primes.size()-1;
	for (int i = 1; i <= t; i++) {
		scanf ("%d", &x);
		int aux = x;
		ans = 1;
		for (int j = en; x > 1 && j >= 0; j--) {
			take = false;
			while (x % primes[j] == 0) {
				take = !take;
				x /= primes[j];
			}
			if (take) {
				ans *= primes[j];
				// printf ("%d %d\n", primes[j], take);
			}
		}
		// printf ("%lld\n", ans);
		if (x > 1) ans *= x;
		ans *= aux;
		printf ("Caso #%d: %lld\n", i, ans);
	}

	return 0;
}
