#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int t, f;
int work;
priority_queue<pair<double, pii>> pq;

int main ()
{
	unsigned long long ans = 0, fines;
	if (scanf ("%d %d", &t, &f) != EOF)
		work = t;
	if (scanf ("%d %d", &t, &f) != EOF) {
		work--;
		pq.push ({(double) f/t, {t, f}});
		fines = f;
	}
	while (!pq.empty()) {
		if (work == 0) {
			pii p = pq.top().y;
			pq.pop ();
			work = p.x;
			fines -= p.y;
		}
		ans += fines;
		if (scanf ("%d %d", &t, &f) != EOF) {
			pq.push ({(double) f/t, {t, f}});
			fines += f;
			work--;
		} else {
			work--;
			ans += fines * work;
			work = 0;
		}
	}

	printf ("%llu\n", ans);

	return 0;
}
