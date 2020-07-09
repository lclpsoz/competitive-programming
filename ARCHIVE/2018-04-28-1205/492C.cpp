#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> pii;

long long n, r, avg;
long long ans;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main ()
{
	long long a, b;
	scanf ("%lld %lld %lld", &n, &r, &avg);
	long long sum = n*avg;
	long long now = 0;
	while (n--) {
		scanf ("%lld %lld", &a, &b);
		pq.push ({b, a});
		now += a;
	}

	long long f, s;
	while (now < sum) {
		f = pq.top().first;
		s = pq.top().second;
		// prlong longf ("%lld %lld|%lld %lld\n", f, s, now, sum);
		pq.pop();
		if (now + (r - s) <= sum) {
			now += r - s;
			ans += (r-s)*f;
		}
		else {
			ans += (sum-now)*f;
			now += r-s;
		}
	}

	printf ("%lld\n", ans);

	return 0;
}
