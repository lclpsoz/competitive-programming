#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int MAXP = sqrt (2147483648LL+100LL);

int n, m;
bool not_p[MAXP];
vector<int> primes;

int main ()
{
	map<int, int> mp;
	not_p[0] = not_p[1] = true;
	for (int i = 2; i*i < MAXP; i++)
		if (!not_p[i])
			for (int j = i*i; j < MAXP; j+=i)
				not_p[j] = true;

	for (int i = 2; i < MAXP; i++)
		if (!not_p[i])
			primes.pb (i);

	while (scanf ("%d %d", &n, &m) != EOF) {
		// printf ("%d %d\n", n, m);
		if (m <= n)
			printf ("%d divides %d!\n", m, n);
		else {
			int x = m;
			for (int p : primes) {
				while (x%p == 0) {
					x/=p;
					mp[p]++;
				}
				if (x == 1) break;
			}
			if (x > 1)
				mp[x]++;

			bool ans = true;
			for (pii p : mp) {
				x = n/p.x;
				int aux = 0;
				while (x) {
					aux += x;
					x /= p.x;
				}
				if (p.y > aux) {
					// printf ("%d %d\n", p.y, n/p.x);
					ans = false;
					break;
				}
			}
			mp.clear();

			if (!ans)
				printf ("%d does not divide %d!\n", m, n);
			else
				printf ("%d divides %d!\n", m, n);

		}
	}

	return 0;
}
