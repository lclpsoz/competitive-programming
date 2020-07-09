#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;
#define FOR(i, x, y) for (int i = (x); i < (y); i++)

int k;
int arr[15];

int main ()
{
	bool ts = false;
	while (scanf ("%d", &k), k) {
		if (ts) putchar ('\n');
		ts = true;
		FOR(i, 0, k)
			scanf ("%d", &arr[i]);
		FOR(i, 0, k-5)
			FOR(j, i+1, k-4) {
				FOR(o, j+1, k-3) {
					FOR(l, o+1, k-2) {
						FOR(m, l+1, k-1)
							FOR(n, m+1, k) {
								printf ("%d %d %d %d %d %d\n", arr[i],
										arr[j],
										arr[o],
										arr[l],
										arr[m],
										arr[n]);
							}
					}
				}
			}
	}

	return 0;
}
